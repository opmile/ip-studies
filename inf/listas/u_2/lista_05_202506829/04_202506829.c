#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* safeMalloc(size_t size);

int** matrixAlloc(int rows, int cols);

void freeMatrix(int **matrix, int rows);

int generateRandom();

void printMatrix(int **matrix, int rows, int cols);

int main() {
    srand(time(NULL));

    int n = generateRandom();
    printf("Dimensão N aleatória gerada: %d\n", n);

    int **matrix = matrixAlloc(n, n);

    printf("Preencha as posições da matriz com números pares: \n");
    int pos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &pos);
            if (pos % 2 != 0) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = pos;
            }
        }
    }

    printMatrix(matrix, n, n);

    freeMatrix(matrix, n);

    return 0;
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr ==  NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}

int** matrixAlloc(int rows, int cols) {
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

int generateRandom() {
    return rand() % 5 + 2; // min 2 : max 5
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