// 1 kW = 1/5 do minSalary
#include <stdio.h>

void generateTaxPowerReport(float minSalary, float totalKW) {
    float kW = minSalary / 5;
    float totalDue = kW * totalKW;
    float totalWithDiscount = totalDue * 0.85;

    printf("-- RELATÓRIO DE IMPOSTO DE ENERGIA --\n");
    printf("kW = R$ %.2f\n", kW);
    printf("TOTAL DEVIDO = R$ %.2f\n", totalDue);
    printf("TOTAL COM DESCONTO = R$ %.2f\n", totalWithDiscount);
}

const char message[] = "Erro: entrada inválida";

int main() {

    float minSalary = 0.00f, totalKW = 0.00f;
    
    printf("SALÁRIO MÍNIMO = R$ ");
    if (scanf("%f", &minSalary) != 1) {
        printf("%s", message);
    }

    printf("TOTAL DE ENERGIA CONSUMIDA (kW) = ");
    scanf("%f", &totalKW);
    
    generateTaxPowerReport(minSalary, totalKW);

    return 0;
}
