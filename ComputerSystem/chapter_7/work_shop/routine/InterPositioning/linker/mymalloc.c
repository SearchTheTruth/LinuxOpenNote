#include <stdio.h>
#include <malloc.h>

void *__real_malloc(size_t);
void __real_free(void *);

void *__wrap_malloc(size_t sz)
{
    void *ptr = __real_malloc(sz);      /*libc malloc*/
    printf("malloc(%d) = %p\n", (int)sz, ptr);
    return ptr;
}

void __wrap_free(void *ptr)
{
    __real_free(ptr);                          /*libc free*/
    printf("free = %p\n", ptr);
}

