# string
strings representam um conjunto de caracteres e, em c, são representadas como um array de caracteres do tipo `char`
```c
char greetings[] = "hello world";
```
* apesar da sintaxe de `char` pedir aspas simples, para strings, representamos sempre com aspas duplas

para a saída de dados de uma string, necessitamos de um novo especificador de formato `%s`
```c
char greetings[] = "hello world";
printf("%s", greetings);
```

## acesso por índice
como strings são na verdade arrays em c, podemos acessá-las nos referindo pelo índice
```c
char greetings[] = "Hello World!";
printf("%c", greetings[0]);
```
* note que como aqui queremos um único caractere, devemos usar o especificador de formato `%c`

para modificar strings, seguimos a mesma lógica de acesso por índice que já foi estudada no módulo de arrays
```c
char greetings[] = "hello world!";
greetings[0] = 'j';
printf("%s", greetings);
// outputs jello world! 
```

## iterando uma string
```c
char carName[] = "volvo";

int length = sizeof(carName) / sizeof(carName[0]);

for (int i = 0; i < length; i++) {
    printf("%c\n", carName[i]);
}
```

## outra forma de declaração
nos exemplos acima usamos *strings literais* para criar uma variável do tipo string, sendo essa a forma mais comum e fácil de criar string em c

também podemos criar uma string como um conjunto de caracteres. esse exemplo é equivalente aos exemplos anteriores
```c
char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
printf("%s", greetings);
```
*por que incluir `'\0'` ao final?*
esse caractere é conhecido como "null terminating character" e deve ser incluso quando declarando strings dessa forma
* seu objetivo é indicar o final da string para o compilador

a real diferença é que declarar string de forma literal é mais fácil, poupa tempo e não temos de nos preocupar com o caracter nulo, já que o c fará isso pra nós

também é imporante destacar que o tamanho de ambos os arrays é o mesmo: os dois possuem 13 caracteres

## caracteres especiais
porque strings devem ser escritas em aspas duplas, o seguinte exemplo aponta erro de compilação
```c
char txt[] = "We are the so-called "Vikings" from the north.";
```

a solução para esse problema é o uso do caractere especial **backslash escape character**
| escape character | result |  description  |
| ---------------- | ------ |  -----------  |
|        \'        |    '   |  single quote |
|        \"        |    "   |  double quote |
|        \\        |    \   |   backslash   |

* a sequência `\"` insere aspas duplas em uma string
```c
char txt[] = "we are the so-called \"Vikings\" from the north.";
```

* a sequência `\'` insere aspas simples em uma string
```c
char txt[] = "it\'s alright.";
```

* a sequência `\` insere um backslash em uma string
```c
char txt[] = "the character \\ is called backslash.";
```

outros caracteres especiais em c são:
1. `\n` - nova linha
2. `\t` - tab
3. `\0` - null

## métodos de strings
as funções de strings devem ser incluidas no cabeçalho do arquivo importando a lib <string.h>
```c
#include <string.h>
```

### string length
para retornar o comprimento da string, usamos a função `strlen()`
```c
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
printf("%zu", strlen(alphabet));
```

nos itens anteriores, usamos `sizeof()` para retornar o tamanho da string/array, mas note que `sizeof()` se comporta de forma diferente de `strlen()`, já que `sizeof()` também inclui o caracter nulo `\0` na contagem
```c
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
printf("%zu\n", strlen(alphabet));   // 26
printf("%zu\n", sizeof(alphabet));   // 27
```
* é importante lembrar que `sizeof` sempre retorna o tamanho em bytes que aquele dado ocupa na memória, e não de fato o tamanho da string
```c
char alphabet[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
printf("%zu\n", strlen(alphabet));   // 26
printf("%zu\n", sizeof(alphabet));   // 50
```

essa é uma armadilha clássica de c: use `strlen()` para iterar sobre strings
**`strlen()`**
* retorna o número de caracteres visíveis na string, sem contar o caractere nulo
* forma correta para strings, pois uma string em c é um array de `char` terminado com `\0`

**`sizeof()`**
* retorna o tamanho total em bytes da variável, não o número de caracteres da string
* se for um array de `char`, ele inclui `\0`
* se for um ponteiro (`char*`), vai retornar o tamanho do ponteiro (geralmente 8 bytes) - ou seja, nada de útil nesse caso

quando trabalhamos com strings grandes, é melhor declarar uma variável que armazena o tamanho da string do que usar `strlen(string)` dentro do loop for, isso porque a função será acionada e recalculada a cada iteração

### concatenate strings
para combinar duas strings usamos `strcat()`
```c
char *strcar(char *dest, const char *src);
```
* concatena a string `src` ao final da string `dest`, e retorna `dest`
* `dest` precisa ter espaço suficiente para comportar as duas strings juntas
* se quisermos combinar mais de duas strings, precisamos realizar múltiplas chamadas à função

```c
char frase[100] = ""; // precisa ter espaço sobrando

strcat(frase, "olá, ");
strcat(frase, "milena ");
strcat(frase, "dev");

printf("%s\n", frase);
```