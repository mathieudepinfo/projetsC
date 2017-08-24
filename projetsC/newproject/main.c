#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombreDeVies;
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
    return 0;

}
