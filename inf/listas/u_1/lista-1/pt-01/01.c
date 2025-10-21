#include <stdio.h>

#define DOLAR 5.42

float convert(float savings) {
    return savings * DOLAR;
}

int main() {
    
    float savings;
    printf("ECONOMIAS ($): ");
    scanf("%f", &savings);

    printf("TOTAL ACUMULADO (R$): %.2f\n", convert(savings));

    return 0;
}