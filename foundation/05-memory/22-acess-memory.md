# acesso à memória dinâmica
a **memória dinâmica se comporta como um array** criado em *tempo de execução* e com seu tipo de dado especificado pelo tipo do ponteiro
* assim como em arrays, para acessar um elemento na memória dinâmica, se refira a ele pelo seu número de índice
```c
ptr[0] = 12;
```
* você também pode desreferenciar o ponteiro para acessar seu primeiro elemento
```c
*ptr = 12;
```

a memória dinâmica se comporta como um array porque, ao usar `malloc` ou `calloc` para alocar um bloco de memória, você está criando **várias "caixinhas" de um certo tipo de dado**, lado a lado na memória
* e como o ponteiro indica qual é o tipo de dado apontado (por exemplo `int*`, `float*`, `struct Pessoa*`), o compilador calcula corretamente os endereços dos elementos seguintes - **exatamente como faz com um array**

ex) leia e escreva na memória dinâmica
```c
int *ptr;
ptr = calloc(4, sizeof(*ptr));

*ptr = 2;
ptr[1] = 4;
*(ptr + 2) = 6;

printf("%d\n", *ptr);
printf("%d %d %d", ptr[1], ptr[2], ptr[3]);
```

## uma nota sobre tipos de dados
a memória dinâmica *não possui seu próprio tipo de dado*, é apenas uma *sequência de bytes*. o dado na memória pode ser interpretado com base no tipo de dado do seu ponteiro
* nesse próximo exemplo, um ponteiro para 4 bytes pode ser interpretado como um elemento `int` (4 bytes) ou como um array de 4 `char` (1 byte cada)
```c
int *ptr1 = malloc(4);
char *ptr2 = (char*) ptr1; // type casting
ptr1[0] = 1684234849; // inteiro
printf("%d é %c %c %c %c", *ptr1, ptr2[0], ptr2[1], ptr2[2], ptr2[3]);
```

ex) inteiros alocados dinamicamente, acessados como array
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* vetor = malloc(5 * sizeof(int));

    if (vetor = NULL) {
        printf("erro ao alocar memória\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        vetor[i] = (i + 1) * 10; // acesso por index
    }

    for (int i = 0; i < 5; i++) {
        printf("vetor[%d]: %d\n", i, *(vetor + i));
    }

    free(vetor); // libera espaço
    
    return 0;
}
```

ex) alocando e acessando um array de structs dinamicamente
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    int qtd = 3;

    Pessoa* lista = malloc(qtd * sizeof(Pessoa));

    if (lista == NULL) {
        printf("erro ao alocar memória\n");
        return 1
    }

    strcpy(lista->nome, "milena");
    lista->idade = 19;

    strcpy((lista + 1)->nome, "miguel");
    (lista + 1)->idade = 20;

    strcpy(lista[2].nome, "joaozinho")
    lista[2].idade = 21;
}

```
* `lista->campo` === `(*lista).campo` === `lista[0].campo`

* `(lista + 1)->idade` != `*(lista + 1)->idade`
    * `lista + 1` → você anda para a próxima struct (ok).
    * `(lista + 1)->nome` → acessa o campo nome da segunda struct (ok).
    * `*(lista + 1)->nome` → aqui está o erro.

    * nome é um array de `char`, ou seja, `char nome[50]`
    * quando voce faz `(lista + 1)->nome`, isso tem tipo `char*` (porque arrays decaem para ponteiros)
    * se fizer `*` nesse ponteiro significa que você quer extrair o primeiro caractere da string
    * você estaria então passando um `char` como destino do `strcpy`, mas ele espera um ponteiro para `char`

a sacada aqui é perceber que o ponteiro `lista` é um ponteiro de struct, então pode ser usado para acessar seus membros usando `->`, e que ainda é um array que armazena structs do tipo `Pessoa`, então a aritmética de deslocamento de ponteiros também vale porque `lista` é um ponteiro que aponta para o primeiro elemento da lista de pessoas

