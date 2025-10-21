#include <stdio.h>
#include <math.h>

float functionH(float a, float b, float d) {
    return powf(a + b, d);
}

int main() {
    
    float a, b, d;

    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("d = ");
    scanf("%f", &d);

    printf("H = %.2f\n", functionH(a, b, d));

    return 0;
}
