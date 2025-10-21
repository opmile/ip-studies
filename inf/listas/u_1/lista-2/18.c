#include <stdio.h>
#include <math.h> // Para fabs()

int main() {
    int numero_conta;
    float limite_credito, saldo_inicial, total_depositos, total_retiradas, novo_saldo;

    printf("Número da conta: ");
    scanf("%d", &numero_conta);

    printf("Limite de credito: ");
    scanf("%f", &limite_credito);

    printf("Saldo no início do mês: ");
    scanf("%f", &saldo_inicial);

    printf("Total de depósitos: ");
    scanf("%f", &total_depositos);

    printf("Total de retiradas: ");
    scanf("%f", &total_retiradas);

    novo_saldo = saldo_inicial + total_depositos - total_retiradas; 

    if (novo_saldo < 0 && fabs(novo_saldo) > limite_credito) {
        float excedido = fabs(novo_saldo) - limite_credito;
        printf("\nConta: %d\n", numero_conta);
        printf("CRÉDITO EXCEDIDO EM %.2f reais.\n", excedido);
    } else {
         printf("\nConta: %d\n", numero_conta);
         printf("Situação de crédito regular.\n");
    }

    return 0;
}