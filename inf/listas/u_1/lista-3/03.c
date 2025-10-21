#include <stdio.h>

void printfCategory(int age) {
    if (age >= 5 && age <= 7) {
        printf("Categoria: INFANTIL A\n");
    } else if (age >= 8 && age <= 10) {
        printf("Categoria: INFANTIL B\n");
    } else if (age >= 11 && age <= 13) {
        printf("Categoria: JUVENIL A\n");
    } else if (age >= 14 && age <= 17) {
        printf("Categoria JUVENIL B\n");
    } else {
        printf("Não se enquadra em nenhuma das categorias!\n");
    }
}

int main() {
    int age;

    printf("Digite a idade: ");
    scanf("%d", &age);

    printfCategory(age);
    
    return 0;
}