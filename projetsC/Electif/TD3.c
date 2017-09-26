#include <stdio.h>
#include <stdlib.h>
#include "module.h"

int main(int argc,char* argv[])
{
    if(atoi(argv[1]))
    {
        printf("%d \n",fibonnacci(atoi(argv[1])));
    }

    if(atoi(argv[2]))
    {

        printf("%d \n",nbits(atoi(argv[2])));
    }

    return 0;
}

