#include <stdio.h>

int main() {
    float nota_trabalho, nota_teste, nota_prova, media_final;

    printf("Digite a nota do trabalho (0 a 10): ");
    scanf("%f", &nota_trabalho);

    printf("Digite a nota do teste em laboratorio (0 a 10): ");
    scanf("%f", &nota_teste);

    printf("Digite a nota da prova escrita (0 a 10): ");
    scanf("%f", &nota_prova);

    media_final = (nota_trabalho * 2 + nota_teste * 2 + nota_prova * 6) / 10;

    printf("A média final do estudante é: %.2f\n", media_final);

    return 0;
}
