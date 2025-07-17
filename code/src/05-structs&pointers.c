#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
} Person;

void setName(Person *p, char *name);

void setAge(Person *p, int number);

int main() {
    Person p;

    int age;
    char name[100];

    printf("digite o nome: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0'; // limpa a entrada vinda do usuário

    printf("digite a idade: ");
    scanf("%d", age);
    
    setName(&p, name);
    setAge(&p, age);

    return 0;
}

void setName(Person *p, char *name) {
    strncpy(p->name, name, sizeof(p->name));
    p->name[sizeof(p->name) - 1] = '\0'; // garante o terminador nulo se a string for maior que a capacidade
}

void setAge(Person *p, int number) {
    p->age = number;
}
