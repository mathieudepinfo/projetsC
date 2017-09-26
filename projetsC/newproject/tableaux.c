#include <stdio.h>
#include <stdlib.h>

int somme(int tableau[],int tailleTableau){

    int resultat=0;

    for(int i=0;i<tailleTableau;i++){

        resultat+=tableau[i];
    }

    return resultat;
}

double moyenne(int tableau[], int tailleTableau){

    double moy=0;

    moy=somme(tableau,tailleTableau);
    moy=moy/tailleTableau;
    return moy;
}

void affiche(int tableau[],int tailleTableau){

    for(int i=0;i<tailleTableau;i++){

        printf("%d ",tableau[i]);
    }
}

void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{

    for(int i=0;i<tailleTableau;i++){

        *(tableauCopie+i)=*(tableauOriginal+i);


    }


}

void tri(int *pivot,int *debut, int *fin){
    int temp=0;
    int *x=debut;
    int *y=fin;
    while(y!=pivot && x!=pivot){

        while(*x<*pivot && x<pivot){
            x+=1;

        }

        while(*y>*pivot && y>pivot){

            y-=1;
        }

        if (*x>*pivot && *y<*pivot){
            temp= *x;
            *x=*y;
            *y=temp;
        }
        else if(*x>*pivot){
            temp=*x;
            *x=*pivot;
            *pivot=temp;
        }
        else if(*y<*pivot){

            temp=*y;
            *y=*pivot;
            *pivot=temp;




        }

    }

}
void ordonnerTableau(int *pivot,int *debut, int *fin){

    if (fin-debut==0){
        return;
    }

    else{
        tri(pivot,debut,fin);
        ordonnerTableau(debut ,debut, pivot);
        ordonnerTableau(fin,  pivot,fin);
    }










}

