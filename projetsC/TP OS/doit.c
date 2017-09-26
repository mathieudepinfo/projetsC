#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

int main(int argc,char* argv[])
{
    int status;

    for(int i=0;i<5;i++)
    {


        if(fork()==0)
        {
            execvp(argv[1],argv+1);
            exit(0);
        }
        else{
            waitpid(-1,&status,0);
        }
        if(WIFEXITED(status))
        {
            if(!WEXITSTATUS(status))
            {

                printf("Ca c'est bien passé \n");

            }
            else
            {
                printf("Ca a fini sur un exit mais ça c'est mal passé \n");
                exit(-1);
            }
        }
        else
        {
            printf("Me suis fait refouler par un signal \n");
            exit(-1);
        }
    }

}
