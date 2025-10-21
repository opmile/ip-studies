#include <stdio.h>
#include <string.h>

#define CHAR 50

void check(char *str1, char *str2);

int main() {

    printf("Primeira string: ");
    char str1[CHAR];
    fgets(str1, CHAR, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Segunda string: ");
    char str2[CHAR];
    fgets(str2, CHAR, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    check(str1, str2);

    return 0;
}

void check(char *str1, char *str2) {
    if (strcmp(str1, str2) == 0) {
        printf("STRINGS IGUAIS\n");
    } else {
        printf("%s\n", strcat(str1, str2));
    }   
}



