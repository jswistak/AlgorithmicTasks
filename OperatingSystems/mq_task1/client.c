#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#define ERR(source) (fprintf(stderr,"%s:%d\n",__FILE__,__LINE__),\
perror(source),kill(0,SIGKILL),\
exit(EXIT_FAILURE))


#define MAX_RESERVATIONS 10
#define MAX_PID 10

volatile sig_atomic_t shouldQuit = 0;


void sethandler( void (*f)(int, siginfo_t*, void*), int sigNo) {
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));
    act.sa_sigaction = f;
    act.sa_flags=SA_SIGINFO;
    if (-1==sigaction(sigNo, &act, NULL)) ERR("sigaction");
}


void sigquit_handler(int sig, siginfo_t *s, void *p) {
    shouldQuit = 1;
}
void sigint_handler(int sig, siginfo_t *s, void *p) {
    shouldQuit = 1;
}



void client_work(mqd_t mq, mqd_t del) {
    int32_t msg = getpid(); 
    printf("Sending mess %d\n", msg);
    if(mq_send(mq, (const char*)&msg, sizeof(int32_t), 0) == -1){
        if (errno != EINTR)
            ERR("mq_send");
    }
    if(mq_receive(del, (char*)&msg, sizeof(int32_t), 0) == -1){
        if (errno != EINTR) 
            ERR("mq_receive");
    }
    printf("My number is %d\n", msg);

    if(msg <= 3){
        printf("Q%d 2022", msg);
        //wait for delivery
        if(mq_receive(del, (char*)&msg, sizeof(int32_t), 0) == -1){
            if (errno != EINTR) 
            ERR("mq_receive");
        }
        printf("Reservation fulfilled\n");
    }
    else{
        printf("After Q3 2022\n");
    }
    
}

int main(int argc, char** argv) {
    mqd_t reservations;
    mqd_t delivery;
    char deliveryQueueName[sizeof("/DELIVERY_") + MAX_PID]; 
    snprintf(deliveryQueueName, sizeof("/DELIVERY_")+MAX_PID, "/DELIVERY_%d", getpid());

    struct mq_attr attr;
    attr.mq_maxmsg=MAX_RESERVATIONS;
    attr.mq_msgsize=sizeof(pid_t);
    if((reservations = TEMP_FAILURE_RETRY(mq_open("/RESERVATIONS",  O_RDWR, 0600, &attr))) == (mqd_t)-1) ERR("mq_open");
    if((delivery = TEMP_FAILURE_RETRY(mq_open(deliveryQueueName,  O_RDWR | O_CREAT, 0600, &attr))) == (mqd_t)-1) ERR("mq_open");
    
    sethandler(sigquit_handler,SIGQUIT);
    sethandler(sigint_handler,SIGINT);

    client_work(reservations, delivery);
    
    mq_close(reservations);
    mq_close(delivery);
    if (mq_unlink(deliveryQueueName))
        ERR("mq unlink");
    
    return EXIT_SUCCESS;
}