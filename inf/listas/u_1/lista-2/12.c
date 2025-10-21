#include <stdio.h>

int main() {
    int idade;

    printf("Digite a idade: ");
    scanf("%d", &idade);

    if (idade > 18) {
        printf("MAIOR\n"); 
    } else if (idade >= 16) { 
        printf("EMANCIPADO\n"); 
    } else { 
        printf("MENOR\n"); 
    }

    return 0;
}