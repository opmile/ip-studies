#include <stdio.h>
#include <string.h>

#define STANDARD_CHAR 50
#define MAX_CAPACITY 20

typedef struct {
    char nome[STANDARD_CHAR];
    int codigo;
    float preco;
    int qtdEstoque;
} Produto;

void limparBuffer();

int verificarDuplicado(const Produto* produtos, int n, int codigo);

void listarTodos(const Produto* produtos, int n);

void buscarPorNome(const Produto* produtos, int n, const char *nome);

int main() {

    int n = 0; // informa a capacidade de cadastros no vetor

    printf("=== CONTROLE DE ESTOQUE ==\n");

    do {
        printf("-- Insira a quantidade de produtos de cadastro: \n");
        scanf("%d", &n);
        limparBuffer();

        if (n > MAX_CAPACITY) {
            printf("Capacidaqde máxima de %d atingida!\n", MAX_CAPACITY);
        } else if (n <= 0) {
            printf("Número inválido!\n");
        }
    } while (n <= 0 || n > MAX_CAPACITY);

    Produto produtos[MAX_CAPACITY] = {
        {"", 0, 0.00f, 0}
    };

    char nome[STANDARD_CHAR];
    int codigo = 0, qtdEstoque = 0;
    float preco = 0.00f;

    int i = 0;
    while (i < n) {
        printf("======= CADASTRO: %d =======\n", i + 1);

        printf("NOME: ");
        fgets(nome, STANDARD_CHAR, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        do {
            printf("CODIGO: ");
            scanf("%d", &codigo);
            limparBuffer();

            if (verificarDuplicado(produtos, i, codigo)) {
                printf("Produto já cadastrado!\n");
            }
        } while (verificarDuplicado(produtos, i, codigo));

        printf("PREÇO: ");
        scanf("%f", &preco);
        limparBuffer();

        printf("QUANTIDADE EM ESTOQUE: ");
        scanf("%d", &qtdEstoque);
        limparBuffer();

        printf("============================\n");

        strcpy(produtos[i].nome, nome);
        produtos[i].codigo = codigo;
        produtos[i].preco = preco;
        produtos[i].qtdEstoque = qtdEstoque;
        
        i++;

        if (i == n) {
            printf("Estoque cheio!\n");
        }
    }


    int op = -1;
    do {
        printf("\n===== MENU ======\n");

        printf("1 -- Listar todos os cadastros\n");
        printf("2 -- Buscar por nome\n");
        printf("0 -- Sair\n");
        scanf("%d", &op);
        limparBuffer();

        switch (op) {
            case 1: 
                listarTodos(produtos, n);
                break;

            case 2: {
                char busca[STANDARD_CHAR];
                printf("Digite o nome de procura: ");
                fgets(busca, STANDARD_CHAR, stdin);
                busca[strcspn(busca, "\n")] = '\0';

                buscarPorNome(produtos, n, busca);
                break;
            }

            case 0:
                printf("Encerrando...\n");
                break;
            
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (op != 0);

    return 0;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int verificarDuplicado(const Produto* produtos, int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

void listarTodos(const Produto* produtos, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n===== PRODUTO %d =====\n", i + 1);
        printf("NOME = %s\n", produtos[i].nome);
        printf("ID = %d\n", produtos[i].codigo);
        printf("PREÇO = %.2f\n", produtos[i].preco);
        printf("ESTOQUE = %d\n", produtos[i].qtdEstoque);
    }
}

void buscarPorNome(const Produto* produtos, int n, const char *nome) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            printf("\n===== PRODUTO %d =====\n", i + 1);
            printf("NOME = %s\n", produtos[i].nome);
            printf("ID = %d\n", produtos[i].codigo);
            printf("PREÇO = %.2f\n", produtos[i].preco);
            printf("ESTOQUE = %d\n", produtos[i].qtdEstoque);
            encontrado = 1;
            
        } 
    }

    if (!encontrado) {
        printf("Nenhum produto com nome '%s' encontrado\n", nome);
    }
}