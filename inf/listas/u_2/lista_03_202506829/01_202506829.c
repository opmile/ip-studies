#include <stdio.h>
#include <string.h>

#define PASSWORD "p123"

#define N_CARACTERS 50

int validatePassword(const char *str);

int main() {

    char password[N_CARACTERS];

    printf("Insira sua senha: ");
    fgets(password,N_CARACTERS, stdin);
    password[strcspn(password, "\n")] = '\0';

    if (validatePassword(password) == 0) {
        printf("Senha incorreta\n");
    }

    return 0;
}

int validatePassword(const char *str) {
    if (strcmp(str, PASSWORD) == 0) {
        printf("Validação bem-sucedida\n");
        return 1;
    }
    return 0;
}