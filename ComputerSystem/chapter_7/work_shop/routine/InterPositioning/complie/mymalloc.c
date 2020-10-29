#include <stdio.h>
#include <malloc.h>

void *mymalloc(size_t sz)
{
    void *ptr = malloc(sz);
    printf("malloc(%d) = %p\n", (int)sz, ptr);
    return ptr;
}

void myfree(void *ptr)
{
    free(ptr);
    printf("free = %p\n", ptr);
}

