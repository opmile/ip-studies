#include <stdio.h>

void returnConcept(float avg) {
    if (avg < 5) {
        printf("D\n");
    } else if (avg < 7) {
        printf("C\n");
    } else if (avg < 8) {
        printf("B\n");
    } else {
        printf("A\n");
    }
}

int main() {
    float avg = 0.00f;

    printf("Digite a média final do aluno: ");
    scanf("%f", &avg);

    printf("Conceito: ");
    returnConcept(avg);

    return 0;
}