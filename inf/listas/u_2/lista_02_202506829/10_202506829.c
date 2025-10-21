#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// usuário considera que a linha escolhida começa em 1
// para o programa, a posição é traduzida em (linha - 1)

void printMatrix(int **matrix, int rows, int cols);

int generateRandom(int max, int min);

void* safeMalloc(size_t size);

int** matrixAlloc(int rows, int cols);

int** fillMatrix(int rows, int cols);

void freeMatrix(int **matrix, int rows);

int sumRow(int **matrix, int rows, int cols, int row);

int main() {
    srand(time(NULL));

    int chosenRow = 0;

    int rows = generateRandom(5, 1);
    int cols = generateRandom(4, 1);

    int **matrix = fillMatrix(rows, cols);

    printf("Matriz = \n");
    printMatrix(matrix, rows, cols);

    printf("Escolha até a linha %d: ", rows);
    scanf("%d", &chosenRow);

    printf("Soma da linha %d: %d\n",
         chosenRow, sumRow(matrix, rows, cols, chosenRow));

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

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int sumRow(int **matrix, int rows, int cols, int row) {
    if (row - 1 > rows) {
        printf("Linha maior que os limites da matriz!\n");
        exit(1);
    }

    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += matrix[row - 1][j];
    }    
    return sum;
}
