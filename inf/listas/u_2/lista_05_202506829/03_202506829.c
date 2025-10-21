#include <stdio.h>
#include <stdlib.h>

void* safeMalloc(size_t size);
int* allocArr(int len);
void printArr(int *arr, int len);

int main() {
    int n = -1;
    while (n <= 0) {
        printf("Digite um inteiro válido: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Entrada inválida!\n");
        }
    }

    int *arr = allocArr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
        while (arr[i] < 2) {
            printf("arr[%d] = ", i);
            scanf("%d", &arr[i]);
            if (arr[i] < 2)  {
                printf("Elemento deve ser maior ou igual a 2!\n");
            }
        }
    }

    printArr(arr, n);

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