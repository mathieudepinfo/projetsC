#include <stdio.h>
#include <stdlib.h>

void affiche(long n);
int somme(int a,int b);
int factorielle(int n);
int syracuse(int n,int p);

int main(int argc, char* argv[])
{
    printf("hello world \n");
    if(atoi(argv[1])){
        affiche(atoi(argv[1]));
    }
    if(atoi(argv[2])){
        printf("%d \n",factorielle(atoi(argv[2])));
    }
    if(atoi(argv[3])){
        syracuse(atoi(argv[3]),atoi(argv[4]));
    }
}

void affiche(long n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d \n",i);
    }
}

int somme(int a,int b)
{
    return a+b;
}

int factorielle(int n)
{
    if(n==0){
        return 1;
    }
    else{
        return n*factorielle(n-1);
    }
}

int syracuse(int n,int p)
{
    printf("%d \n",n);

    if(p==0){
        return 0;
    }
    if(n%2==0)
    {
        return syracuse(n/2,p-1);
    }
    else
    {
        return syracuse(3*n+1,p-1);
    }

}
