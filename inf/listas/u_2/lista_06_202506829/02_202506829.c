#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void *safeAlloc(size_t size);
int generateRandom();
int* fill(int len);
void printArr(int *arr, int len);

int main() {
    srand(time(NULL));

    int len = 5;
    int *arr = fill(len);
    printArr(arr, len);

    return 0;
}

void *safeAlloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação");
        exit(1);
    }
    return ptr;
}

int generateRandom() {
    return rand() % 10 + 1; 
}

int* fill(int len) {
    int *arr = (int*) safeAlloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        *(arr + i) = generateRandom();
    }
    return arr;
}

void printArr(int *arr, int len) {
    printf("{ ");
    for (int i = 0; i < len; i++) {
        printf("%d", *(arr + i));
        if (i < len - 1) printf(", ");
    }
    printf(" }\n");
}