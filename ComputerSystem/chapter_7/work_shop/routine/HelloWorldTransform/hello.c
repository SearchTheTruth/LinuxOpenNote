#include <stdio.h>
#include <stdlib.h>
#include "useless.h"

#define MACRO_HW "HelloWorld"

int main()
{
    char *str = MACRO_HW;

    printf("%s\n", str);

    return 0;
}

