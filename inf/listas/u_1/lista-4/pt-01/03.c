#include <stdio.h>

int main() {
    double salarioCarlos, salarioJoao;
    double valorCarlos, valorJoao;
    int meses = 0;

    printf("Digite o salario de Carlos: ");
    scanf("%lf", &salarioCarlos);

    salarioJoao = salarioCarlos / 3.0;
    valorCarlos = salarioCarlos;
    valorJoao = salarioJoao;

    while (valorJoao < valorCarlos) {
        valorCarlos *= 1.02; // aumenta 2%
        valorJoao *= 1.05;   // aumenta 5%
        meses++;
    }

    printf("Serao necessarios %d meses para que Joao ultrapasse ou iguale Carlos.\n", meses);

    return 0;
}
