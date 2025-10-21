#include <stdio.h>

int main(void) {
    double x, soma = 0.0, fat = 1.0;
    int sinal = 1; // alterna +1 / -1

    printf("Digite X: ");
    if (scanf("%lf", &x) != 1) return 0;

    for (int k = 0; k < 20; k++) {
        if (k > 0) fat *= k;          // calcula k!
        soma += sinal * (x / fat);    // termo = sinal * X / k!
        sinal = -sinal;               // inverte sinal para o próximo termo
    }

    printf("Soma dos 20 primeiros termos = %.10f\n", soma);
    return 0;
}
