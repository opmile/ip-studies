#include <stdio.h>
#include <ctype.h>

int main() {
    float altura, peso_ideal;
    char sexo;

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    printf("Digite o sexo (M para masculino, F para feminino): ");
    // Adiciona um espaço antes de %c para consumir o 'enter' da leitura anterior
    scanf(" %c", &sexo);

    char insensitive_sexo = toupper(sexo);

    if (insensitive_sexo == 'M') {
        peso_ideal = (72.7 * altura) - 58;
        printf("Seu peso ideal eh: %.2f kg\n", peso_ideal);

    } else if (insensitive_sexo == 'F') {
        peso_ideal = (62.1 * altura) - 44.7;
        printf("Seu peso ideal eh: %.2f kg\n", peso_ideal);

    } else {
        printf("Sexo inválido. Use M ou F.\n");
    }

    return 0;
}