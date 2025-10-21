#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 3 == 0 && numero % 7 == 0) {
        printf("O número %d é divisivel por 3 e por 7.\n", numero);
    } else {
        printf("O número %d nao é divisivel por 3 e por 7 simultaneamente.\n", numero);
    }

    return 0;
}