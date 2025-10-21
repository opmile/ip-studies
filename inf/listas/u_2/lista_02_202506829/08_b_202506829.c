#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// matriz Amxn - diagonal principal: elementos aij com i = j

void printMatrix(int **matrix, int rows, int cols);

int generateRandom(int max, int min);

void* safeMalloc(size_t size);

int** matrixAlloc(int rows, int cols);

int** fillMatrix(int rows, int cols);

int sumLowerMainDiagonal(int **matrix, int rows, int cols);

void freeMatrix(int **matrix, int rows);

int main() {
    srand(time(NULL));

    int rows = 0, cols = 0;

    printf("Insira o número de linhas da matriz: ");
    scanf("%d", &rows);

    printf("Insira o número de colunas da matriz: ");
    scanf("%d", &cols);

    int **matrix = fillMatrix(rows, cols);
    printMatrix(matrix, rows, cols);

    printf("Soma dos elementos acima da diagonal principal: %d\n",
         sumLowerMainDiagonal(matrix, rows, cols));

    freeMatrix(matrix, rows);

    return 0;
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("{\n");
    for (int i = 0; i < rows; i++) {
        printf("  { ");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf(" }%s\n", i < rows - 1 ? ", " : "");
    }
    printf("}\n");
}

int generateRandom(int max, int min) {
    return rand() % (max - min + 1) + min;
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
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

int** fillMatrix(int rows, int cols) {
    int **matrix = matrixAlloc(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom(10, 1);
        }
    }
    return matrix;
}

int sumLowerMainDiagonal(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j) {
                sum += matrix[i][j]; 
            }
        }
    }
    return sum;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}