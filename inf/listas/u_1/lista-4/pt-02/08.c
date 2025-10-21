#include <stdio.h>

int main() {
    int soma = 0;
    for (int i = 1; i <= 20; i++) {
        printf("%d ", i);
        soma += i;
    }
    printf("\nSoma = %d\n", soma);
    return 0;
}
