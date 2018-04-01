#include <unistd.h>
#include <stdio.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

#define __USE_POSIX
#include <signal.h>


void sig_usr1(int );
volatile sig_atomic_t mqflag;

int main(int argc, char* argv[])
{
    mqd_t mqid = 0;
    void *buff;
    struct mq_attr attr;
    struct sigevent sigev;
    sigset_t zeromask,newmask,oldmask;

    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mqid = mq_open("/mq_test",O_RDONLY | O_NONBLOCK,mode,NULL);
    mq_getattr(mqid,&attr);
    buff = malloc(attr.mq_msgsize);

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigemptyset(&oldmask);
    sigaddset(&newmask,SIGUSR1);

    signal(SIGUSR1,sig_usr1);
    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;
    int n = mq_notify(mqid,&sigev);

    for (;;)
    {
        sigprocmask(SIG_BLOCK,&newmask,&oldmask);
        while(mqflag == 0)
            sigsuspend(&zeromask);

        mqflag = 0;
        ssize_t n;
        mq_notify(mqid, &sigev);
        while( (n = mq_receive(mqid,buff,attr.mq_msgsize,NULL)) >=0)
            printf("SIGUSR1 received, read %ld bytes.\n",(long)n);
        if(errno != EAGAIN)
            printf("mq_receive error\n");
        sigprocmask(SIG_UNBLOCK,&newmask,NULL);
    }  
    return 0;
}

void sig_usr1(int signo)
{
    mqflag = 1;
}
