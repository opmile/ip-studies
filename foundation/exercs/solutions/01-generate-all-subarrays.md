# 01 - gere todos os subarrays
> *gere todos os subarrays possíveis de um array de inteiros e armazene-os em uma matriz*

a ideia aqui é:
* receber um array de inteiros
* gerar todos os subarrays possíveis (contíguos)
* armazenar cada subarray em uma matriz *jagged*, ou seja, um array de ponteiros para arrays de diferentes tamanhos
* alocar tudo dinamicamente com `malloc`
* usar `int **subarrays` como a matriz de subarrays

para um array de tamanho `n` existem `n * (n+1)/2` subarrays contíguos. por exemplo, se `n = 3`
```c
Array: [1, 2, 3]
Subarrays: [1], [1,2], [1,2,3], [2], [2,3], [3]
```

```c
void gerarSubarrays(int *array, int n, int ***subarrays, ... )
```
(aqui já travou... ponteiro para um ponteiro para um ponteiro de int?????? wtffff)

esse trecho significa que `subarrays` é um ponteiro ara um poneiro para um ponteoro de int, ou seja:
```
***subarrays → endereço de **subarrays → endereço de *subarrays → vetor de inteiros
```
**mas por que 3 níveis?**
1. **nós quereremos retornar um `int**`**
ou seja, no **main** teremos:
```c
int **subarrays;
```
esse `subarrays` será sua matriz jagged (um array de ponteiro para arrays de inteiros)

2. **para modificar esse `int **subarrays` dentro da função, você precisa passar o endereço dele**
simplesmente passar `subarrays` para a fun;'ao seria passar por valor, ou seja, uma cópia. você conseguiria modificar o conteúdo apontado por ele (os arrays de inteiros) mas não poderia fazer `malloc` nele e esperar que o `main` veja
então dentro da função você faz:
```c
*subarrays = malloc(...); // modifica o valor do **subarrays do main


```c
#include <stdio.h>
#include <stdlib.h>

void gerarSubarrays(int *array, int ***subarrays, int **tamanhos, int *total) {
    *total = n * (n + 1) / 2;

    //aloca o vetor de ponteiros para os subarrays
}