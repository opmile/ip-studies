#include <stdio.h>

int main() {
    int num, qtd = 0, soma = 0, maior, menor;
    int somaPares = 0, qtdPares = 0, qtdImpares = 0;

    printf("Digite um numero (30000 para parar): ");
    scanf("%d", &num);

    maior = menor = num;

    while (num != 30000) {
        soma += num;
        qtd++;

        if (num > maior) maior = num;
        if (num < menor) menor = num;

        if (num % 2 == 0) {
            somaPares += num;
            qtdPares++;
        } else {
            qtdImpares++;
        }

        printf("Digite um numero (30000 para parar): ");
        scanf("%d", &num);
    }

    printf("Soma: %d\n", soma);
    printf("Quantidade: %d\n", qtd);
    printf("Media: %.2f\n", (float)soma / qtd);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    if (qtdPares > 0)
        printf("Media pares: %.2f\n", (float)somaPares / qtdPares);
    else
        printf("Nenhum numero par\n");
    printf("Percentual impares: %.2f%%\n", (qtdImpares * 100.0) / qtd);

    return 0;
}
