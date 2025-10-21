#include <stdio.h>
#include <math.h>

int main() {
    double numero;

    printf("Digite um numero: ");
    scanf("%lf", &numero);

    if (numero >= 0) {
        printf("A raiz quadrada de %.2f é %.2f\n", numero, sqrt(numero));
    } else {
        printf("O quadrado de %.2f é %.2f\n", numero, pow(numero, 2));
    }

    return 0;
}