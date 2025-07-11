# user input
vamos diferenciar entrada e saída de dados 

**saídas são *escritas* porque:**
estamos enviando dados do programa para fora
quando o programa imprime algo na tela, ele escreve no console - ou seja, sai do programa
* `printf()` é o método usado para saída de dados com sua escrita no console

**entradas são leituras porque:**
estamos recebendo dados de fora para dentro do programa
quando o usuário entra com dados no teclado, o programa lê - entra no sistema
* `scanf()` é o método usado para entrada de dados com sua leitura no console

```c
// variável que armazenará a leitura do número recebido pelo usuário
int myNum;

printf("digite um número: \n");

// recebe e salvar o número que o usuário registrou
scanf("%d", &myNum);

// escrever o número digitado no console
printf("you number is: %d\n", myN);
```

a função `scanf()` recebe dois argumentos: o especificador de formato e a referência da variável, que armazena o endereço de memória dessa variável 

## múltiplos inputs
a função `scanf()` aceita múltiplas entradas do usuário
```c
int myNum;
char myChar;

printf("digite um número e uma letra: \n");

// recebe e salva o número e a letra digitados no console
scanf("%d %c", &myNum, &myChar);

prinf("%d\n", myNum);
prinf("%c\n", myChar);
```

## input string
também podemos receber uma string digitada pelo usuário
```c
// criar a string
char firstName[30];

printf("digite seu primeiro nome: \n");

// recebe e salva o texto
scanf("%s", firstName);

printf("hello %s\n", firstName);
```
note que quando trabalhamos com strings com `scanf()`, precisamos especificar o tamanho da string/array (por isso usamos o valor alto de 30 como tamanho), mas pelo menos teremos a certeza de que temos espaço de armazenamento suficiente para comportar toda a string
* não é necessário usar o operador de referência na memória `&`

1. **porque definir um tamanho fixo para o array de `char`**
porque C não tem strings dinâmicas embutidas como em outras linguagens de programação
* em C, strings são arrays de `char`, e array em C têm tamanho fixo - determinado no momento da declaração
```c
char nome[50]; // espaço para 49 letras + '\0'
char nome2[] = "milena";

scanf("%s", nome);
```
não definir o tamanho do array e só declará-lo acusa erro de compilação, porque o compilador precisa saber quanto espaço alocar na stack

*isso é disperdício de memória?* sim e não
* criar arrays grandes e usar só 3 letras, sim, estamos subutilizando a memória
* mas em C, você só precisa reservar a quantidade máxima esperada de caractees - é uma forma de previnir buffer overflow (estouro de memória)

em programas reais, o ideal é:
* definir o tamanho com base no contexto (ex: 100 caracteres para nome completo);
* ou usar alocação dinâmica com `malloc()` quando precisar de mais flexibilidade

2. **por que não precisamos do operador de referência `&`**
porque toda string em C é, na real, um ponteiro `char*`. ainda dedicaremos uma sessão especial só para estudar ponteiros

em C, um ponteiro é uma variável especial que armazena o endereço de memória. em vez de guardar um valor diretamente (como `int x = 10`), um ponteiro guarda *onde* esse valor está
```c
int x = 10; // variável que guarda o valor 10
int* p = &x; // ponteiro para int que guarda endereço de x
```
* `&x` representa o endereço de memória onde `x` está alocado

**strings em C são ponteiros!**
toda string em C é, na real, um `char*` que aponta para a primeira letra da sequência de caracteres terminada com `\0`

`char*` significa "ponteiro para um caractere" - ou seja, uma variável que guarda o endereço de memória onde está armazenado um texto (uma sequência de caracteres, uma string).
```c
char* nome = "milena";
```
* `nome` é um ponteiro que aponta para a posição da memória onde a string `"milena"` está guardada
* essa string está em *área de memória somente leitura* - então não podemos mudar o conteúdo depois (causaria erro em tempo de execução)
* essa forma de declaração é útil para representar **strings constantes**

*resumo da ópera:* o nome do array já um ponteiro!
```c
char nome[50];
scanf("%s", nome);
```
passar `nome` como argumento significa passar o endereço de memória do primeiro caractere do array, ou seja, um  `char *`
```c
int idade;
scanf("%d", &idade); // precisamos passar o endereço explicitamente aqui
```
* porque `idade` não é um ponteiro, precisamos indicar explicitamente pra função onde ela deve colocar a informação a ser armazenada

### multiple input strings
a função `scanf()` tem uma grave limitação: ela considera espaços em branco como um caractere de término, o que significa que só podemos ler o dado string, mesmo que digitemos múltiplas palavras no console
```c
char fullName[30];

printf("digite seu nome completo: \n");
scanf("%s", fullName);

printf("oi %s", fullName);

// digite seu nome comleto: milena oliveira
// oi milena
```
para solucionar esse problema usamos a função `fgets()` para ler uma linha de texto
```c
fgets(nome_do_array, tamanho, stdin);
```
* para o tamanho, usamos `sizeof()` para indicar o tamanho máximo que pode ser lido (inclui o caractere nulo `\0`)

* `stdin` é a abreviação de standard input (entrada padrão), e representa onde o programa lê dados digitados pelo usuário - normalmente o teclado
    * tecnicamente, `stdin` é uma stream de dados do tipo `FILE *` (um ponteiro para uma estrutura que representa um fluxo de dados), já aberta automaticamente quando o programa começa

ex)
```c
char frase[50];

prinf("digite uma frase: \n");
fgets(frase, sizeof(frase), stdin);

prinf("você digitou: %s\n", frase);
```
*cuidados*: o `fgets()` inclui o caractere de quebra de linha (`\n`) se aind houver espaço no array
```c
// entrada: "olá mundo\n"
char frase[20];
fgets(frase, 20, stdin); // "olá mundo\n"
```

vamos corrigir esse comportamento usando a função `strcspn()`, da lib `<string.h>` que:
> retorna o índice do primeiro caractere da string de entrada que também aparece em outra string (o "conjunto exclusão").
ou em outras palavras
> retorna o comprimento da string até o primeiro caractere proibido (que deve estar presente em `str2`)

* ou seja, a função não te dá diretamente o índice, mas te dá o número de caracteres contados imediatamente anterior ao primeiro proibido, que significa justamente o índice dele

```c
size_t strcspn(const char *str, const char *reject);
```
* `str` - a string de análise
* `reject` - os caracteres que você não quer que apareçam
retorna o índice do primeiro caractere de `str` que também está em `reject`

```c
char frase[50];
fgets(frase, sizeof(frase), stdin);

// remove o \n do final, se existir
frase[strcspn(nome, "\n")] = '\0';
```
aqui a função está fazendo o seguinte:
1. percorre `frase` caractere por caractere
2. a cada passo, faz a verificação
3. quando encontra `\n`, ele para
4. retorna o número de caracteres que leu até ali -> o valor corresponde exatamente ao índice de `\n`

---
#### **uma breve introdução a streams**
no contexto da linguagem C, uma stream é uma **abstração de fluxo contínuo de dados** - seja ele vindo *de* ou indo *para* algum lugar (como teclado, tela, arquivo, etc.)

> pensa numa stream como **um cano por onde os dados passam**, e seu programa só se preocupa em ler ou escrever nesse cano, em saber *como* ou *onde* os dados estão de verdade

existem 3 streams padrões em C, abertas automaticamente quando o programa começa:
| stream  | nome     | usada para...     | tipo em C |
| ------- | -------- | ----------------- | --------- |
| entrada | `stdin`  | ler do teclado    | `FILE *`  |
| saída   | `stdout` | escrever na tela  | `FILE *`  |
| erro    | `stderr` | mensagens de erro | `FILE *`  |

* stream em C é um ponteiro para uma estrutura de dados do tipo `FILE`, com funções da lib padrão `<stdio.h>` inclusas no cabeçalho
* C trata arquivos, teclados, telas... tudo como um fluxo de bytes sequenciais, e você acessa esses fluxos usando funções, como:
    * `fgetc()`, `fgets()` - leitura
    * `fputc()`, `fputs()`, `fprintf()` - escrita
    todas essas funções usam uma stream como argumento (`stdin`, `stdout`, `stderr`, ou outras são abertas com `fopen()`)
