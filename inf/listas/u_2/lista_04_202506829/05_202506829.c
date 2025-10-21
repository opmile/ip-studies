#include <stdio.h>
#include <string.h>

#define CHAR_NUM 50
#define MAX 30

typedef struct {
    char name[CHAR_NUM];
    int code;
    float price;
    char category[CHAR_NUM];
} Product;

void cleanBuffer();
void showByCategory(Product *p, int len, char *filter);
void showByLessThan(const Product *p, int len, float value);
void showByGreaterThan(const Product *p, int len, float value);

int main() {
    char category[CHAR_NUM];
    float value = 0.00f;

    Product products[MAX];
    int len;

    printf("Insira a quantidades de produtos para a cadastrar: ");
    scanf("%d", &len);
    cleanBuffer();

    for (int i = 0; i < len; i++) {
        printf("\n---- Produto %d ----\n", i + 1);

        printf("NOME: ");
        fgets(products[i].name, CHAR_NUM, stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';

        printf("CÓDIGO: ");
        scanf("%d", &products[i].code);
        cleanBuffer();

        printf("PREÇO: ");
        scanf("%f", &products[i].price);
        cleanBuffer();

        printf("CATEGORIA: ");
        fgets(products[i].category, CHAR_NUM, stdin);
        products[i].category[strcspn(products[i].category, "\n")] = '\0';
    }

    int op = -1;
    do {
        printf("\n==== MENU ====\n");
        printf("1 - Exibir produtos de uma categoria\n");
        printf("2 - Exibir produtos com preço inferior a um valor\n");
        printf("2 - Exibir produtos com preço superior a um valor\n");
        printf("0 - Sair\n");

        scanf("%d", &op);
        cleanBuffer();

        switch (op) {
            case 1: 
                printf("Digite a categoria desejada: ");
                fgets(category, CHAR_NUM, stdin);
                category[strcspn(category, "\n")] = '\0';
                showByCategory(products, len, category);
                break;
            
            case 2:
                printf("Exibir produtos com preço inferior a: R$ ");
                scanf("%f", &value);
                showByLessThan(products, len, value);
                break;
            
            case 3:
                printf("Exibir produtos com preço superior a: R$ ");
                scanf("%f", &value);
                showByGreaterThan(products, len, value);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (op != 0);

    return 0;
}

void showByCategory(Product *p, int len, char *filter) {
    int found = 0;

    for (int i = 0; i < len; i++) {
        if (strcasecmp(p[i].category, filter) == 0) {
            printf("%s | %d | R$%.2f\n", p[i].name, p[i].code, p[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Nenhum produto encontrado da categoria");
    }
}

void showByLessThan(const Product *p, int len, float value) {
    int found = 0;
    for (int i = 0; i < len; i++) {
        if (p[i].price < value) {
            printf("%s | %d | %s | R$%.2f\n", p[i].name, p[i].code, p[i].category, p[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Nenhum produto encontrado com preço abaixo de R$ %.2f.\n", value);
    }
}

void showByGreaterThan(const Product *p, int len, float value) {
    int found = 0;
    for (int i = 0; i < len; i++) {
        if (p[i].price > value) {
            printf("%s | %d | %s | R$%.2f\n", p[i].name, p[i].code, p[i].category, p[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Nenhum produto encontrado com preço acima de R$ %.2f.\n", value);
    }
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}