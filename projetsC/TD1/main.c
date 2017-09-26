#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
#include "ex3.h"

int main()
{
    printf("%d \n",addition(3,7));

    char a=220;
    char b=220;
    printf("%c %c \n",additionc(a,b),440);

    printf("%d \n",nbitsChar());
    printf("%d \n",nbitsUS());
    return 0;
}
