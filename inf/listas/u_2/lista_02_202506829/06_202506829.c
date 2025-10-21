#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **matrix, int rows, int cols);

void* safeMalloc(size_t size);

int** matrixAlloc(int rows, int cols);

int generateRandom(int max, int min);

int** fillMatrix(int rows, int cols);

int** sumTwoMatrixes(int **matrixA, int **matrixB, int rows, int cols);

void freeMatrix(int **matrix, int rows);

int main() {
    srand(time(NULL));

    int rows = 0, cols = 0;

    printf("Digite o número de linhas das matrizes: ");
    scanf("%d", &rows);

    printf("Digite o número de colunas das matrizes: ");
    scanf("%d", &cols);

    int **matrixA = fillMatrix(rows, cols);
    printf("Matrix A = \n");
    printMatrix(matrixA, rows, cols);

    int **matrixB = fillMatrix(rows, cols);
    printf("Matrix B = \n");
    printMatrix(matrixB, rows, cols);

    printf("Seja C = A + B (a soma das duas matrizes): \n");
    int **matrixC = sumTwoMatrixes(matrixA, matrixB, rows, cols);
    printMatrix(matrixC, rows, cols);

    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(matrixC, rows);
    
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

int generateRandom(int max, int min) {
    return rand() % (max - min + 1) + min;
}

int** fillMatrix(int rows, int cols) {
    int** matrix = matrixAlloc(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom(10, 1);
        }
    }
    return matrix;
}

int** sumTwoMatrixes(int **matrixA, int **matrixB, int rows, int cols) {
    int **matrixResult = matrixAlloc(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return matrixResult;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}