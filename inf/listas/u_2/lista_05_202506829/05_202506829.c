#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void *safeMalloc(size_t size);

int **matrixAlloc(int rows, int cols);

void freeMatrix(int **matrix, int rows);

void printMatrix(int **matrix, int rows, int cols);

int main() {

    int n = 0;
    while (n <= 1) {
        printf("Insira a dimensão da matriz (>1): ");
        scanf("%d", &n);
        if (n <= 1) {
            printf("Entrada inválida!\n");
        }
    }

    int **matrix = matrixAlloc(n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else if (i < j) { // acima da diagonal principal
                matrix[i][j] = 1;
            } else { // i > j -- abaixo da diagonal principal
                matrix[i][j] = -1;
            }
        }
    }

    printMatrix(matrix, n, n);
    
    freeMatrix(matrix, n);

    return 0;
}

void *safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}

int **matrixAlloc(int rows, int cols) {
    int **matrix = (int**) safeMalloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) safeMalloc(cols * sizeof(int));
    }

    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("{\n");
    for (int i = 0; i < rows; i++) {
        printf("  { ");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("}%s\n", i < rows - 1 ? ", " : "");
    }
    printf("}\n");
}