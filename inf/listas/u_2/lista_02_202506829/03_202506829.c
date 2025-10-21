#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LEN 10

// primo -> divide por 1 e por ele mesmo

// se n possui um divisor, ele aparece antes de √n
// n = 100, √n = 50
// 4 * 25 = 100 -- 4 é um divisor
// 25 * 4 = 100 -- chequei duas vezes!!
// condição de parada do for: i < √n == i * i < n

int checkIfPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int generateRandom(int max, int min) {
    return rand() % (max - min + 1) + min;
}

void *safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}

int* fillArr(int len) {
    int *arr = (int*) safeMalloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = generateRandom(100, 1);
    }
    return arr;
}

void verify(const int *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (checkIfPrime(arr[i]) == 1) {
            printf("Primo encontrado na posição %d: %d\n", i + 1, arr[i]);
        }
    }
}

void printArr(const int *arr, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf("}\n");
}

int main() {
    srand(time(NULL));

    int *arr = fillArr(LEN);

    printf("Vetor: ");
    printArr(arr, LEN);

    verify(arr, LEN);

    return 0;
}