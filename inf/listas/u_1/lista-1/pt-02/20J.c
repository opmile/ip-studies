#include <stdio.h>
#include <math.h>

float functionJ(float a) {
    return (sinf(a) + cosf(a)) / tanf(a);
}

int main() {
    
    float a;

    printf("a = ");
    scanf("%f", &a);

    printf("J = %.2f\n", functionJ(a));

    return 0;
}
