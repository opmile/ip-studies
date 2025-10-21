#include <stdio.h>
#include <ctype.h>

void toUpperCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char) str[i]);
    }
    // unsigned char para caracteres fora do ASCII
}

int main() {

    char nome[] = "Milena";
    toUpperCase(nome);
    printf("Maiusculo: %s\n", nome);

    return 0;
}