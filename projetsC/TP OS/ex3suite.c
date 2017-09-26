#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

pid_t pid1;

void handler1(int sig){

    kill(pid1,SIGUSR2);
    exit(0);
}
void handler2(int sig){
    exit(0);
}
int main()
{
    pid_t pid2;//fils cadet
    pid1=fork();//fils ainé
    int status1,status2;

    if(pid1){
        pid2=fork();

        if(pid2){//on est dans le pere mammene
            waitpid(pid2,&status2,0);//mort du cadet
            waitpid(pid1,&status1,0);//mort du fils
            exit(0);
        }
        else{//on est dans le cadet
            struct sigaction nvt,old;
            memset(&nvt, 0, sizeof(nvt));
            nvt.sa_handler=&handler1;
            sigaction(SIGUSR1,&nvt,&old);
            while(1){sleep(0.5);}
        }

    }
    else{//on est dans l'ainé

        struct sigaction nvt,old;
        memset(&nvt, 0, sizeof(nvt));
        nvt.sa_handler=&handler2;
        sigaction(SIGUSR2,&nvt,&old);
        while(1){sleep(0.5);};
    }

}
