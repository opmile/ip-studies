#include <stdio.h>

int main() {

    int aprov = 0,
    recup = 0, 
    reprov = 0;

    float somaTurma = 0, 
    mediaTurma = 0;

    float nota1 = 0.0f, 
    nota2 = 0.0f, 
    nota3 = 0.0f;

    int matriculaBase = 2025000;
    int counter = 1;

    int totalMatriculados;

    printf("-- Relatório de Desepenho da Turma --\n");

    printf("Informe o total de alunos matriculados: ");
    scanf("%d", &totalMatriculados);

    for (int i = 0; i < totalMatriculados; i++) {
        printf("Matrícula: %d\n", matriculaBase + counter++);

        printf("Nota 1: ");
        scanf("%f", &nota1);

        printf("Nota 2: ");
        scanf("%f", &nota2);

        printf("Nota 3: ");
        scanf("%f", &nota3);

        float mediaAluno = (nota3 + nota2 + nota1) / 3;
        somaTurma += mediaAluno;

        printf("Média: %.2f\n", mediaAluno);
    
        printf("Situação: ");
        if (mediaAluno <= 4) {
            printf("REPROVADO");
            reprov++;
        } else if (mediaAluno < 7) {
            printf("RECUPERAÇÃO");
            recup++;
        } else {
            printf("APROVADO");
            aprov++;
        }
        printf("\n");
    }
    
    mediaTurma = somaTurma / totalMatriculados;
    printf("Média da turma: %.2f\n", mediaTurma);
    printf("Aprovados: %d\n", aprov);
    printf("Recuperação: %d\n", recup);
    printf("Reprovados: %d\n", reprov);
}