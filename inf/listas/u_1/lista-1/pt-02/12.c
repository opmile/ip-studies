#include <stdio.h>

void generateReport(float firstSaving, float secondSaving) {
    float totalAccumulated = firstSaving + secondSaving;

    printf("TOTAL ACUMULADO = %.2f\n", totalAccumulated);
    printf("-- PERCENTUAL DE PARTICIPAÇÃO -- \n");
    printf("1° SÓCIO = %2.f%%\n", (firstSaving / totalAccumulated) * 100);
    printf("2° SÓCIO = %2.f%%\n", (secondSaving / totalAccumulated) * 100);
}

int main() {

    float first = 0.00f, second = 0.00f;

    printf("ECONOMIA DO 1° SÓCIO = ");
    scanf("%f", &first);

    printf("ECONOMIA DO 2° SÓCIO = ");
    scanf("%f", &second);

    generateReport(first, second);
    
    return 0;
}