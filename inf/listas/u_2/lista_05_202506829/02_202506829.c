#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void* safeMalloc(size_t size);

int* allocArr(int len);

void printArr(int *arr, int len);

int main() {
    int len = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &len);

    int *arr = allocArr(len);

    for (int i = 0; i < len; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printArr(arr, len);

    free(arr);

    return 0;
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}

int* allocArr(int len) {
    return (int*) safeMalloc(len * sizeof(int));
}

void printArr(int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}