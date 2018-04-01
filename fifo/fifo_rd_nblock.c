#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int ret = mkfifo("my_fifo",0777);
    if (ret == -1)
    {
        printf("make fifo failed!\n");
        return 1;
    }

    char *buf="memeda!";
    int fd = open("my_fifo",O_RDONLY | O_NONBLOCK);
    int n = write(fd,buf,strlen(buf));
    close(fd);
    unlink("my_fifo");
    return 0;
}