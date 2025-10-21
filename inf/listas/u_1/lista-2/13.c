#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x, fx;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        fx = fabs(x);
    } else if (x > 0 && x <= 10) {
        fx = pow(x, 2);
    } else { // x > 10
        fx = sqrt(x);
    }

    printf("f(%.2f) = %.2f\n", x, fx);

    return 0;
}