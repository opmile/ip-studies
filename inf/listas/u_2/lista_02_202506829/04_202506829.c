#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void printArr(const int *arr, int len);

int generateRandom();

void* safeMalloc(size_t size);

int* fillArr(int len);

void bubbleSort(int *arr, int len);

int main() {
    srand(time(NULL));

    int *arr = fillArr(LEN);

    printf("Vetor original: ");
    printArr(arr, LEN);

    bubbleSort(arr, LEN);

    printf("Vetor resultante: ");
    printArr(arr, LEN);

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

// ordenação custosa! O(n^2)
void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



