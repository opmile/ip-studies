#include <stdio.h>

int main() {
    int a, b;

    printf("Digite dois valores inteiros (A e B): ");
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("Nao é possível dividir por zero.\n");
        return 1;

    } else if (a % b == 0) {
        printf("%d é divisivel por %d.\n", a, b);

    } else {
        printf("%d nao é divisivel por %d.\n", a, b);

    }

    return 0;
}