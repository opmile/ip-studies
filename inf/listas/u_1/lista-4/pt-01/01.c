#include <stdio.h>

// a^b
// complexidade O(b)
int pot(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * pot(a, b - 1);
    }
}

/* 
* versão recursão básica (linear) - funciona, mas tem complexidade O(b) o que não se torna ineficiente para expoentes grandes

* otimização: exponentiation by squaring - reduz o número de chamadas para O(log b)
a^b = 
    * (a^(b/2)^2) se b for par
    * a * (a^((b-1)/2)^2 se b for ímpar
isso implica usar quadrado ao invés de multiplicação em cadeia, o que reduz o problema pela metade a cada chamada recursiva (log)

* a = 2, b = 5

otimizada:
2^5 = 2 * 2^2 * 2^2 = 2 * (2^2)^2 
     = 2 * (4)^2
     = 2 * 16 = 32

multiplicação em cadeia:
2^5 = 2 * 2 * 2 * 2 * 2
    = 4 * 2 * 2 * 2
    = 8 * 2 * 2
    = 16 * 2
    = 32

se b for par: a^b = (a^(b/2)) * (a^(b/2)) = (a^(b/2))²
2^6 = (2^3)^2 = 8^2 = 64

se b for ímpar: a^b = a * a^(b - 1) = a * (a^((b-1)/2))² ("quebramos" um a e deixamos o resto par)
2^5 = 2 * (2^2)^2 = 2 * (4)^2 = 2 * 16 = 32

*/

// complexidade O(b)
int potOt(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int half = potOt(a, (int) b / 2);

    if (b % 2 == 0) {
        return half * half;
    } else {
        return a * half * half;
    }
}

float potE(float a, float b) {
    float result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}


int main() {
    float a, b;
    // a^b

    printf("Insira a base: ");
    scanf("%f", &a);

    printf("Insira o expoente: ");
    scanf("%f", &b);

    printf("%.2f elevado a %.2f é %.2f\n", a, b, potE(a, b));
    
    return 0;
}
