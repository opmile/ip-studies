#include <stdio.h>
#include <stdlib.h>

#define STANDARD_CHAR 50

typedef struct {
    char nome[STANDARD_CHAR];
    int idade;
    float salario;
    float valeAlimentacao;
} Funcionario;

int main() {
    int F, i;
    float somaSalarios = 0;

    printf("Informe o número de funcionários: ");
    scanf("%d", &F);
    getchar(); // limpa o \n pendente

    // Alocação dinâmica do vetor de structs
    Funcionario *funcionarios = (Funcionario *) malloc(F * sizeof(Funcionario));

    if (funcionarios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Leitura dos dados usando ponteiro
    for (i = 0; i < F; i++) {
        printf("\n=== Cadastro do %dº funcionário ===\n", i + 1);
        printf("Nome completo: ");
        fgets((funcionarios + i)->nome, STANDARD_CHAR, stdin);

        printf("Idade: ");
        scanf("%d", &(funcionarios + i)->idade);
        getchar();

        printf("Salário: ");
        scanf("%f", &(funcionarios + i)->salario);
        getchar();

        printf("Vale-alimentação: ");
        scanf("%f", &(funcionarios + i)->valeAlimentacao);
        getchar();

        somaSalarios += (funcionarios + i)->salario;
    }

    system("clear");

    printf("=== Dados dos Funcionários ===\n");
    for (i = 0; i < F; i++) {
        float ganhoTotal = (funcionarios + i)->salario + (funcionarios + i)->valeAlimentacao;
        printf("\nNome: %s", (funcionarios + i)->nome);
        printf("Ganho total mensal: R$ %.2f\n", ganhoTotal);
    }

    printf("\nMédia dos salários: R$ %.2f\n", somaSalarios / F);

    // Libera a memória
    free(funcionarios);

    return 0;
}
