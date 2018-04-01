#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
    int flag = O_RDWR | O_CREAT | O_EXCL;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = 0;
    fd = shm_open("/shm_test", flag, mode);
    if (-1 == fd)
    {
        printf("open shm failed!\n");
        return 1;
    }
    ftruncate(fd, 1024);

    mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    return 0;
}