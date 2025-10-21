#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct {
    char codigo[MAX_STR];
    float nota;
    int frequencia;
    char nucleo[MAX_STR];
    char situacao[MAX_STR];
} Disciplina; // N3

typedef struct {
    char periodo[MAX_STR];
    int qtdDisciplinas;
    float mediaSemestral;
    Disciplina *disciplinas;
} Periodo; // N2

typedef struct {
    char matricula[MAX_STR];
    char nome[MAX_STR];
    char corRaca[MAX_STR];
    char estadoCivil[MAX_STR];
    char curso[MAX_STR];
    char anoIngresso[MAX_STR];
    char instituicao[MAX_STR];
    char situacaoAtual[MAX_STR];
    int qtdPeriodos;
    Periodo *periodos;
} Aluno; // N1

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void safeFlush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para determinar situação da disciplina
void definirSituacao(Disciplina *d) {
    if (d->nota >= 6.0 && d->frequencia >= 75)
        strcpy(d->situacao, "Aprovado");
    else
        strcpy(d->situacao, "Reprovado");
}

// Entrada dos dados de um aluno completo
Aluno inserirAluno() {
    Aluno a;
    printf("Matrícula: ");
    fgets(a.matricula, MAX_STR, stdin); a.matricula[strcspn(a.matricula, "\n")] = '\0';

    printf("Nome completo: ");
    fgets(a.nome, MAX_STR, stdin); a.nome[strcspn(a.nome, "\n")] = '\0';

    printf("Cor/Raça/Etnia: ");
    fgets(a.corRaca, MAX_STR, stdin); a.corRaca[strcspn(a.corRaca, "\n")] = '\0';

    printf("Estado civil: ");
    fgets(a.estadoCivil, MAX_STR, stdin); a.estadoCivil[strcspn(a.estadoCivil, "\n")] = '\0';

    printf("Curso: ");
    fgets(a.curso, MAX_STR, stdin); a.curso[strcspn(a.curso, "\n")] = '\0';

    printf("Ano de ingresso: ");
    fgets(a.anoIngresso, MAX_STR, stdin); a.anoIngresso[strcspn(a.anoIngresso, "\n")] = '\0';

    printf("Instituição: ");
    fgets(a.instituicao, MAX_STR, stdin); a.instituicao[strcspn(a.instituicao, "\n")] = '\0';

    printf("Situação atual: ");
    fgets(a.situacaoAtual, MAX_STR, stdin); a.situacaoAtual[strcspn(a.situacaoAtual, "\n")] = '\0';

    printf("Quantidade de períodos cursados: ");
    scanf("%d", &a.qtdPeriodos);
    safeFlush();

    a.periodos = (Periodo*) malloc(a.qtdPeriodos * sizeof(Periodo));

    for (int i = 0; i < a.qtdPeriodos; i++) {
        printf("\n=== Período %d ===\n", i + 1);
        printf("Referência do período (ex: 2016.1): ");
        fgets(a.periodos[i].periodo, MAX_STR, stdin); a.periodos[i].periodo[strcspn(a.periodos[i].periodo, "\n")] = '\0';

        printf("Quantidade de disciplinas: ");
        scanf("%d", &a.periodos[i].qtdDisciplinas);
        safeFlush();

        a.periodos[i].disciplinas = (Disciplina*) malloc(a.periodos[i].qtdDisciplinas * sizeof(Disciplina));

        float somaNotas = 0.0f;
        for (int j = 0; j < a.periodos[i].qtdDisciplinas; j++) {
            printf("\n--- Disciplina %d ---\n", j + 1);
            printf("Código: ");
            fgets(a.periodos[i].disciplinas[j].codigo, MAX_STR, stdin);
            a.periodos[i].disciplinas[j].codigo[strcspn(a.periodos[i].disciplinas[j].codigo, "\n")] = '\0';

            printf("Núcleo: ");
            fgets(a.periodos[i].disciplinas[j].nucleo, MAX_STR, stdin);
            a.periodos[i].disciplinas[j].nucleo[strcspn(a.periodos[i].disciplinas[j].nucleo, "\n")] = '\0';

            printf("Nota (0 a 10): ");
            scanf("%f", &a.periodos[i].disciplinas[j].nota);
            safeFlush();

            printf("Frequência (0 a 100): ");
            scanf("%d", &a.periodos[i].disciplinas[j].frequencia);
            safeFlush();

            definirSituacao(&a.periodos[i].disciplinas[j]);
            somaNotas += a.periodos[i].disciplinas[j].nota;
        }

        a.periodos[i].mediaSemestral = somaNotas / a.periodos[i].qtdDisciplinas;
    }

    return a;
}

void imprimirAluno(Aluno a) {
    printf("\n====================================\n");
    printf("Matrícula: %s\n", a.matricula);
    printf("Nome: %s\n", a.nome);
    printf("Cor/Raça: %s\n", a.corRaca);
    printf("Estado civil: %s\n", a.estadoCivil);
    printf("Curso: %s\n", a.curso);
    printf("Ano de ingresso: %s\n", a.anoIngresso);
    printf("Instituição: %s\n", a.instituicao);
    printf("Situação atual: %s\n", a.situacaoAtual);
    printf("====================================\n");

    for (int i = 0; i < a.qtdPeriodos; i++) {
        printf("\n>> Período: %s\n", a.periodos[i].periodo);
        printf("Média semestral: %.2f\n", a.periodos[i].mediaSemestral);
        printf("Lista de disciplinas:\n");

        for (int j = 0; j < a.periodos[i].qtdDisciplinas; j++) {
            Disciplina d = a.periodos[i].disciplinas[j];
            printf("  - Código: %s | Núcleo: %s | Nota: %.1f | Freq: %d%% | Situação: %s\n",
                   d.codigo, d.nucleo, d.nota, d.frequencia, d.situacao);
        }
    }
    printf("====================================\n");
}

int main() {
    int qtdAlunos;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &qtdAlunos);
    safeFlush();

    Aluno *alunos = (Aluno*) malloc(qtdAlunos * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }

    for (int i = 0; i < qtdAlunos; i++) {
        limparTela();
        printf("=== Cadastro do aluno %d ===\n", i + 1);
        alunos[i] = inserirAluno();
    }

    limparTela();
    printf("\n=== RELATÓRIO DE ALUNOS ===\n");
    for (int i = 0; i < qtdAlunos; i++)
        imprimirAluno(alunos[i]);

    // liberar memória
    for (int i = 0; i < qtdAlunos; i++) {
        for (int j = 0; j < alunos[i].qtdPeriodos; j++)
            free(alunos[i].periodos[j].disciplinas);
        free(alunos[i].periodos);
    }
    free(alunos);

    return 0;
}
