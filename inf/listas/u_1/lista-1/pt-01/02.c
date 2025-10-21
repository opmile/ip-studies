#include <stdio.h>

float calculateRetangularVolume(float length, float height, float width) {
    return length * height * width;
}

int main() {
    
    float length, height, width;

    printf("COMPRIMENTO: ");
    scanf("%f", &length);

    printf("ALTURA: ");
    scanf("%f", &height);

    printf("LARGURA: ");
    scanf("%f", &width);

    printf("VOLUME TOTAL = %.2f\n", calculateRetangularVolume(length, height, width));
    
    return 0;
}