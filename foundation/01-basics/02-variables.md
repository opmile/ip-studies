# variáveis em c
variáveis são container que armazeram dados, como números e caracteres. em c, existem diferentes tipos de dados:
- `int` - armazenam inteiros
- `float` - armazenam decimais (ponto flutuantes)
- `char` - armazenam caracteres: `'a'`, `'B'`. caracteris são envelopados em aspas simples

```c
type variableName = value;
```

existem duas formas de declarar variáveis: declarar e atribuir um valor, ou declarar e atribuir um valor depois
```c
int myNum = 15;

int myNewNum;
myNewNum = 20;
```

## imprimindo o valor de uma variável
ao contrário de muitas linguagens de programação, passar apenas a variável como argumento da função não realiza a impressão da mesma. é preciso usar os "format specifiers", que são basicamente os **placeholders** já conhecidos em outras linguagens.

esses especificadores de dados são usados dentro da função `printf()` para avisar ao compulador que tipo de dado a variável está carregando
- `int` -- `%d` ou `%i`
- `float` -- `%f` ou `%F`
- `char` -- `%c` 
- `double` -- `%lf`
- `string` -- `%s`

```c
int myNum = 15;

printf("valor: %d", myNum);
///

char myLetter = 'm';

printf("valor: %d, letra: %c", myNum, myLetter);

///
printf("valor: %d, letra: %c", 15, 'm') // sem variável
```

## características
* se você atribuir um novo valor para uma variável já existente no programa, ele irá sobrescrever o antigo valor
```c
int myNum = 15; //15
myNum = 20; // agora é 20
```

* podemos atribuir o valor de uma variável a outra
```c
int oldNum = 23;
int myNum = 15;

oldNum = myNum;

printf("%d", oldNum); // 15
```

* ou copiar valores para variáveis vazias
```c
int myNum = 15;
int myOtherNum;

myOtherNum = myNum;

printf("%d", myOtherNum); // 15
```

* podemos declarar múltiplas variáveis na mesma linha de declaração desde que compartilhem o mesmo tipo de dado, separando-as por uma vírgula
```c
int x = 5, y = 6, z = 50;
printf("%d", x + y + z);
```

* também podemos atribuir o mesmo valor a múltiplas variáveis que compartilham um mesmo tipo
```c
int x, y, z;
x = y = z = 50;
printf("%d", x + y + z);
```

*obs* o padrão de identificar variáveis em C é por `snake_case`

## constantes
se não queremos que o valor de uma variável seja alterado, precisamos usar a palavra-chave `const` no momento de declaração da variável
* usar `const` declara a variável como constante, que significa não modificável, apenas de leitura

```c
const int myNum = 15; // sempre 15
myNum = 10; // error: assignment of read-only variable 'myNum'
```

sempre declare variáveis como constantes quando sabemos que o valor armazenado é improvável de ser alterado
```c
const int minutesPerHour = 60;
```

* no caso de variáveis constantes, o momento de declaração deve vir sempre acompanhado do valor que a variável armazenará
```c
const int minutesPerHour = 60 // compila

const int minutesPerHour;
minutesPerHour = 60; // acusa erro de compilação
```

* é considerada uma boa prática de legibilidade de código declarar constantes em uppercase (todas as letras maiúsculas)
```c
const int BIRTHYEAR = 1980;
```