#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tableaux.h"

void plusoumoins(int nombre_secret);

int main()
{
    /*int nombreDeVies;
    nombreDeVies=5;
    printf("il reste %d vie \n",nombreDeVies);

    int age;
    printf("votre age?");
    scanf("%d",&age);
    printf("%d",age);

    switch (age)
{
case 2:
  printf("salut bebe !");
  break;
case 6:
  printf("salut gamin !");
  break;
case 12:
  printf("salut jeune !");
  break;
case 16:
  printf("salut ado !");
  break;
case 18:
  printf("salut adulte !");
  break;
case 68:
  printf("salut papy !");
  break;
default:
  printf("je n'ai aucune phrase de prete pour ton age  ");
  break;


}
*/
//int MAX=100,MIN=1;
//srand(time(NULL));

//int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
//plusoumoins(nombreMystere);
int tableau[5]={1,6,12,4,6};
somme(tableau,5);
printf("%d \n",somme(tableau,5));
printf("%f \n",moyenne(tableau,5));

int tableau2[5];
copie(tableau,tableau2,5);
affiche(tableau2,5);
ordonnerTableau(tableau2+2,tableau2,tableau2+4);
affiche(tableau2,5);
    return 0;

}

void plusoumoins(int nombre_secret)
{
    int nombre;
    printf("J'ai choisi un nombre entre 1 et 100, devinez lequel!");
    scanf("%d",&nombre);

    while (nombre!=nombre_secret){

        if(nombre<nombre_secret){
            printf("C'est plus grand!");
        }

        else{
            printf("C'est plus petit!");
        }
        scanf("%d",&nombre);

    }
    printf("Bien joue, le nombre etait %d",nombre_secret);



}

