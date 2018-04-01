#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h> 
#include <string.h>

int main(int argc, char* argv[])
{
    int fd1,fd2;
    unsigned char *ptr1, *ptr2;
    pid_t pid;
    int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    fd1 = shm_open("/shm_test",O_RDWR,mode);
    if (fd1 == -1)
    {
        printf("Message : %s\n", strerror(errno)); 
        return 1;
    }

    struct stat stat;
    fstat(fd1, &stat);

    fd2 = open("/dev/shm/shm_test1",O_RDWR | O_CREAT,mode);
    if (fd2 == -1)
    {
        printf("Message : %s\n", strerror(errno)); 
        return 1;
    }
    
    pid = fork();
    if (pid == 0)
    {
        ptr2 = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd2,0);
        ptr1 = mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd1, 0);
        printf("child: shm prt=%p, mmf ptr=%p\n",ptr1, ptr2);
        sleep(5);
        printf("share memory integer:%d", *ptr1);
    }
    else if (pid > 0)
    {
        ptr1 = mmap(NULL, 1024, PROT_READ|PROT_WRITE, MAP_SHARED, fd1, 0);
        ptr2 = mmap(NULL, 4, PROT_READ|PROT_WRITE, MAP_SHARED, fd2,0);
        printf("parent: shm prt=%p, mmf ptr=%p\n",ptr1, ptr2);
        *ptr1 = 128;
        waitpid(0, NULL, 0);
    }
    else{
        
    }

    return 0;
}