#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc,char* argv[])
{
    printf("%s \n",argv[1]);
    char s[]="coucou";
    int fd[2];
    int status;
    pipe(fd);

    if(fork())
    {

        char s[]="coucou";
        write(fd[1],s,sizeof(s));
        close(fd[0]);close(fd[1]);
        waitpid(-1,&status,0);
        exit(0);
    }
    else
    {
        dup2(fd[0],0);
        close(fd[0]);close(fd[1]);

        execvp("mail",argv[1]);
        exit(0);
    }
}
