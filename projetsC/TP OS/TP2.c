#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ecrire(int n);

int main(int argc,char* argv[])
{
    /*int fd[2]; //petit programme exemple
    pipe(fd);
    char* s="Bonjour moi!";
    write(fd[1],s,13);
    close(fd[1]);
    char* v=malloc(sizeof(char)*13);
    read(fd[0],v,13);
    close(fd[0]);
    printf("%s \n",v);*/

    /*while(1)
    {
        ecrire(n);
        printf("%d \n",n);
        n=n+1000;
    }*/
    int a=ecrire(atoi(argv[1]));
    printf("%d \n",a);
    return a;
}

int ecrire(int n)
{

    int fd[2];
    pipe(fd);

    char* s[n];

    int res=write(fd[1],s,n);

    close(fd[1]);
    close(fd[0]);


    return res;
}
