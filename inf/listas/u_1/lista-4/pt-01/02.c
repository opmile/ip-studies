#include <stdio.h>

void printResult() {
    int sum = 0;
    int count = 0;

    for (int i = 50; i <= 70; i++) {
        if (i % 2 == 0) {
            sum += i;
            count++;
        }
    }
    printf("Soma: %d\n", sum);
    
    float avg = (float) sum / count;
    printf("Média: %.2f\n", avg);
}

int main() {
    
    printResult();
    
    return 0;
}