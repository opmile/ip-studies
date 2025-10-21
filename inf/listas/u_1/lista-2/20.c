#include <stdio.h>

int main() {
    float tempo_padrao, tempo_gasto, diferenca, pontos;
    int inscricao;

    printf("Digite o tempo padrão (minutos decimais): ");
    scanf("%f", &tempo_padrao);

    printf("Digite o número de inscrição da equipe: ");
    scanf("%d", &inscricao);

    printf("Digite o tempo gasto pela equipe (minutos decimais): ");
    scanf("%f", &tempo_gasto);

    diferenca = tempo_gasto - tempo_padrao;

    if (diferenca < 3) {
        pontos = 100;
    } else if (diferenca >= 3 && diferenca < 5) {
        pontos = 80;
    } else { 
        pontos = 80 - (diferenca - 5) / 5.0;
    }

    printf("\nEquipe: %d\n", inscricao);
    printf("Pontuacao: %.2f pontos\n", pontos);

    return 0;
}