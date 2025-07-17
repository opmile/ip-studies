# dealocar (liberar) memória
quando você não precisa mais de um bloco de memória, você sempre dealocá-lo. dealocação também é referida como liberar (freeing) a memória

a memória dinâmica permanece reservada até a dealocação ou até o programa ser encerrado

uma vez que a memória é dealocada, ela pode ser usada por outros programas ou pode até ser alocada para outras partes do seu programa

## liberar memória
usamos a função `free()`
```c
free(pointer)
```
* o parâmetro `pointer` corresponde ao ponteiro que aponta para o endereço de memória a ser dealocado

```c
int *ptr;
ptr = malloc(sizeof(*ptr));

free(ptr);
ptr = NULL;
```
é considerada uma boa prática configurar o ponteiro para `NULL` depois de liberar o bloco de memória que ele apontava, para que você não possa acidentalmente continuar usando (corre risco *double free*)
* a memória apontada por `ptr` foi devolvida para o sistema
* mas o ponteiro `ptr` ainda guarda o endereço antigo na RAM
* ou seja, `ptr` é um ponteiro danificado (dangling pointer) - um endereço que você não deveria mais acessar
* `ptr = NULL` resolve esse problema porque agora o ponteiro aponta para nenhum lugar válido, e é capaz de remover o endereço "sujo"

```c
int main() {
    int *ptr;
    ptr = malloc(sizeof(*ptr));

    if (ptr == NULL) {
        printf("impossível alocar memória");
        return 1;
    }

    *ptr = 20;
    printf("%d\n", *ptr);

    free(ptr);
    ptr = NULL
    
    return 0;
}
```

mas se lembre: ponteiros são variáveis como qualquer outra, então você pode reaproveitá-los à vontade, desde que saiba o que está fazendo
```c
int *ptr = malloc(sizeof(int));
*ptr = 42;

printf("%d\n", *ptr); // 42

free(ptr); // libera a memória
ptr = NULL; // limpa o endereço antigo

// agora podemos reapontar
ptr = malloc(sizeof(int));

printf("%d\n", *ptr); // imprime 99
free(ptr);
ptr = NULL;
```
* `ptr` é uma variável do tipo ponteiro.
* `ptr = NULL` apenas zera o endereço (dizendo que ele não aponta pra nada por enquanto).
* depois, você faz `ptr = malloc(...)`, e ele passa a apontar para uma nova região válida.

*muito cuidado!*
* não use o ponteiro se ele não aponta para algo válido
```c
int *ptr = NULL;
*ptr = 5; // crash (segmentation fault)
```
porque `NULL` não é uma área de memória válida para escrita

## memory leak
um vazamento de memória acontece quando a **memória dinâmica é alocada mas nunca liberada**

se um vazamento de memória acontece em um loop ou em uma função chamada frequentemente, pode ocupar muito espaço desnecessário e causar lentidão

existe *risco de vazamento de memória se um ponteiro que aponta para memória dinâmica é perdido antes da memória ser liberada*. isso pode acontecer acidentalmente, então é importante ter cuidado e manter controle desse tipo de ponteiro

ex) *o ponteiro é sobrescrito*
```c
int *ptr;
ptr = calloc(2, sizeof(*ptr));

int x = 5;
ptr = &x;
```
* nesse exemplo, depois do ponteiro agora apontar para o endereço de `x`, a memória alocada por `calloc()` não pode mais ser acessada e é perdida

ex) *ponteiro que existe apenas dentro da função*
```c
void myFunction() {
    int *ptr;
    ptr = malloc(sizeof(*ptr));
}

int main() {
    myFunction();
    printf("a função terminou")
    return 0;
}
```
* nesse exemplo, a memória que foi alocada dentro da função permanece alocada depois do termino da função, mas não pode mais ser acessada. uma solução é liberar a memória antes do término da função

ex) o ponteiro se perde quando a realocação falha
```c
int* ptr;
ptr = malloc(sizeof(*ptr));
ptr = realloc(ptr, 2 * sizeof(*ptr));
```
* se `realloc()` não conseguir realocar memória propriamente, ela retornará um ponteiro para `NULL` e a memória original constinuará reservada
* nesse exemplo, se `realloc()` falhar então o ponteiro nulo é atribuido a `ptr`, sobrescrevendo o endereço de memória original e perdendo seu acesso

### sumário
quando gerenciando memória em C, use boas práticas
1. se lembre de checar por erros (valores de retorno `NULL`) para descobrir se a alocação de memória foi bem sucedida ou não
2. previna vazamentos de memória - sempre se lembre de liberar memória que não está sendo mais usada, ou seu programa pode perder performance ou pior, crashar se acabar a memória disponível
3. definir ponteiro para `NULL` depois de liberar espaço e não continuar usando endereço "lixo"