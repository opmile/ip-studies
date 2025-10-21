#include <stdio.h>

// custo total da viagem (reais)
// ida e volta entre duas cidades
// ler L da gasl., distancia AB, autonomia (Km/L)

// distancia * autonomia = L total
// L total * precoPorLitro = totalGasto

int main() {
    float precoPorLitro, distanciaTotal, autonomia;

    printf("Informe o preço da gasolina: (R$/L) ");
    scanf("%f", &precoPorLitro);

    printf("Informe a distância entre as duas cidades: (Km) ");
    scanf("%f", &distanciaTotal);

    printf("Informe a autonomia do veículo: (Km/L) ");
    scanf("%f", &autonomia);

    float precoTotal = 2 * ((distanciaTotal / autonomia) * precoPorLitro);

    printf("A viagem custará R$%.2f\n", precoTotal);
}