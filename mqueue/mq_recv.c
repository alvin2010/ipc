#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int flag = O_RDWR;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mqd_t mqid = mq_open("/mq_test",flag,mode,NULL);
    if (mqid == -1)
    {
        printf("open mqueue failed!\n");
        return 1;
    }

    struct mq_attr attr;
    mq_getattr(mqid,&attr);
    char buf[256] = {0};
    int priority = 0;
    mq_receive(mqid,buf,attr.mq_msgsize,&priority);
    printf("%s\n",buf);
    mq_close(mqid);    
    return 0;
}