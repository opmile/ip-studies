#include <stdio.h>

float calculateTotalInvestedTime(float hours) {
    return hours * 60;
}

int main() {

    float hours = 0.00f;
    printf("TOTAL DE HORAS INVESTIDAS NA DISCIPLINA = ");
    scanf("%f", &hours);

    printf("TOTAL EM MINUTOS = %.2f", calculateTotalInvestedTime(hours));
}