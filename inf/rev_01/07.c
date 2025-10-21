#include <stdio.h>

// residencial - 1
// comercial - 0

int main() {

    int categoria;

    float consumoLitros = 0.0f, 
    consumoMetrosCubicos = 0.0f,
    tarifaEsgoto = 0.0f,
    totalTarifa = 0.0f;

    printf("Informe sua categoria:\n");
    printf("1 - Residencial\n");
    printf("2 - Comercial\n");
    scanf("%d", &categoria);

    printf("Informe o consume de água (L): ");
    scanf("%f", &consumoLitros);
    consumoMetrosCubicos = consumoLitros / 1000;

    tarifaEsgoto = consumoMetrosCubicos * 0.8;

    switch (categoria) {
        case 1:
            printf("RESIDENCIAL\n");
            totalTarifa = 25 + (0.45 * consumoMetrosCubicos) + tarifaEsgoto;
            printf("Total a pagar: R$%.2f\n", totalTarifa);
            break;
        
        case 2:
            printf("COMERCIAL\n");
            if (consumoMetrosCubicos <= 100) {
                totalTarifa = 250 + tarifaEsgoto;
            } else {
                totalTarifa = 100 + (1.35 * consumoMetrosCubicos) + tarifaEsgoto;
            }
            printf("Total a pagar: R$%.2f\n", totalTarifa);
            break;

        default:
            printf("Entrada de categoria inválida!\n");
            break;
    }
}