#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STANDARD_CHAR 50

typedef struct {
    char logradouro[STANDARD_CHAR];
    int numero;
    char cep[15];
    char cidade[STANDARD_CHAR];
    char estado[3];
} Endereco;

typedef struct {
    char nome[STANDARD_CHAR];
    int idade;
    char instagram[STANDARD_CHAR];
    char telefone[20];
    Endereco endereco;
} Pessoa;

void limparBuffer();

int main() {

    Pessoa p, *ptr = &p;

    printf("== CADASTRO DE PESSOA ==\n");

    printf("Nome completo = ");
    fgets(ptr->nome, STANDARD_CHAR, stdin);
    ptr->nome[strcspn(ptr->nome, "\n")] = '\0';

    printf("Idade = ");
    scanf("%d", &ptr->idade);
    limparBuffer();

    printf("Instagram = ");
    fgets(ptr->instagram, STANDARD_CHAR, stdin);
    ptr->instagram[strcspn(ptr->instagram, "\n")] = '\0';

    printf("Telefone = ");
    fgets(ptr->telefone, 20, stdin);
    ptr->telefone[strcspn(ptr->telefone, "\n")] = '\0';

    printf("== DADOS DE ENDEREÇO ==\n");

    printf("Logradouro: ");
    fgets(ptr->endereco.logradouro, STANDARD_CHAR, stdin);
    ptr->endereco.logradouro[strcspn(ptr->endereco.logradouro, "\n")] = '\0';

    printf("Número = ");
    scanf("%d", &ptr->endereco.numero);
    limparBuffer();

    printf("CEP = ");
    fgets(ptr->endereco.cep, 15, stdin);
    ptr->endereco.cep[strcspn(ptr->endereco.cep, "\n")] = '\0';

    printf("Cidade = ");
    fgets(ptr->endereco.cidade, STANDARD_CHAR, stdin);
    ptr->endereco.cidade[strcspn(ptr->endereco.cidade, "\n")] = '\0';

    printf("Estado (use a sigla) = ");
    fgets(ptr->endereco.estado, 3, stdin);
    ptr->endereco.estado[strcspn(ptr->endereco.estado, "\n")] = '\0';

    system("clear");

    printf("=== Dados cadastrados com sucesso! ===\n\n");

    printf("Nome: %s\n", ptr->nome);
    printf("Idade: %d\n", ptr->idade);
    printf("Instagram: %s\n", ptr->instagram);
    printf("Telefone: %s\n", ptr->telefone);

    printf("\n--- Endereco ---\n");
    printf("Logradouro: %s\n", ptr->endereco.logradouro);
    printf("Numero: %d\n", ptr->endereco.numero);
    printf("CEP: %s\n", ptr->endereco.cep);
    printf("Cidade: %s\n", ptr->endereco.cidade);
    printf("Estado: %s\n", ptr->endereco.estado);

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}