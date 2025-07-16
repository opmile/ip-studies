# realocação de memória
se a quantidade de memória reservada não é suficiente, podemos realocar esse espaço para um maior.
* realocação reserva uma diferente (normalmente maior) quantidade de memória enquanto mantêm os dados já armazenados

você pode mudar o tamanho de memória alocado com `realloc()`, que aceita dois parâmetros
```c
int *ptr2 = realloc(ptr1, size);
```
* o primeiro parâmetro é o ponteiro que aponta para a memória a ser redimensionada
* o segundo parâmetro especifica um novo tamanho da alocação, medida em bytes

a função `realloc()` tenta redimensionar a memória em `ptr1` e retorna o mesmo endereço de memória apontada por esse ponteiro. se não for possível redimensionar a memória no endereço correspondente, então ela alocará memória em um endereço diferente e retornará o novo endereço

quando `relloc()` retorna um enderço de memória diferente, a memória no endereço original não é mais reservada e não é mais segura de ser usada
* quando realocação é feita é uma boa recomendação atribuir um novo ponteiro para a variável anterior, para que o antigo ponteiro não seja usado acidentalmente

```c
int *ptr1, *ptr2, size;

// alocando memoria para 4 inteiros
size = 4 * sizeof(*ptr1);
ptr1 = malloc(size);

printf("%d bytes alocados no endereço: %p \n", size, ptr1);

// redimensionando o espaço para armazenar 6 inteiros
size = 6 * sizeof(*ptr1);
ptr2 = realloc(ptr1, size);

printf("%d bytes alocados no endereço: %p \n", size, ptr2);
```

## NULL pointer & error checking
a função `realloc` retorna ponteiro `NULL` se não for possível alocar mais memória. acontecer isso é pouco provável, mas vale a pena manter em mente quando se precisa construit um código à prova de falhas
```c
int *ptr1, *ptr2;

ptr1 = malloc(4);

ptr2 = realloc(ptr1, 8);

if (ptr2 == NULL) {
    // se a realocação falhar
    printf("fail to reallocate memory");
} else {
    printf("success! 8 bytes reallocated at address %p \n", ptr2);
    ptr1 = ptr2; // update ptr1 to point to the newly allocated memory
}
```
* você sempre deve incluir a checagem de erros com `(if ptr == NULL)` quando alocando ou realocando memória
* você sempre deve liberar memória alocada depois de terminar de usá-la. isso é importante para garantir que o programa comporte de forma esperada, mas também o torna mais sustentável e eficiente
    * para liberar espaço use `free(ptr)`
