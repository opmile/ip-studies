#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int **matrix, int rows, int cols);

void* safeMalloc(size_t size);

int** matrixAlloc(int rows, int cols);

int generateRandom(int max, int min);

int** fillMatrix(int rows, int cols);

void freeMatrix(int **matrix, int rows);

int sumMatrix(int **matrix, int rows, int cols);

int main() {
    srand(time(NULL));

    int rows = 0, cols = 0;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &rows);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &cols);

    int **matrix = fillMatrix(rows, cols);
    printf("Matriz gerada = \n");
    printMatrix(matrix, rows, cols);

    printf("Soma de todos os elementos = %d\n", sumMatrix(matrix, rows, cols));
    
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
        printf("}%s\n", i < rows - 1 ? ", " : "");
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

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int sumMatrix(int **matrix, int rows, int cols) {
    int result = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result += matrix[i][j];
        }
    }
    return result;
}

