#include <stdio.h>

int main() {
    int n, aprov = 0, exame = 0, reprov = 0;
    float nota1, nota2, media, somaClasse = 0;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite as duas notas do aluno %d: ", i+1);
        scanf("%f %f", &nota1, &nota2);

        media = (nota1 + nota2) / 2;
        somaClasse += media;

        printf("Media: %.2f - ", media);
        if (media < 3) {
            printf("Reprovado\n");
            reprov++;
        } else if (media < 7) {
            printf("Exame\n");
            exame++;
        } else {
            printf("Aprovado\n");
            aprov++;
        }
    }

    printf("Total aprovados: %d\n", aprov);
    printf("Total exame: %d\n", exame);
    printf("Total reprovados: %d\n", reprov);
    printf("Media da classe: %.2f\n", somaClasse / n);

    return 0;
}
