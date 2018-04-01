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

    char *buf = "hello, i am sender!";
    mq_send(mqid,buf,strlen(buf),20);
    mq_close(mqid);
    
    return 0;
}