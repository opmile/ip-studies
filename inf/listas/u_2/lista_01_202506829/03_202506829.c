#include <stdio.h>

void checkCategory(int age) {
    if (age >= 5 && age <= 7) {
        printf("INFANTIL A\n");
    } else if (age >= 8 && age <= 10) {
        printf("INFANTIL B\n");
    } else if (age >= 11 && age <= 13) {
        printf("JUVENIL A\n");
    } else if (age >= 14 && age <= 17) {
        printf("JUVENIL B\n");
    } else {
        printf("ADULTO\n");
    }
}

int main() {
    int age = 0;

    printf("Digite a idade do nadador: ");
    scanf("%d", &age);

    printf("Categoria: ");
    checkCategory(age);

    return 0;
}