#include <stdio.h>

int main() {
    int a, b, c, temp;

    printf("Digite tres valores inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    // Algoritmo simples de ordenação por trocas
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    printf("Valores em ordem crescente: %d, %d, %d\n", a, b, c);

    return 0;
}