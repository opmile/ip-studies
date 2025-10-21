// nao existe moeda de 50 centavos no padrao eua, mas fiquei sem nomes para continuar com o mesmo padrao de nomeclatura em ingles

#include <stdio.h>

float calculateTotalCoinSaving(int one, int fiftyCents, int quarter, int dime, int nickel) {
    return (one * 1) + (fiftyCents * 0.5) + (quarter * 0.25) + (dime * 0.1) + (nickel * 0.05);
}

int main() {

    int one, fiftyCents, quarter, dime, nickel;

    printf("DIGITE A QUANTIDADE DE CADA MOEDA\n");

    printf("MOEDAS DE R$ 1,00 = ");
    scanf("%d", &one);

    printf("MOEDAS DE R$ 0,50 = ");
    scanf("%d", &fiftyCents);

    printf("MOEDAS DE R$ 0,25 = ");
    scanf("%d", &quarter);

    printf("MOEDAS DE R$ 0,10 = ");
    scanf("%d", &dime);

    printf("MOEDAS DE R$ 0,05 = ");
    scanf("%d", &nickel);

    printf("TOTAL CALCULADO = R$ %.2f\n", 
        calculateTotalCoinSaving(one, fiftyCents, quarter, dime, nickel));

    return 0;
}