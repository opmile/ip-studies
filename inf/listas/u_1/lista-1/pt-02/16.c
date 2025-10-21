#include <stdio.h>

void generateReport(int whiteVotes, int nullVotes, int validVotes) {
    int totalVoters = whiteVotes + nullVotes + validVotes;

    printf("-- RELATÓRIO DE PERCENTUAL DE ELEIORES--\n");
    printf("VOTOS BRANCOS = %.2f%%\n", ((float) whiteVotes / totalVoters) * 100);
    printf("VOTOS NULOS = %.2f%%\n", ((float) nullVotes / totalVoters) * 100);
    printf("VOTOS VÁLIDOS = %.2f%%\n", ((float) validVotes / totalVoters) * 100);
    printf("\n");
    printf("TOTAL DE ELEITORES NA COMPANHA = %d\n", totalVoters);
}

int main() {

    int whiteVotes = 0, nullVotes = 0, validVotes = 0;

    printf("VOTOS BRANCOS = ");
    scanf("%d", &whiteVotes);

    printf("VOTOS NULOS = ");
    scanf("%d", &nullVotes);

    printf("VOTOS VÁLIDOS = ");
    scanf("%d", &validVotes);

    generateReport(whiteVotes, nullVotes, validVotes);

    return 0;
}