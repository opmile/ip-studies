#include <stdio.h>

int main() {
    float x, y, z;

    printf("Digite os três comprimentos (X, Y e Z): ");
    scanf("%f %f %f", &x, &y, &z);

    // O comprimento de cada lado de um triângulo é menor que a soma dos outros dois
    if (x < y + z && y < x + z && z < x + y) {
        printf("Os valores formam um triângulo.\n");
        if (x == y && y == z) {
            printf("Tipo: Equilátero\n"); 
        } else if (x == y || y == z || x == z) {
            printf("Tipo: Isósceles\n"); 
        } else {
            printf("Tipo: Escaleno\n"); 
        }
    } else {
        printf("Os valores não formam um triângulo.\n"); 
    }

    return 0;
}