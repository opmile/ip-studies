#include <stdio.h>

int main() {

    int var, *ptr1, **ptr2, ***ptr3;

    printf("var = ");
    scanf("%d", &var);

    ptr1 = &var;
    ptr2 = &ptr1;
    ptr3 = &ptr2;

    printf("DOBRO = %d\n", 2 * (**ptr2));
    printf("TRIPLO = %d\n", 3 * (***ptr3));
    printf("QUÁDRUPLO = %d\n", 4 * (***ptr3));

    return 0;
}