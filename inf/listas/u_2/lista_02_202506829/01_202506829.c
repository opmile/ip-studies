#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN 5

int generateRandomNumber();

int* fillArray(int len);

void* safeAllocaiton(size_t size);

void printArr(const int *arr, int len);

int sumTwoArrays(const int *arrA, const int *arrB, int len);

int main() {
    srand(time(NULL));

    int *arrA = fillArray(LEN);
    int *arrB = fillArray(LEN);

    printf("Vetores gerados: \n");

    printArr(arrA, LEN);
    printArr(arrB, LEN);

    printf("Soma: %d\n", sumTwoArrays(arrA, arrB, LEN));

    free(arrA);
    free(arrB);

    return 0;
}

int generateRandomNumber() {
    return rand() % 100 + 1; // 1 a 100
}

void* safeAllocaiton(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    return ptr;
}

int* fillArray(int len) {
    int *arr = (int*) safeAllocaiton(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = generateRandomNumber();
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

int sumTwoArrays(const int *arrA, const int *arrB, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arrA[i] + arrB[i];
    }
    return sum;
}
