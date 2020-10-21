#include <stdlib.h>
#include <stdio.h>

#include "APIarray.h"

array* arrayCreate(size_t size) {
    if(size <= 0) {
        array* a = (array*)malloc(sizeof(array));
        a->data = (int*)malloc(sizeof(int));
        a->size = 1;
    }
    array* a = (array*)malloc(sizeof(array));
    a->data = (int*)malloc(sizeof(int) * size);
    a->size = size;
    return a;
}

void arrayInsert(array* a, size_t pos, int val) {
    if(pos >= a->size) {
        printf("Out of bounds\n");
        exit(-1); 
    }
    a->data[pos] = val;
}

int arrayGet(array* a, size_t pos) {
    if(pos >= a->size) {
        printf("Out of bounds\n");
        exit(-1);
    }
    return a->data[pos];
}

void arrayDelete(array* a, size_t pos) {
    if(pos >= a->size) {
        printf("Out of bounds\n");
        exit(-1);
    }
    int* newData = (int*)malloc(sizeof(int) * (a->size - 1));
    for(unsigned i = 0; i < a->size; ++i) {
        if(i < pos) {
            newData[i] = a->data[i];
        } else if(i > pos) {
            newData[i - 1] = a->data[i];
        }
    }
    free(a->data);
    a->data = newData;
}

void arrayResize(array* a, size_t size) {
    int* newData = (int*)malloc(sizeof(int) * size);
    if(size <= a->size) {
        for(unsigned i = 0; i < size; ++i) {
            newData[i]  = a->data[i];
        }
    } else {
        for(unsigned i = 0; i < a->size; ++i) {
            newData[i] = a->data[i];
        }
    }
    free(a->data);
    a->data = newData;
    a->size = size;
}

void arrayDestroy(array* a) {
    free(a->data);
    a->size = 0;
    free(a);
}

void arrayPrint(array* a) {
    for(unsigned i = 0; i < a->size; ++i) {
        printf("%d ", a->data[i]);
    }
    printf("\n");
}
