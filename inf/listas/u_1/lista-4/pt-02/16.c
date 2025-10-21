#include <stdio.h>

int main() {
    int a, b, n, c;
    printf("Digite os dois primeiros termos: ");
    scanf("%d %d", &a, &b);
    printf("Digite N: ");
    scanf("%d", &n);

    printf("%d %d ", a, b);
    for (int i = 3; i <= n; i++) {
        if (i % 2 == 1) c = b + a;
        else c = b - a;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
