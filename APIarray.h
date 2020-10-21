#ifndef _ARRAY_API_H
#define _ARRAY_API_H

#include <stdlib.h>

typedef struct array array;

struct array{
    int* data;
    size_t size;
};

array* arrayCreate(size_t size);
void arrayInsert(array* a, size_t pos, int val);
int arrayGet(array* a, size_t pos);
void arrayDelete(array* a, size_t pos);
void arrayResize(array* a, size_t size);
void arrayDestroy(array* a);
void arrayPrint(array* a);
#endif // _ARRAY_API_H
