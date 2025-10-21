#include <stdio.h>

int main() {
    int idade, contMais50 = 0, contAltura = 0, contPeso = 0, total = 0, opcao;
    float altura, peso, somaAltura = 0;

    do {
        printf("Digite idade, altura e peso: ");
        scanf("%d %f %f", &idade, &altura, &peso);

        if (idade > 50) contMais50++;
        if (idade >= 10 && idade <= 20) {
            somaAltura += altura;
            contAltura++;
        }
        if (peso < 40) contPeso++;
        total++;

        printf("Deseja continuar? (1-Sim / Outro-Nao): ");
        scanf("%d", &opcao);
    } while (opcao == 1);

    printf("Qtd idade > 50: %d\n", contMais50);
    if (contAltura > 0)
        printf("Media altura 10-20 anos: %.2f\n", somaAltura / contAltura);
    else
        printf("Nenhuma pessoa entre 10 e 20 anos.\n");
    printf("Percentual peso < 40kg: %.2f%%\n", (contPeso * 100.0) / total);

    return 0;
}
