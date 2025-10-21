#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_NUM 50

typedef struct {
    int cep;
    int number;
    char publicPlace[CHAR_NUM];
    char neighborhood[CHAR_NUM];
    char complement[CHAR_NUM];
    char city[CHAR_NUM];
    char state[CHAR_NUM];
} Address;

typedef struct {
    char fullName[CHAR_NUM];
    int age;
    Address a;
} Person;

void cleanBuffer();
void showData(const Person *p);

int main() {
    char fullName[CHAR_NUM], publicPlace[CHAR_NUM], neighborhood[CHAR_NUM], complement[CHAR_NUM], city[CHAR_NUM], state[CHAR_NUM];
    int age = 0, cep = 0, number = 0;

    printf("Preencha os dados pessoais:\n");

    printf("Nome completo: ");
    fgets(fullName, CHAR_NUM, stdin);
    fullName[strcspn(fullName, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &age);
    cleanBuffer();
    if (age < 0 || age > 120) {
        printf("Idade inválida!\n");
        exit(1);
    }

    printf("Preencha os dados de endereço:\n");

    printf("Logradouro: ");
    fgets(publicPlace, CHAR_NUM, stdin);
    publicPlace[strcspn(publicPlace, "\n")] = '\0';

    printf("Número: ");
    scanf("%d", &number);
    cleanBuffer();

    printf("Bairro: ");
    fgets(neighborhood, CHAR_NUM, stdin);
    neighborhood[strcspn(neighborhood, "\n")] = '\0';

    printf("Complemento: ");
    fgets(complement, CHAR_NUM, stdin);
    complement[strcspn(complement, "\n")] = '\0';

    printf("CEP (apenas números): ");
    scanf("%d", &cep);
    cleanBuffer();

    printf("Cidade: ");
    fgets(city, CHAR_NUM, stdin);
    city[strcspn(city, "\n")] = '\0';

    printf("Estado: ");
    fgets(state, CHAR_NUM, stdin);
    state[strcspn(state, "\n")] = '\0';

    Person p;
    strcpy(p.fullName, fullName);
    p.age = age;

    Address a;
    a.cep = cep;
    a.number = number;
    strcpy(a.publicPlace, publicPlace);
    strcpy(a.neighborhood, neighborhood);
    strcpy(a.complement, complement);
    strcpy(a.city, city);
    strcpy(a.state, state);

    p.a = a;
    showData(&p);

    return 0;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void showData(const Person *p) {
    printf("Pessoa cadastrada: \n");
    
    printf("%s\n", p->fullName);
    printf("%d anos\n", p->age);
    
    printf("Endereço: \n");
    printf("%s, %d\n", p->a.publicPlace, p->a.number);
    printf("%s\n", p->a.neighborhood);
    printf("%s\n", p->a.complement);
    printf("%d\n", p->a.cep);
    printf("%s - %s\n", p->a.city, p->a.state);
}