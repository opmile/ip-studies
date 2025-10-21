#include <stdio.h>

float calculateTotalWaterTax(float waterTax) {
    float sewerTax = waterTax * 0.8;
    return sewerTax + waterTax;
}

int main() {

    float waterTax;
    printf("TARIFA DE ÁGUA = R$ ");
    scanf("%f", &waterTax);

    printf("TOTAL A PAGAR = %.2f\n", calculateTotalWaterTax(waterTax));
    
    return 0;
}