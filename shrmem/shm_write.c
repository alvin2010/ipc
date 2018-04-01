#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char* argv[])
{
    int flag = O_RDWR;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = 0;
    unsigned char* ptr, c;
    fd = shm_open("/shm_test", flag, mode);
    if (-1 == fd)
    {
        printf("open shm failed!\n");
        return 1;
    }
    struct stat stat; 
    fstat(fd,&stat);
    ptr = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    for (int i = 0; i < stat.st_size; i++)
    {
        *ptr++ = i % 256;
        printf("write %d\n",i);
    }
    return 0;
}