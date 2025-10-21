#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandomNumber(int max, int min);

void* safeMalloc(size_t size);

int* fillArr(int len);

void printArr(const int *arr, int len);

int crossProduct(const int *arrA, const int *arrB, int len);

int main() {
    srand(time(NULL));

    int dimension = generateRandomNumber(30, 1);
    printf("Dimensão dos vetores: %d", dimension);
    
    int *arrA = fillArr(dimension);
    int *arrB = fillArr(dimension);

    printf("Representação vetorial: \n");

    printArr(arrA, dimension);
    printArr(arrB, dimension);

    printf("Produto Vetorial: %d\n", crossProduct(arrA, arrB, dimension));

    free(arrA);
    free(arrB);

    return 0;
}

void* safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação!\n");
    }
    return ptr;
}

int generateRandomNumber(int max, int min) {
    return rand() % (max - min + 1) + min;
}

int* fillArr(int len) {
    // cppcheck-suppress cstyleCast
    int *arr = (int*) safeMalloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = generateRandomNumber(50, 0); // elementos que variam de 0 a 50
    }
    return arr;
}

void printArr(const int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

int crossProduct(const int *arrA, const int *arrB, int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += arrA[i] * arrB[i];
    }
    return result;
}