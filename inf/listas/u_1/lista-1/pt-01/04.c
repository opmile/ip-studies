#include <stdio.h>

float calculateReadjustment(float salary, float percentReadjustment) {
    return salary + (salary * percentReadjustment);
}

int main() {

    float salary, percentReadjustment;
    
    printf("SALÁRIO = R$ ");
    scanf("%f", &salary);

    printf("PERCENTUAL DE REAJUSTE = ");
    scanf("%f", &percentReadjustment);

    printf("\n");

    printf("SALÁRIO ATUAL = R$ %.2f\n", salary);
    printf("NOVO SALÁRIO = R$ %.2f\n", 
        calculateReadjustment(salary, percentReadjustment));

    return 0;
}