#include <stdio.h>
#include <stdlib.h>

extern char *out;
char *global = "global symbol";
static char *local = "local symbol";
int common;

int main()
{
    printf("%s\n", out);
    printf("%s\n", global);
    printf("%s\n", local);
    return 0;
}
