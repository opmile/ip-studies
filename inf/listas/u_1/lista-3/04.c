#include <stdio.h>

void readCode(int id) {
    if (id == 1) {
        printf("Cargo: Escrituário\n");
        printf("Percentual de Aumento: 50.00%%\n");
    } else if (id == 2) {
        printf("Cargo: Secretário\n");
        printf("Percentual de Aumento: 35.00%%\n");
    } else if (id == 3) {
        printf("Cargo: Caixa\n");
        printf("Percentual de Aumento: 20.00%%\n");
    } else if (id == 4) {
        printf("Cargo: Gerente\n");
        printf("Percentual de Aumento: 10.00%%\n");
    } else if (id == 5) {
        printf("Sem direito de aumento\n");
    }
}

int main() {
    int id;

    printf("Digite o código do funcionário: ");
    scanf("%d", &id);

    readCode(id);

    return 0;
}