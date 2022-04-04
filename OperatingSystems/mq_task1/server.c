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
volatile sig_atomic_t shouldFulfill = 0;

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
    shouldFulfill++;
}



void server_work(mqd_t mq) {
    int resnum = 1;
    printf("Server work\n");
    int32_t msg = 0;
    mqd_t m[4];
    int filledAlready = 0;
    while(!shouldQuit){
        while(shouldFulfill > filledAlready && filledAlready < 3 && filledAlready < resnum - 1){
            
            if(TEMP_FAILURE_RETRY(mq_send(m[filledAlready], (const char*)&resnum, sizeof(int32_t), 0)) == -1){
            if (errno != EINTR)
                ERR("mq_send");
            }
            
            mq_close(m[filledAlready]);
            filledAlready ++;
        }
        printf("Waiting for mess no %d\n", resnum);
        if(mq_receive(mq, (char*)&msg, sizeof(int32_t), 0) == -1){
            if (errno == EINTR) continue;
            ERR("mq_receive");
        }
        //printf("Server rec: %d\n", msg);
        mqd_t client;
        char deliveryQueueName[sizeof("/DELIVERY_") + MAX_PID]; 
        snprintf(deliveryQueueName, sizeof("/DELIVERY_")+MAX_PID, "/DELIVERY_%d", msg);
        if((client = TEMP_FAILURE_RETRY(mq_open(deliveryQueueName,  O_RDWR))) == (mqd_t)-1) ERR("mq_open");
        if(TEMP_FAILURE_RETRY(mq_send(client, (const char*)&resnum, sizeof(int32_t), 0)) == -1){
            if (errno != EINTR)
                ERR("mq_send");
        }
        if(resnum <= 3){
            m[resnum - 1] = client;
        }
        else if(resnum > 3){
            mq_close(client);
        }
        resnum++;
        printf("Resnum after %d\n", resnum);
        
    }


    int smaller = shouldFulfill;
    if(smaller > resnum - 1) smaller = resnum - 1;
    for( ; filledAlready < smaller; filledAlready++){
        if(mq_send(m[filledAlready], (const char*)&resnum, sizeof(int32_t), 0) == -1){
            if (errno != EINTR)
                ERR("mq_send");
        }
        mq_close(m[filledAlready]);
        filledAlready++;
    }


}

int main(int argc, char** argv) {
    mqd_t reservations;
    struct mq_attr attr;
    attr.mq_maxmsg=MAX_RESERVATIONS;
    attr.mq_msgsize=sizeof(pid_t);
    if((reservations = TEMP_FAILURE_RETRY(mq_open("/RESERVATIONS",  O_RDWR | O_CREAT, 0600, &attr))) == (mqd_t)-1) ERR("mq_open");
    
    
    sethandler(sigquit_handler,SIGQUIT);
    sethandler(sigint_handler,SIGINT);

    server_work(reservations);
    
    mq_close(reservations);
    if (mq_unlink("/RESERVATIONS"))
        ERR("mq unlink");
    
    return EXIT_SUCCESS;
}