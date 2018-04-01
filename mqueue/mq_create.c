#include <mqueue.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int flag = O_RDWR | O_CREAT | O_EXCL;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    mqd_t mqid = mq_open("/mq_test", flag, mode,NULL);
    if (mqid == -1)
    {
        printf("mqueue create failed!\n");
        return 1;
    }
    else
    {
        printf("mqueue create success!\n");
    }    
    int n = mq_close(mqid);    
    return 0;
}

