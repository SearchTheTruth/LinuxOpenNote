#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


void *malloc(size_t sz)
{
    void *(*mallocp)(size_t);
    char *err;
    static int cnt = 0;

    ++cnt;

    mallocp = dlsym(RTLD_NEXT, "malloc");  /*get libc malloc addr*/
    if ((err = dlerror()) != NULL) {
        fputs(err, stderr);
        exit(1);
    }

    void *ptr = mallocp(sz);  /*call libc malloc*/
    if (cnt == 1)
        printf("malloc(%d) = %p\n", (int)sz, ptr);
    cnt = 0;
    return ptr;
}

void free(void *ptr)
{
    void (*freep)(void *);
    char *err;
    static int cnt = 0;

    ++cnt;

    freep = dlsym(RTLD_NEXT, "free"); /*get libc free addr*/
    if ((err = dlerror()) != NULL) {
        fputs(err, stderr);
        exit(1);
    }

    freep(ptr);  /*call libc free*/

    if (cnt == 1)
        printf("free = %p\n", ptr);
    cnt = 0;
}

