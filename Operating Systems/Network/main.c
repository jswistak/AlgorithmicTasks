#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>

#define ERR(source) (perror(source),                                 \
                     fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), \
                     exit(EXIT_FAILURE))

#define TEMP_FAILURE_RETRY(exp)             \
  ({                                        \
    typeof((exp)) _trc;                     \
    do {                                    \
      _trc = (exp);                         \
    } while (_trc == -1 && errno == EINTR); \
    _trc;                                   \
  })


#define MAX_CLIENTS 3
#define MAX_BUF 256
#define MAX_CONNECTIONS 3
#define BACKLOG 3 // max pending connections

ssize_t bulk_write(int fd, char *buf, size_t count)
{
    int c;
    size_t len = 0;
    do
    {
        c = TEMP_FAILURE_RETRY(write(fd, buf, count));
        if (c < 0)
            return c;
        buf += c;
        len += c;
        count -= c;
    } while (count > 0);
    return len;
}

volatile sig_atomic_t do_work = 1;
void sigint_handler(int sig)
{
    do_work = 0;
}
int sethandler(void (*f)(int), int sigNo)
{
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));
    act.sa_handler = f;
    if (-1 == sigaction(sigNo, &act, NULL))
        return -1;
    return 0;
}

// Creates socket on domain of type
int make_socket(int domain, int type)
{
    int sock;
    sock = socket(domain, type, 0);
    if (sock < 0)
        ERR("socket");
    return sock;
}
// Create address from address and port
struct sockaddr_in make_address(const char *address, const char *port)
{
    int ret;
    struct sockaddr_in addr;
    struct addrinfo *result;
    struct addrinfo hints = {};
    hints.ai_family = AF_INET;
    if ((ret = getaddrinfo(address, port, &hints, &result)))
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(EXIT_FAILURE);
    }
    addr = *(struct sockaddr_in *)(result->ai_addr);
    freeaddrinfo(result);
    return addr;
}
// Create TCP socket & bind socket to address and listen of BACKLOG number
int bind_tcp_socket_to_address(struct sockaddr_in addr)
{
    int socketfd, t = 1;
    socketfd = make_socket(PF_INET, SOCK_STREAM);
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &t, sizeof(t)))
        ERR("setsockopt");
    if (bind(socketfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        ERR("bind");
    if (listen(socketfd, BACKLOG) < 0)
        ERR("listen");
    return socketfd;
}

// Creates socket and connects to an address
int connect_tcp_socket_to_address(struct sockaddr_in addr)
{
    int socketfd;
    socketfd = make_socket(PF_INET, SOCK_STREAM);
    if (connect(socketfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) < 0)
    {
        if (errno != EINTR)
            ERR("connect");
        else
        {
            fd_set wfds;
            int status;
            socklen_t size = sizeof(int);
            FD_ZERO(&wfds);
            FD_SET(socketfd, &wfds);
            if (TEMP_FAILURE_RETRY(select(socketfd + 1, NULL, &wfds, NULL, NULL)) < 0)
                ERR("select");
            if (getsockopt(socketfd, SOL_SOCKET, SO_ERROR, &status, &size) < 0)
                ERR("getsockopt");
            if (0 != status)
                ERR("connect");
        }
    }
    return socketfd;
}
int connect_tcp_socket(char *name, char *port)
{
    return connect_tcp_socket_to_address(make_address(name, port));
}
// Accepts connection
int add_new_client(int sfd)
{
    int nfd;
    if ((nfd = TEMP_FAILURE_RETRY(accept(sfd, NULL, NULL))) < 0)
    {
        if (EAGAIN == errno || EWOULDBLOCK == errno)
            return -1;
        ERR("accept");
    }
    return nfd;
}
// Set nonblock for FD
int set_nonblock(int desc)
{
    int oldflags = fcntl(desc, F_GETFL, 0);
    if (oldflags == -1)
        return -1;
    return fcntl(desc, F_SETFL, oldflags | O_NONBLOCK);
}

void sigint_sigblock(sigset_t *mask, sigset_t *oldmask)
{
    sigemptyset(mask);
    sigaddset(mask, SIGINT);
    sigprocmask(SIG_BLOCK, mask, oldmask);
}

void clean_desc(int *fdC, int *cfds)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        int fd = fdC[i];
        if (fd >= 0)
        {
            close(fdC[i]);
        }
    }
    for (int i = 0; i < MAX_CONNECTIONS; i++)
    {
        if (cfds[i] < 0)
            continue;
        close(cfds[i]);
    }
}

void server(int server_sock, int *command_conn)
{
    int cfds[MAX_CONNECTIONS];
    for (int i = 0; i < MAX_CONNECTIONS; i++)
        cfds[i] = -1;
    fd_set rfds;
    sigset_t mask, oldmask;
    sigint_sigblock(&mask, &oldmask);
    while (do_work)
    {
        int fdmax = server_sock;
        FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);
        FD_SET(server_sock, &rfds);
        for (int i = 0; i < MAX_CONNECTIONS; i++)
        {
            if (cfds[i] >= 0)
            {
                FD_SET(cfds[i], &rfds);
                fdmax = (cfds[i] > fdmax ? cfds[i] : fdmax);
            }
        }
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            int fd = command_conn[i];
            if (fd >= 0)
            {
                FD_SET(fd, &rfds);
                fdmax = (fd > fdmax ? fd : fdmax);
            }
        }
        struct timespec tim = {52, 0};
        int executed = 0;
        if (pselect(fdmax + 1, &rfds, NULL, NULL, &tim, &oldmask) < 0)
        {
            if (EINTR == errno)
                continue;
            ERR("pselect");
        }
        for (int i = 0; i < MAX_CONNECTIONS; i++)
        {
            if (cfds[i] < 0)
                continue;
            if (FD_ISSET(cfds[i], &rfds))
            {
                executed = 1;
                printf("Client sends:\n"); /* Got some data on connected client */
                ssize_t size;
                char buf[MAX_BUF];
                int cfd = cfds[i];
                do
                {
                    size = recv(cfd, buf, MAX_BUF, 0);
                    bulk_write(STDOUT_FILENO, buf, size);
                } while (size == MAX_BUF);
                if (size == 0)
                {
                    close(cfd);
                    cfds[i] = -1;
                }
            }
        }
        if (FD_ISSET(server_sock, &rfds))
        {
            executed = 1; /*New Connection*/
            printf("Added new client\n");
            int cfd = add_new_client(server_sock);
            set_nonblock(cfd);
            if (cfd >= 0)
            {
                for (int i = 0; i < MAX_CONNECTIONS; i++)
                {
                    if (cfds[i] < 0)
                    {
                        cfds[i] = cfd;
                        break;
                    }
                    else if (i == MAX_CONNECTIONS - 1)
                    {
                        close(cfds[0]);
                        cfds[0] = cfd;
                    }
                }
            }
        }
        if (FD_ISSET(STDIN_FILENO, &rfds))
        {
            executed = 1;
            ssize_t size;
            char buf[MAX_BUF];
            read(STDIN_FILENO, buf, 255);
            buf[255] = 0;
            size = strlen(buf); /*Sends msg to all clients*/
            for (int i = 0; i < MAX_CLIENTS; i++)
            {
                if (command_conn[i] < 0)
                    continue;
                if (bulk_write(command_conn[i], buf, size) < 0 && errno != EAGAIN)
                {
                    close(command_conn[i]);
                    command_conn[i] = -1;
                }
            }
        }
        if (!executed)
        {
            break;
        }
    }
    clean_desc(command_conn, cfds);
    sigprocmask(SIG_UNBLOCK, &mask, NULL);
}

void usage(const char *name)
{
    fprintf(stderr, "USAGE: %s socket port {optionals x 2}\n", name);
    exit(EXIT_FAILURE);
}

int main(int argc, const char *argv[])
{
    sethandler(SIG_IGN, SIGPIPE);
    sethandler(sigint_handler, SIGINT);
    // server file descriptor
    int fdC[MAX_CLIENTS];
    if (argc < 3 || argc > 9)
    {
        usage(argv[0]);
    }
    int fdL = bind_tcp_socket_to_address(make_address(argv[1], argv[2]));
    // Connect to given clients
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        fdC[i] = -1;
        if (argc > 4 + 2 * i)
        {
            fdC[i] = connect_tcp_socket_to_address(make_address(argv[3 + 2 * i], argv[4 + 2 * i]));
        }
    }
    server(fdL, fdC);
    return EXIT_SUCCESS;
}
