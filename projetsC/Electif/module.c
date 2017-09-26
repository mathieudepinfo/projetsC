#include "module.h"

int fibonnacci(int n)
{
    int u0=0;
    int u1=1;
    int tmp;

    for(int i=0;i<n;i++)
    {
        tmp=u1;
        u1=u0+u1;
        u0=tmp;

    }
    return u1;
}

int nbits(int n)
{
    int cp=0;
    for(int i=0;i<(sizeof(n)*8);i++)
    {
        if(n&(1<<i))
        {
            cp++;
        }
    }
    return cp;
}
