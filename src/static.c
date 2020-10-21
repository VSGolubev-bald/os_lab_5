#include <stdio.h>

#include "APIarray.h"

int main() {
    int command = 0;
    array* a;
    int value = 0;
    int pos = 0;
    printf("1 - create array with given size\n");
    printf("2 - insert element to array at given position\n");
    printf("3 - get element value on given position\n");
    printf("4 - delete element from given position\n");
    printf("5 - resize array to given size\n");
    printf("6 - print array\n");
    printf("0 - exit\n");
    while(scanf("%d", &command) && command) {
        if(command == 1) {
            printf("Enter value\n");
            scanf("%d", &value);
            a = arrayCreate(value);
        } else if(command == 2) {
            printf("Enter position and value\n");
            scanf("%d %d", &pos, &value);
            arrayInsert(a, pos, value);
        } else if(command == 3) {
            printf("Enter position\n");
            scanf("%d", &pos);
            printf("%d\n", arrayGet(a, pos));
        } else if(command == 4) {
            printf("Enter position\n");
            scanf("%d", &pos);
            arrayDelete(a, pos);
        } else if(command == 5) {
            printf("Enter value\n");
            scanf("%d", &value);
            arrayResize(a, value);
        } else if(command == 6) {
            arrayPrint(a);
        }
    }
    arrayDestroy(a);
    return 0;
}
