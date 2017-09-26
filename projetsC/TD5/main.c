#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
#define CHAINE "comment ca va?" //attention certains caractères sont encodés bizaremment
#define CHAINE_2 "ou sont les eee!"
#define CHAINE_A_COPIER "chaine a copier"


int main()
{   //ex 1
    char* s=CHAINE;
    printf("%d \n",len(s));
    //ex2
    char s2[]=CHAINE_A_COPIER;
    char* p=malloc(len(s2)*sizeof(char));
    scopy(p,s2);
    printf("%s, %s \n",s2,p);

    char* s3=CHAINE_2;
    printf("%d \n",nbe('e',s3));
    //ex3
    char* s4=malloc(len(s3)*sizeof(char));
    scopy(s4,s3);
    *s4='P';
    printf("%s -> %s \n",s3,s4);

    //ex4
    int n1[8]={1,2,3,4,5,6,7,8};
    affiche(8,n1);
    int n2[8]={2,3,4,5,6,7,8,6};
    affiche(8,n2);
    int* res=calloc(9,sizeof(int));
    addition(res,n1,8,n2,8);
    affiche(9,res);
    return 0;



}
