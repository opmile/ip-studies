#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void printArr(const int *arr, int len);

int generateRandom();

void* safeMalloc(size_t size);

int* fillArr(int len);

void findBiggest(int *arr, int len);

int main() {
    srand(time(NULL));

    int *arr = fillArr(LEN);
    printArr(arr, LEN);

    findBiggest(arr, LEN);

    free(arr);

    return 0;
}

void printArr(const int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

int generateRandom() {
    return rand() % 20 + 1;
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}

int* fillArr(int len) {
    int *arr = (int*) safeMalloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = generateRandom();
    }
    return arr;
}

void findBiggest(int *arr, int len) {
    int result = 0;
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > result) {
            result = arr[i];
            index = i;
        }
    }
    printf("Maior elemento encontrado na posição %d: %d\n", index + 1, result);
}