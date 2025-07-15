# um array é um ponteiro?
em C, um array não é literalmente um ponteiros, mas se comporta como tal em várias sitações

```c
int arr[5] = {1, 2, 3, 4, 5};
```
* isso declara um bloco contínuo de memória para 5 inteiros
* o nome `arr` representa o endereço do seu primeiro elemento (`&arr[0]`)

ao usar `arr` em uma expressão (por exemplo, ao passar para uma função), **o nome do array decai para um ponteiro**
```c
void printArray(int *ptr, int size);

printArray(arr, 5); // aqui arr vira um ponteiro
```
* isso significa que `arr` se comporta como se fosse um `int *`

**por que o nome do array decai para um ponteiro?** porque em C, os parâmetros de função são passados por valor
```c
void foo(int arr[]) {...} // ou void foo(int *arr) {...}
```
significa que *não estamos passando o array inteiro*, mas uma *cópia do endereço do primeiro elemento*
```c
foo(arr);
// ==
foo(&arr[0]); // ou seja, um int *
```
isso economiza memória e tempo, porque copiar um array inteiro toda vez que você chama uma função seria custoso demais - principalmente em C, onde o controle é mais próximo do hardware


o compilador trata `int arr[]` em funções como um ponteiro para int, ou seja `int *arr`
essas duas assinaturas são equivalentes e aceitas:
```c
void foo(int arr[]);
void foo(int *arr);
```

**o que isso implica?**
o tamanho original do array se perde ao passá-lo em uma função
```c
void foo(int arr[]) {
    prinf("%lu\n", sizeof(arr)); // retorna o tamanho de um ponteiro
}
```
corrigir isso implica adicioanar como argumento o tamanho do array
```c
void foo(int arr[], int size);
```
