#include <stdio.h>

int main() {

    int a = 0, b = 0;

    scanf("%d %d", &a, &b);

    int *ptrA = &a;
    int *ptrB = &b;

    printf("ENDEREÇO A = %p\n", ptrA);
    printf("ENDEREÇO B = %p\n", ptrB);

    printf("MAIOR VALOR = %d\n", *ptrA > *ptrB ? *ptrA : *ptrB);

    return 0;
}