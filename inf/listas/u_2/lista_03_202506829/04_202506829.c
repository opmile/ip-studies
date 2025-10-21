#include <stdio.h>
#include <string.h>

void printOddPositions(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (i % 2 != 0) {
            printf("%c", name[i]);
        }
    }
    printf("\n");
}

int main() {
    const char *name = "milena";
    printf("Nome: %s\n", name);

    printf("Caracteres nas posições ímpares: ");
    printOddPositions(name);

    return 0;
}