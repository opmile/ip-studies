#include <stdio.h>
#include <stdlib.h> // Para abs()

int main() {
    int h1, m1, h2, m2;
    int total_minutos1, total_minutos2, diferenca_minutos;
    int res_h, res_m;

    printf("Digite o instante inicial (hh mm): ");
    scanf("%d %d", &h1, &m1);
    printf("Digite o instante final (hh mm): ");
    scanf("%d %d", &h2, &m2);

    // Converte tudo para minutos
    total_minutos1 = h1 * 60 + m1;
    total_minutos2 = h2 * 60 + m2;
    
    // Calcula a diferença
    diferenca_minutos = abs(total_minutos2 - total_minutos1);
    
    // Converte a diferença de volta para horas e minutos
    res_h = diferenca_minutos / 60;
    res_m = diferenca_minutos % 60;
    
    printf("O intervalo de tempo decorrido foi de %d hora(s) e %d minuto(s).\n", res_h, res_m);
    
    return 0;
}