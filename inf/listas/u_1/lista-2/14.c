#include <stdio.h>

int main() {
    float a, b, c, d, maior, menor;

    printf("Digite quatro valores (A, B, C e D): ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    // Inicializa maior e menor com o primeiro valor
    maior = a;
    menor = a;

    // Compara com B
    if (b > maior) maior = b;
    if (b < menor) menor = b;

    // Compara com C
    if (c > maior) maior = c;
    if (c < menor) menor = c;

    // Compara com D
    if (d > maior) maior = d;
    if (d < menor) menor = d;

    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);

    return 0;
}