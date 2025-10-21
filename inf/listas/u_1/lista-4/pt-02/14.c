#include <stdio.h>

int main() {
    int n1, n2;
    printf("Digite N1 e N2: ");
    scanf("%d %d", &n1, &n2);

    for (int i = n1; i <= n2; i++) {
        int primo = 1;
        if (i < 2) primo = 0;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
