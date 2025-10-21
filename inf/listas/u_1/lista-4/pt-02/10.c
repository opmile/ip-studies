#include <stdio.h>

int fibonacci(int p); // 01
int fib(int n, int *memo); // 02

int main() {
    int n;
    printf("Digite N termos: ");
    scanf("%d", &n);

    int a = 0, b = 1, c;
    printf("%d %d ", a, b);

    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}

// usando recursividade

// comparativo com contagem de chamadas recursivas
int count;
int countOt;

int fibonacci(int p) { // 01
    count++;
    
    if (p == 1) {
        return 0;
    }
    if (p == 2) {
        return 1;
    }
    return fibonacci(p - 1) + fibonacci(p - 2);
}

/*
complexidade exponencial O(2^n)
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1)
│   │   │   └── fib(0)
│   │   └── fib(1)
│   └── fib(2)
│       ├── fib(1)
│       └── fib(0)
└── fib(3)
    ├── fib(2)
    │   ├── fib(1)
    │   └── fib(0)
    └── fib(1)
muitos termos se repetem! algoritmo recursivo ingênuo
*/

// usando programação dinâmica

int fib(int n, int *memo) { // 02 
    countOt++;

    if (memo[n] != -1) {
        return memo[n];
    } // se fib(n) já foi calculado, estará guardado

    // casos base
    if (n == 0) return memo[0] = 0;
    if (n == 1) return memo[1] = 1;

    // caso normal: fib(n) ainda não foi calculado
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}