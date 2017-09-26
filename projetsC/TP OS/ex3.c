#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

void handler(int sig){

    static int a;
    if(a>=5){
        kill(getpid(),6);
        exit(0);
    }
    else{
        a++;

    }
}

int main()
{
    struct sigaction nvt,old;
    memset(&nvt, 0, sizeof(nvt));
    nvt.sa_handler=&handler;
    sigaction(SIGINT,&nvt,&old);
    while(1);
}

