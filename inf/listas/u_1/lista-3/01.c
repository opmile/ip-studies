#include <stdio.h>

void readProductId(int id) {
    if (id == 1) {
        printf("Sul\n");
    } else if (id == 2) {
        printf("Procedência: Norte\n");
    } else if (id == 3) {
        printf("Procedência: Leste\n");
    } else if (id == 4) {
        printf("Procedência: Oeste\n");
    } else if (id == 5 || id == 6) {
        printf("Procedência: Nordeste\n");
    } else if (id == 7 || id == 8 || id == 9) {
        printf("Procedência: Sudeste\n");
    } else if (id <= 20) {
        printf("Procedência: Centro-Oeste\n");
    } else if (id >= 25 && id <= 30) {
        printf("Procedência: Nordeste\n");
    } else {
        printf("IMPORTADO\n");
    }
}

int main() {
    float price;
    int id;


    printf("Preço do Produto: ");
    scanf("%f", &price);

    printf("ID do produto: ");
    scanf("%d", &id);

    readProductId(id);

    return 0;
}