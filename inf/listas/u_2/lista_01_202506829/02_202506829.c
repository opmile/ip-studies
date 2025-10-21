#include <stdio.h>

int checkIfPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n/2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return 0; // perfeito
    }
    return 1; // não é perfeito
}

int main() {

    int number;

    printf("Cheque se um número é perfeito\n");
    printf("Insira um número inteiro :");
    scanf("%d", &number);

    int result = checkIfPerfect(number);
    if (result == 0) {
        printf("O número é perfeito!\n");
    } else {
        printf("O número não é perfeito\n");
    }

    return 0;
}