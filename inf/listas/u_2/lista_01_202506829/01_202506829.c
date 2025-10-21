#include <math.h>
#include <stdio.h>

#define PI 3.14

float calculateEsfericVolume(float radius);

int main() {
    int op = -1;
    float radius = 0.00f;

    printf(" = Calculadora de Volume Esférico = \n");

    printf("Digite quantos volumes deseja calcular: ");
    scanf("%d", &op);

    for (int i = 0; i < op; i++) {

        printf("\nInsira o valor do raio %d (m): ", i + 1);
        scanf("%f", &radius);

        printf("\nVolume %d calculado: %.2f m^3\n", i + 1, calculateEsfericVolume(radius));
    }
    
    return 0;
}

float calculateEsfericVolume(float radius) {
    return (4 * PI * powf(radius, 3)) / 3;
}