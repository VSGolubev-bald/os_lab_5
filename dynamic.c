#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "APIarray.h"

int main() {
    array* (*arrayCreate)(size_t size);
    void (*arrayInsert)(array* a, size_t pos, int val);
    int (*arrayGet)(array* a, size_t pos);
    void (*arrayDelete)(array* a, size_t pos);
    void (*arrayResize)(array* a, size_t size);
    void (*arrayDestroy)(array* a);
    void (*arrayPrint)(array* a);
    char* error;
    void* libHandle;
    libHandle = dlopen("./libarr.so", RTLD_LAZY);
    if(!libHandle) {
        printf("%s\n", dlerror());
        return -1;
    }
    arrayCreate = dlsym(libHandle, "arrayCreate");
    arrayInsert = dlsym(libHandle, "arrayInsert");
    arrayGet = dlsym(libHandle, "arrayGet");
    arrayDelete = dlsym(libHandle, "arrayDelete");
    arrayResize = dlsym(libHandle, "arrayResize");
    arrayDestroy = dlsym(libHandle, "arrayDestroy");
    arrayPrint = dlsym(libHandle, "arrayPrint");
    printf("1 - create array with given size\n");
    printf("2 - insert element to array at given position\n");
    printf("3 - get element value on given position\n");
    printf("4 - delete element from given position\n");
    printf("5 - resize array to given size\n");
    printf("6 - print array\n");
    printf("0 - exit\n");
    int command = 0;
    array* a;
    int value = 0;
    int pos = 0;
    while(scanf("%d", &command) && command) {
        if(command == 1) {
            printf("Enter value\n");
            scanf("%d", &value);
            a = (*arrayCreate)(value);
        } else if(command == 2) {
            printf("Enter position & value\n");
            scanf("%d %d", &pos, &value);
            (*arrayInsert)(a, pos, value);
        } else if(command == 3) {
            printf("Enter position\n");
            scanf("%d", &pos);
            printf("%d\n", (*arrayGet)(a, pos));
        } else if(command == 4) {
            printf("Enter position\n");
            scanf("%d", &pos);
            (*arrayDelete)(a, pos);
        } else if(command == 5) {
            printf("Enter value\n");
            scanf("%d", &value);
            (*arrayResize)(a, value);
        } else if(command == 6) {
            (*arrayPrint)(a);
        }
    }
    (*arrayDestroy)(a);
    return 0;
}
