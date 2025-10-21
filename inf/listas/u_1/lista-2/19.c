#include <stdio.h>

int main() {
    float vendas_brutas, salario_total;
    float salario_fixo = 500.00; 
    float comissao = 0.09; 
    
    printf("Digite o valor das vendas brutas da semana: R$ ");
    scanf("%f", &vendas_brutas);
    
    salario_total = salario_fixo + (vendas_brutas * comissao);
    
    if (vendas_brutas > 15000.00) {
        salario_total += 800.00;
    }
    
    printf("O salário total do vendedor eh: R$ %.2f\n", salario_total);
    
    return 0;
}