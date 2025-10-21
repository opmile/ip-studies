#include <stdio.h>

void totalDistance(float distanteKM) {
    printf("= %.2f Km\n", distanteKM);
    printf("= %.2f cm\n", 100000 * distanteKM);
}

int main() {
    
    float distanceKM;

    printf("DISTÂNCIA EM KM ENTRE AS DUAS UNIVERSIDADES = ");
    scanf("%f", &distanceKM);

    totalDistance(distanceKM);
    
    return 0;
}