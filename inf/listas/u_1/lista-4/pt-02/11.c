#include <stdio.h>

int main() {
    int n;
    int fat = 1;

    printf("Digite um número: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Número inválido!\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        fat *= i;
    }

    printf("Fatorial de %d = %d\n", n, fat);
    return 0;
}

// usando recursividade

int fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}