#include <stdio.h>

int main() {
    float precoCombustivel = 0.0f, consumoMedio = 0.0f;
    float distInicio = 0.0f, distFim = 0.0f;
    float pedagio = 0.0f;
    float gastoCombustivel = 0.0f, gastoPedagio = 0.0f, gastoTotal = 0.0f;
    float kmTotal = 0.0f;
    int opcao = 0;
    int tipo = 0; // 1 - Gasolina, 2 - Etanol, 3 - Diesel

    printf("=== Calculadora de Gastos de Viagem ===\n");

    printf("Digite o preço do litro de combustível: ");
    scanf("%f", &precoCombustivel);

    printf("Digite o consumo médio do veículo (km por litro): ");
    scanf("%f", &consumoMedio);

    printf("Qual o tipo de combustível usado?\n");
    printf("1 - Gasolina\n");
    printf("2 - Etanol\n");
    printf("3 - Diesel\n");
    scanf("%d", &tipo);

    do {
        printf("\nDigite a distância inicial do percurso (km): ");
        scanf("%f", &distInicio);
        printf("Digite a distância final do percurso (km): ");
        scanf("%f", &distFim);

        float distanciaPercurso = distFim - distInicio;

        // ida e volta
        kmTotal += distanciaPercurso * 2;

        // combustível gasto nesse percurso
        float litros = distanciaPercurso / consumoMedio;
        float custoComb = litros * precoCombustivel;
        gastoCombustivel += custoComb;
        gastoTotal += custoComb;

        // pedágio
        printf("Digite o valor do pedágio nesse percurso (0 se não houver): ");
        scanf("%f", &pedagio);
        gastoPedagio += pedagio;
        gastoTotal += pedagio;

        printf("Deseja adicionar outro percurso?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
        scanf("%d", &opcao);

    } while (opcao != 0);

    // relatório final
    printf("\n===== RELATÓRIO FINAL =====\n");
    printf("Quilômetros totais percorridos (ida e volta): %.2f km\n", kmTotal);
    printf("Total gasto com combustível: R$ %.2f\n", gastoCombustivel);
    printf("Total gasto com pedágio: R$ %.2f\n", gastoPedagio);
    printf("Gasto total da viagem: R$ %.2f\n", gastoTotal);

    if (tipo == 1) {
        printf("Tipo de combustível usado: Gasolina\n");
    } else if (tipo == 2) {
        printf("Tipo de combustível usado: Etanol\n");
    } else if (tipo == 3) {
        printf("Tipo de combustível usado: Diesel\n");
    } else {
        printf("Tipo de combustível usado: Não informado corretamente\n");
    }

    return 0;
}
