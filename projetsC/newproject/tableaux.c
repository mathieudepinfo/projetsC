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
