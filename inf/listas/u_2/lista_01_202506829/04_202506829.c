#include <stdio.h>

int checkParity(int n) {
    if (n % 2 == 0) {
        return 0;
    }
    return 1;
}

int main() {
    int number;

    printf("Digite um número para checar sua paridade: ");
    scanf("%d", &number);

    int result = checkParity(number);
    if (result == 0) {
        printf("O número é par\n");
    } else {
        printf("O número é ímpar\n");
    }

    return 0;
}