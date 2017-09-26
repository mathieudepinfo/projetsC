#include "ex1.h"
#include <stdlib.h>
#include <stdio.h>

int len(char* chaine)
{
    int compteur=0;
    while(*(chaine+compteur)!=0)
    {
        compteur++;
    }

    return compteur;
}

void scopy(char*p,char chaine[])
{
    int l=len(chaine);
    for(int i=0;i<l;i++)
    {
        *(p+i)=chaine[i];
    }

}
int nbe(char lettre,char* s)
{
    int compteur=0;
    int i=0;
    while(*(s+i)!=0)
    {
        if(*(s+i)==lettre)
        {
            compteur++;
        }
        i++;
    }

    return compteur;

}
int mini(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void addition(int* res,int* a,int sizea,int* b,int sizeb)
{
    int* plusgrand=0;
    int maxsize;
    if(sizea<sizeb)
    {
        plusgrand=b;
        maxsize=sizeb;
    }
    else if(sizeb<sizea)
    {
        plusgrand=a;
        maxsize=sizea;
    }
    int retenue=0;
    for(int i=0;i<mini(sizea,sizeb);i++)
    {

        *(res+i)=(*(a+i)+*(b+i)+retenue)%10;
        retenue=(*(a+i)+*(b+i)+retenue)/10;


    }

    if(plusgrand==b)
    {
        for(int j=sizea;j<sizeb;j++)
        {
            *(res+j)=*(b+j)+retenue;
            retenue=0;
        }
    }
    else if(plusgrand==a)
    {
        for(int j=sizeb;j<sizea;j++)
        {
            *(res+j)=*(a+j)+retenue;
            retenue=0;
        }

    }
    if(retenue!=0)
    {
        *(res+maxsize)=1;
    }

}

void affiche(int sizea,int* a)
{

    for(int i=sizea-1;i>=0;i--)
    {
        printf("%d",*(a+i));
    }
    printf("\n");
}

