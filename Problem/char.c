#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("这个routine为测试\nchar *a[2]和(char *a)[2]的区别\n");

    unsigned int sizea = 0;
    unsigned int sizeb = 0;

    char *chp1 = "charp";
    char *chp2 = "charp";
    char ch1 = 'a';
    char ch2 = 'f';

    char *a[2] = {chp1, chp2};
    char (*b)[2] = {ch1, ch2};
    //volatile char (*b)[2] = {'c', 'h'};

    printf("a[0] = %s,a[1] = %s, b[0] = %c, b[1] = %c\n", a[0], a[1], b[0], b[1]);

    sizea = sizeof(a);
//    sizeb = sizeof(b);//in fact here is sizeof a point b
    sizeb = sizeof(b[0]) * 2;
    printf("pointer = %d, char = %d\n", (int)sizeof(char *), (int)sizeof(char));
    printf("expect sizea = 16, actually sizea = %d\n", sizea);
    printf("expect sizeb = 2, actually sizeb = %d\n", sizeb);

    return 0;
}
