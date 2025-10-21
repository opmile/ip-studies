#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *safeMalloc(size_t size);

int **matrixAlloc(int rows, int cols);

void freeMatrix(int **matrix, int rows);

void printMatrix(int **matrix, int rows, int cols);

int generateRandom();

int main() {
    srand(time(NULL));

    int n = generateRandom();
    printf("Dimensão N da matriz: %d\n", n);

    int **matrix = matrixAlloc(n, n);

    int pos = 0;
    printf("matriz[0][0]= ");
    scanf("%d", &pos);
    matrix[0][0] = pos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                matrix[i][j] *= 2;
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
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
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

int generateRandom() {
    return rand() % 4 + 2; // dimensão: min 2, max 5
}