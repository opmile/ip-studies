# ponteiros
um ponteiro é uma **variável que armazena o endereço de memória de outra variável**.

uma variável ponteiro aponta para um tipo de dado (como `int`) do mesmo tipo, e é criada usando o operador `*`

```c
int myAge = 19;
int* ptr = &myAge;

printf("%d\n", myAge); // 19
printf("%p\n", &myAge); // (0x7ffe5367e044)
printf("%p\n", ptr); // (0x7ffe5367e044)
```
no exemplo acima, criamos uma variável `ptr` que aponta para uma variável `int` (`myAge`)
* note também que o tipo de dado do ponteiro deve ser bater com o tipo de dado da variável que estamos trabalhando (`int`, no nosso exemplo)

## desreferenciação
além de guardar o endereço de memória de uma variável, podemos usar o ponteiro para obter o valor que ela aponta
* usamos o operador de desreferencia `*`

```c
int myAge = 19;
int* ptr = &myAge;

// referência: imprime o endereço de memória de myAge com o ponteiro
printf("%p\n", ptr);

// desreferência: imprime o valor de myAge com o ponteiro
printf("%d\n", *ptr);
```

*explorando um pouco melhor os tipos de uso do operador `*`*:
1. usado na declaração de ponteiros (`int* pointer`)
2. quando não usado na declaração, age como um *operdor de desreferenciação*

*obs*: existem duas formas de declarar ponteiros em C
```c
int* myNum;
int *myNum;
```

se você está familiarizado com estruturas de dados como listas, árvores e grafos, saiba que ponteiros são especialmente úteis para sua implementação. mas muitas vezes, você ainda usará ponteiros para, por exemplo, trabalhar com arquivos e gerenciamento da memória

*tenha cuidado!*; ponteiros devem ser usados com cuidado. é possível corromper dados armazenados em outros endereços de memória

## ponteiros e arrays
também podemos usar ponteiros para acessar arrays

dado o array de inteiros a seguir, vamos imprimir o endereço de memória de cada elemento do array
```c
int myNumbers[4] = {25, 50, 75, 100};

for (int i = 0; i < 4; i++) {
    printf("%p\n", &myNumbers[i]);
}
```
obteremos mais ou menos o seguinte resultado (pode ser que não seja exatamente igual ao seu):
```
0x7ffe70f9d8f0
0x7ffe70f9d8f4
0x7ffe70f9d8f8
0x7ffe70f9d8fc
```

note que temos uma sutil diferença apenas no último dígito do endereço de memória dos elementos, com incremento de 4. isso porque o tamanho de um `int` é de 4 bytes
* o compilador reserva 4 bytes de memória para cada elemento do array. o que significa que o array inteiro ocupa 16 bytes (4 * 4) de memória

### como ponteiros estão relacionados com arrays
em C, o **nome de um array é na verdade um ponteiro para o primeiro elemento do array**
* o nome do array corresponde ao endereço de memória de seu primeiro elemento 

podemos provar esse argumento fazendo algo que até então não tinhamos tentado: passar o nome do array como argumento para `printf()`
```c
int myNumbers[4] = {25, 50, 75, 100};

// obtem o endereço de memória do array myNumbers[0]
printf("%p\n", myNumbers);

// obtem o endereço de memória do primeiro elemento do array
printf("%p\n", &myNumbers[0]);
```
o resultado será
```
0x7ffe70f9d8f0
0x7ffe70f9d8f0
```
* isso significa que podemos trabalhar com arrays através de ponteiros.
* já que `myNumbers` é um ponteiro para o primeiro elemento de `myNumbers`, podemos usar o operador `*` para dereferenciação e acessar o valor que ele aponta
```c
int myNumbers[4] = {25, 50, 75, 100};

printf("%d", *myNumbers); // 25
```

é possível acessar o resto dos elementos incrementando o ponteiro/array (+1, +2, etc.)
```c
int myNumbers[4] = {25, 50, 75, 100};

// retorna o valor do elemento na segunda posição
printf("%d\n", *(myNumbers + 1));

// retorna o valor do elemento da terceira posição
printf("%d\n", *(myNumbers + 2))
```

também podemos aplicar o mesmo raciocínio para iterar em um loop
```c
int myNumbers[4] = {25, 50, 75, 100};

int *ptr = myNumbers;

for (int i = 0; i < 4; i++) {
    printf("%d\n", *(ptr + i));
}
```

se quisermos mudar o valor de um elemento do array usando ponteiros:
```c
int myNumbers[4] = {25, 50, 75, 100};

*myNumbers = 13; // altera o valor do primeiro elemento para 13

*(myNumbers + 1) = 17; // altera o valor do segundo elemento para 17
```

pode parecer exagerado usar ponteiros para manipular arrays, principalmente nesse array simples que usamos nos exemplos acima. mas para arrays maiores, trabalhar com ponteiros se torna a manipulação mais eficiente
* também é considerado mais rápido e prático para arrays bidimensionais
* como strings também são arrays, podemos usar ponteiros para acessar strings

*recapitulando...*
se `arr` por si só é um ponteiro para o primeiro elemento
```c
arr == &arr[0];
```
então acessar um elemento com ponteiro é equivalente a 
```c
arr[i] = *(arr + 1);
```
* todo acesso a array por índice é, internamente, ponteiro + deslocamento

```c
char nome[] = "milena";
// nome é um char* para o primeiro caractere, ou seja
char* ptr = nome;
```