#include <stdio.h>

int main() {
    int n, soma = 0;
    printf("Digite N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("Soma de 1 a %d = %d\n", n, soma);
    return 0;
}

// usando recursividade

int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}