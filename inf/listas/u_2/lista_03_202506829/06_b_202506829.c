#include <stdio.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
    // unsigned char para caracteres fora do ASCII
}

int main() {

    char nome[] = "milena";
    toLowerCase(nome);
    printf("Maiusculo: %s\n", nome);

    return 0;
}