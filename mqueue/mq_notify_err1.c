#include <unistd.h>
#include <stdio.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

mqd_t mqid = 0;
void *buff;
struct mq_attr attr;
struct sigevent sigev;
void sig_usr1(int );

int main(int argc, char* argv[])
{
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mqid = mq_open("/mq_test",O_RDONLY,mode,NULL);
    mq_getattr(mqid,&attr);
    buff = malloc(attr.mq_msgsize);

    signal(SIGUSR1,sig_usr1);
    sigev.sigev_notify = SIGEV_SIGNAL;
    sigev.sigev_signo = SIGUSR1;
    int n = mq_notify(mqid,&sigev);

    for (;;)
        pause();    
    return 0;
}

void sig_usr1(int signo)
{
    ssize_t n;
    mq_notify(mqid, &sigev);
    n = mq_receive(mqid,buff,attr.mq_msgsize,NULL);
    printf("SIGUSR1 received, read %ld bytes.\n",(long)n);
}
