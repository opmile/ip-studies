#include <stdio.h>

int main() {
    float nota_trabalho, nota_teste, nota_prova, media_final;
    int numero_faltas;
    const int total_aulas = 64;
    const float max_faltas_permitidas = total_aulas * 0.25;

    printf("Digite a nota do trabalho (0 a 10): ");
    scanf("%f", &nota_trabalho);

    printf("Digite a nota do teste em laboratorio (0 a 10): ");
    scanf("%f", &nota_teste);

    printf("Digite a nota da prova escrita (0 a 10): ");
    scanf("%f", &nota_prova);

    printf("Digite o numero de faltas: ");
    scanf("%d", &numero_faltas);

    media_final = (nota_trabalho * 2 + nota_teste * 2 + nota_prova * 6) / 10;

    printf("A media final do estudante e: %.2f\n", media_final);

    if (numero_faltas > max_faltas_permitidas) {
        printf("REPROVADO POR FALTA\n");
    } else {
        if (media_final >= 7.0) {
            printf("ALUNO APROVADO\n");
        } else if (media_final >= 5.0 && media_final < 7.0) {
            printf("PROVA FINAL\n");
        } else {
            printf("ALUNO REPROVADO\n");
        }
    }

    return 0;
}