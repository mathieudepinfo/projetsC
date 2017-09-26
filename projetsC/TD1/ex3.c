#include "ex3.h"
#include <stdio.h>

int nbits(long maxi)
{
    long c=1;
    int nbits=0;
    while((c&maxi)==c)
    {
        nbits++;
        c=c<<1;
    }
    return nbits;

}

int nbitsChar()
{
    char a=0;
    char b=1;
    long compteur=0;
    while(a!=b)
    {
        b++;
        compteur++;
    }


    return nbits(compteur);
}

int nbitsUS()
{
    unsigned short a=0;
    unsigned short b=1;
    long compteur=0;
    while(a!=b)
    {
        b++;
        compteur++;
    }


    return nbits(compteur);
}

