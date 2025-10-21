#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **matrix, int rows, int cols);

void printArr(int *arr, int len);

void* safeAlloc(size_t size);

int** matrixAlloc(int rows, int cols);

int generateRandom(int max, int min);

int** fillMatrix(int rows, int cols);

int* generateResultantArr(int **matrix, int rows, int cols);

void freeMatrix(int **matrix, int rows);

int main() {
    srand(time(NULL));

    int rows = generateRandom(4, 1);
    int cols = generateRandom(4, 1);

    int **matrix = fillMatrix(rows, cols);

    printf("Matriz gerada: \n");
    printMatrix(matrix, rows, cols);

    printf("Vetor resultante: \n");
    int *arr = generateResultantArr(matrix, rows, cols);
    printArr(arr, cols);

    free(arr);
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

void printArr(int *arr, int len) {
    printf("{ ");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1) printf(", ");
    }
    printf(" }\n");
}

void* safeAlloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    return ptr;
}

int generateRandom(int max, int min) {
    return rand() % (max - min + 1) + min;
}

int** matrixAlloc(int rows, int cols) {
    int **matrix = (int**) safeAlloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) safeAlloc(cols * sizeof(int));
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

int* generateResultantArr(int **matrix, int rows, int cols) {
    int *arr = (int*) safeAlloc(cols * sizeof(int));

    for (int j = 0; j < cols; j++) {
        int element = 0;
        for (int i = 0; i < rows; i++) {
            element += matrix[i][j];
        }
        arr[j] = element;
    }

    return arr;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}