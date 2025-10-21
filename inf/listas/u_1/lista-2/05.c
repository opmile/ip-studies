#include <stdio.h>
#include <stdlib.h> // função abs()

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("Valor original: %d\n", numero);
    if (numero < 0) {
        printf("Valor absoluto: %d\n", abs(numero));
    }

    return 0;
}