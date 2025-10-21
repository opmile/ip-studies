#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 01 - usando qsort (internamente usa algoritmo Quick Sort)
int alphabeticCompare(const void* a, const void* b) {
    const char *str1 = *(const char**)a;
    const char *str2 = *(const char**)b;

    return strcmp(str1, str2);
}

// 02 - usando bubble sort (implementação manual de um algoritmo)
// implementação custosa! O(n^2)
void bubbleSort(char **names, int len) {
    // i - controla a quantidade de passadas; representa cada bubble up (maior elemento)
    for (int i = 0; i < len - 1; i++) {
        // j - controla a comparação e troca com elemento adjacente
        for (int j = 0; j < len - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char *temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
                // troca de ponteiros
            }
        }
    }
}

int main() {
    const char *nomes[] = {"alice", "milena", "bruna", "júlia", "giovana"};
    int len = sizeof(nomes) / sizeof(nomes[0]);

    qsort(nomes, len, sizeof(char*), alphabeticCompare);

    for (int i = 0; i < len; i++) {
        printf("%s", nomes[i]);
        if (i < len - 1) printf(", ");
    }
    printf("\n");

    return 0;
}