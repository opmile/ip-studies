# números pseudoaleatório com `rand()`
a função `rand()` é usada para gerar números pseudoaleatórios

você precisa incluir no cabeçalho:
```c
#include <stdlib.h> // para rand()e srand()
#include <time.h> // para time()
```

## usando `rand()`
```c
int resultado = rand(); // gera um número inteiro entre 0 e RAND_MAX
```
* `RAND_MAX` costuma ser 32767, mas pode variar por sistema
* sem configurar uma semente, os números serão sempre os mesmos toda vez que você rodar o programa (porque `rand()` é determinístico)

## configurando a semente com `srand()`
```c
srand(time(NULL)); // seed baseada no horário atual
```
* chame uma vez só no início do programa (normalmente no `main()`)
* isso faz o `rand()` gerar sequ"encias diferentes a cada execução

*e se quisessemos construir uma função que gere númros aleatórios? onde fica a configuração da seed?* ainda no `main()`!
* a função `srand(time(NULL))` define a semente do gerador de números aleatórios. chamas ela várias vezes seguidas, especialmente em um intervalo de tempo muito pequeno, o valor de `time(NULL)` provavelmente será o mesmo (segundos), e você acaba reiniciando a sequência pseudoaleatória do `rand()`
* garanta que `srand(time(NULL))` está no `main()`, para que `rand()` produza uma sequência diferente a cada execução

## gerar números em um intervalo específico
se quiser, por exemplo, um número entre 1 e 100:
```c
int numero = rand() % 100 + 1; // resultado entre 1 e 100
```
* `rand() % 100` dá um número entre 0 e 99
* `+1` ajusta pra `1` até `100`

**exemplo completo**
```c
#include <stdio.h> 
#include <stdlib.h> //  srand() e rand()
#include <time.h>

int generateRandomNumber() { // de 1 a 100
    return rand() % 100 + 1;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        printf("numero aleatorio: %d\n", generateRandomNumber());
    }

    return 0;
}
```

### intervalo `max` `min`
```c
int numero = rand() % (max - min + 1) + min;
```
1. **`rand() % (max - min + 1)`**
esse trecho gera um valor entre `0` e `(max - min)`

2. **`+ min`**
empurra esse intervalo para começar em `min`
* isso transfor o intervalo de `[0, max - min]` em `[min, max]`

3. **por que usamos *`+1`***
porque quando você faz `rand() % n`, o resultado vai de `0` até `n-1`, então se você quer incluir o valor máximo no intervalo, você precisa aumentar o alcance em 1. mas se lembre que ao mesmo tempo, estamos retirando o alcance do valor míninmo
* pra pegar de 0 a 10: `rand() % 11`
* pra pegar de 1 a 10: `rand() % 10 + 1`
* se fosse só `rand() % 10`, seria 0 a 9