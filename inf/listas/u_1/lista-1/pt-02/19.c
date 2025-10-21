#include <stdio.h>
#include <math.h>

int main() {

    float one, two, three, four, five;

    printf("PRIMEIRO VALOR = ");
    scanf("%f", &one);

    printf("SEGUNDO VALOR = ");
    scanf("%f", &two);

    printf("TERCEIRO VALOR = ");
    scanf("%f", &three);

    printf("QUARTO VALOR = ");
    scanf("%f", &four);

    printf("QUINTO VALOR = ");
    scanf("%f", &five);

    printf("|%.2f| = %.2f\n", one, fabs(one));
    printf("|%.2f| = %.2f\n", two, fabs(two));
    printf("|%.2f| = %.2f\n", three, fabs(three));
    printf("|%.2f| = %.2f\n", four, fabs(four));
    printf("|%.2f| = %.2f\n", five, fabs(five));
    
    return 0;
}