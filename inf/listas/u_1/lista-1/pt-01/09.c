#include <stdio.h>

float calculateAvg(float firstGrade, float secondGrade) {
    return ((firstGrade * 4) + (secondGrade * 6)) / 10;
}

int main() {
    
    float first, second;
    
    printf("DIGITE A PRIMEIRA NOTA = ");
    scanf("%f", &first);

    printf("DIGITE A SEGUNDA NOTA = ");
    scanf("%f", &second);

    printf("MÉDIA DO ALUNO = %.2f\n", calculateAvg(first, second));


    return 0;
}