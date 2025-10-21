#include <ctype.h>
#include <stdio.h>

int main() {
    char charset;
    int isValid = 0;

    printf("Digite um caracter: ");
    scanf("%c", &charset);

    if (charset == 'A' || charset == 'E' || charset == 'I' || charset == 'O' || charset == 'U') {
        printf("Vogal Maiúscula\n");
        isValid = 1;
    }

    if (charset >= '0' && charset <= '9') {
        printf("Número inteiro de 0 a 9\n");
        isValid = 1;
    }

    if (charset == '+' || charset == '-' || charset == '*' || charset == '/') {
        printf("Operador aritmético\n");
        isValid = 1;
    }

    if (!isValid) {
        printf("Caracter inválido!\n");
    }


    return 0;
}