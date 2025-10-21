#include <stdio.h>

float function(float x) {
    return 2 * x + 4;
}

int main() {

    float x;

    printf("x = ");
    scanf("%f", &x);

    printf("x = %.2f\n", x);
    printf("f(x) = %.2f\n", function(x));

    return 0;
}