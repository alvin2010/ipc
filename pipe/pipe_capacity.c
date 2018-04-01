#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "sys/wait.h"
#include "sys/types.h"

int main(int argc, char* argv[])
{
    int fd[2];
    int status = 0;
    int ret = pipe(fd);
    if (ret == -1)
    {
        perror("pipe error\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0)   // child
    {
        close(fd[0]);
        int i = 1;
        while (i)
        {
            write(fd[1],"A",1);
            printf("pipe capacity: %d\n",i++);
        }
        close(fd[1]);

    }
    else if(pid > 0)
    {
        close(fd[1]);
        waitpid(pid,NULL,0);
        close(fd[0]);
    }
    else
    {
        perror("fork error\n");
        return 1;
    }
    return 0;
}