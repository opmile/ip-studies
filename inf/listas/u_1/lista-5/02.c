#include <stdio.h>

int main() {

    int qtd = 0, id = 1;

    int tipoEtiqueta = 0;
    float precoOriginal = 0.00f, precoFinal = 0.00f;

    printf("=== Calculadora de Preços Black Friday ===\n");

    printf("Digite a quantidade de produtos de entrada: ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Digite o preço original do produto %d: ", id);
        scanf("%f", &precoOriginal);

        printf("Digite a etiqueta do produto %d:\n", id);
        printf("1 - Etiqueta normal\n");
        printf("2 - Etiqueta prata\n");
        printf("3 - Etiqueta dourada\n");
        scanf("%d", &tipoEtiqueta);

        precoFinal = precoOriginal * 0.9f;
        
        if (tipoEtiqueta == 2) {
            precoFinal -= precoOriginal * 0.2f;
        } else if (tipoEtiqueta == 3) {
            precoFinal -= precoOriginal * 0.3f;
        }
        
        if (precoFinal >= 100 && precoFinal <= 250) {
            precoFinal -= 10;
        } else if (precoFinal <= 500) {
            precoFinal -= 20;
        } else if (precoFinal > 500) {
            precoFinal -= 30;
        }
        
        printf("Preço original do produto %d: %.2f\n", id, precoOriginal);
        printf("Preço final produto %d: R$%.2f\n", id, precoFinal);

        id++;
    }
    return 0;
}