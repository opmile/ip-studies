#include <stdio.h>
#include <string.h>

int main() {

    char string[] = "milena";

    int length1 = sizeof(string) / sizeof(string[0]);
    printf("%d\n", length1);

    int length2 = strlen(string);
    printf("%d\n", length2);

    for (int i = 0; i < length1; i++) {
        printf("%c\n", string[i]);
    }

    printf("-------\n");

    for (int i = 0; i < length2; i++) {
        printf("%c\n", string[i]);
    }

    return 0;
}