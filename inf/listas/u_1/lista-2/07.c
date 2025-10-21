#include <stdio.h>

int main() {
    float salario, novo_salario;

    printf("Digite o sálario do funcionário: R$ ");
    scanf("%f", &salario);

    if (salario < 1200.00) {
        novo_salario = salario * 1.30;
        printf("O funcionário tem direito ao aumento.\n");
        printf("Salário reajustado: R$ %.2f\n", novo_salario);
    } else {
        printf("O funcionário não tem direito ao aumento.\n");
    }

    return 0;
}