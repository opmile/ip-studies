#include <stdio.h>

int revert(int number) {
    if (number < 100) {
        printf("formato CDU não especificado");
        return 1;
    }

    int c = number / 100;
    int d = (number / 10) % 10; // descarta e unidade e pega o resto da divisão
    int u = number % 10; // pega o ultimo digito de qualquer numero decimal

    return (u * 100) + (d * 10) + c; 
}

int main() {

    int number;
    printf("NUMERO = ");
    scanf("%d", &number);

    printf("INVERTIDO = %d\n", revert(number));
    
    return 0;
}