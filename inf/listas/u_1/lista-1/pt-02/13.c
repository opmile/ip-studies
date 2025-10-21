#include <stdio.h>

void generateReport(float totalIncome) {
    printf("10%% SAÚDE = %.2f\n", 0.1 * totalIncome);
    printf("25%% EDUCAÇÃO = %.2f\n", 0.25 * totalIncome);
    printf("30%% ALIMENTAÇÃO = %.2f\n", 0.3 * totalIncome);
    printf("10%% VESTURÁRIO = %.2f\n", 0.1 * totalIncome);
    printf("5%% LAZER = %.2f\n", 0.05 * totalIncome);
    printf("20%% OUTROS = %.2f\n", 0.2 * totalIncome);
}

int main() {

    float totalIncome = 0.00f;

    printf("RENDA MENSAL = R$ ");
    scanf("%f", &totalIncome);

    generateReport(totalIncome);
}