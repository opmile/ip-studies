#include <stdio.h>

float calculateAvgSalary(float minSalary, float salary) {
    return salary / minSalary;
}

int main() {
    
    float minSalary = 0.00f, salary = 0.00f;
    
    printf("SALÁRIO MÍNIMO: ");
    scanf("%f", &minSalary);

    printf("SALÁRIO DO FUNCIONÁRIO: ");
    scanf("%f", &salary);

    printf("SALÁRIO DO FUNCIONÁRIO: R$ %.2f\n", salary);
    printf("SALÁRIO MÍNIMO: R$ %.2f\n", minSalary);
    printf("EQUIVALENTE A %.2f SALÁRIOS MÍNIMOS\n", 
        calculateAvgSalary(minSalary, salary));

}