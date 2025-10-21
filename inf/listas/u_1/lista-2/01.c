#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2;

    printf("Digite os coeficientes (A, B e C): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("Nao é equacao do segundo grau\n"); // [cite: 23]
    } else {
        delta = (powf(b, 2)) - (4 * a * c);

        if (delta < 0) {
            printf("Nao há raizes reais\n"); 
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("As duas raízes sao: x1 = %.2f e x2 = %.2f\n", x1, x2); 
        }
    }

    return 0;
}