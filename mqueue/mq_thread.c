#include <unistd.h>
#include <stdio.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

mqd_t mqid = 0;
struct mq_attr attr;
struct sigevent sigev;

static void notify_thread(union sigval);

int main(int argc, char* argv[])
{

    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mqid = mq_open("/mq_test",O_RDONLY | O_NONBLOCK,mode,NULL);
    mq_getattr(mqid,&attr);

    sigev.sigev_notify = SIGEV_THREAD;
    sigev.sigev_notify_function = notify_thread;
    sigev.sigev_value.sival_ptr = NULL;
    sigev.sigev_notify_attributes = NULL;
    int n = mq_notify(mqid,&sigev);

    for (;;)
        pause();
    return 0;
}

static void notify_thread(union sigval arg)
{
    ssize_t n;
    char* buff;
    printf("notify_thread_started!\n");
    buff = malloc(attr.mq_msgsize);
    mq_notify(mqid, &sigev);
    while( (n = mq_receive(mqid,buff,attr.mq_msgsize,NULL)) >=0)
        printf("SIGUSR1 received, read %ld bytes.\n",(long)n);
    if(errno != EAGAIN)
        printf("mq_receive error\n");
    free(buff);
    pthread_exit(0);
}
