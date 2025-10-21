#include <stdio.h>

#define CHIP_RING 4.00
#define FOOD_RING 3.50

float calculateTotal(int totalChicken) {
    return (float) (FOOD_RING + CHIP_RING) * totalChicken;
}

int main() {

    int totalChicken = 0;
    printf("TOTAL DE FRANGOS NA GRANJA = ");
    scanf("%d", &totalChicken);

    printf("TOTAL GASTO PARA AUTOMAÇÃO = R$ %.2f\n", calculateTotal(totalChicken));

    return 0;
}