#include <stdio.h>

int main() {
    int numero, centenas, dezenas, unidades;

    printf("Digite um número inteiro positivo de 3 casas: ");
    scanf("%d", &numero);

    if (numero >= 100 && numero <= 999) { 
        centenas = numero / 100;
        dezenas = (numero / 10) % 10;
        unidades = numero % 10;

        printf("Algarismo das centenas: %d\n", centenas);
        printf("Algarismo das dezenas: %d\n", dezenas);
        printf("Algarismo das unidades: %d\n", unidades);
    } else {
        printf("O número informado não tem 3 casas.\n");
    }

    return 0;
}