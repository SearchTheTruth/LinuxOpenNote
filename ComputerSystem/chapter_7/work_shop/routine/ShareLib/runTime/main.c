#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>


int main()
{
    void *handle;
    char *err;
    void (*showp)(void);

    handle = dlopen("./libshow.so", RTLD_LAZY);
    if ((err = dlerror()) != NULL) {
        fputs(err, stderr);
        exit(1);
    }

    showp = dlsym(handle, "show");
    if ((err = dlerror()) != NULL) {
        fputs(err, stderr);
        exit(1);
    }
    showp();

    if (dlclose(handle) < 0) {
        fputs("close failed", stderr);
        exit(1);
    }

    return 0;
}
