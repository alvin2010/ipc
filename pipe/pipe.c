#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "sys/wait.h"
#include "sys/types.h"

int main(int argc, char* argv[])
{
    int fd[2];
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
        int i = 0;
        char* msg = "i am child\n";
        while (i < 5)
        {
            write(fd[1],msg,strlen(msg));
            sleep(2);
            i++;
        }

    }
    else if(pid > 0)
    {
        close(fd[1]);
        char buf[256] = {0};
        int j = 0;
        while (j < 5)
        {
            int n = read(fd[0],buf,256);
            if (n>0)  
            {  
                buf[n] = '\0';  
            }  
            printf("%s",buf);
            j++;  
        }
    }
    else
    {
        perror("fork error\n");
        return 1;
    }
    return 0;
}