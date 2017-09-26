#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <wait.h>

void exercice1_1();
void exercice1_2_chaine(int n);
void exercice1_2_arbre(int n);

int main()
{

    exercice1_2_arbre(10);





    return 0;





}

void exercice1_1()
{
    for(int i=0;i<10;i++)
    {
        if(fork()==0)
        {
            for(int j=0;j<10;j++)
            {
                printf("%d ",i);
                printf("%d ",i);
            }

            exit(0);
        }
    }
}

void exercice1_2_chaine(int n)
{

    printf("Je suis le père, pid = %d \n",getpid());
    //le buffer est copié, "\n" flush le buffer
    for(int i=0;i<n;i++)
    {
        if(fork()==0)
        {
            printf("Je suis le %d ème fils, pid= %d, ppid=%d \n",i,getpid(),getppid());
            exit(0);
        }
        waitpid(-1,NULL,0);
    }

}

void exercice1_2_arbre(int n)
{

    printf("Je suis le père, pid= %d, ppid=%d \n",getpid(),getppid());
    //le buffer est copié, "\n" flush le buffer
    for(int i=0;i<n;i++)
    {
        if(fork()==0)
        {
            printf("Je suis le %d ème fils, pid= %d, ppid=%d \n",i,getpid(),getppid());

        }
        else
        {
            sleep(100);
            exit(0);
        }
    }


}











































