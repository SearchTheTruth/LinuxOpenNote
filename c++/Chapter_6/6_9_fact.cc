#include "Chapter6.h"

int fact(int num)
{
    int ret = 1;

    while (num > 0) {
        ret *= num--;
    }
    return ret;
}
