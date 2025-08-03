# loops
loops executam um bloco de código enquato uma condição específica ainda não foi atendida. loops são fundamentais porque economizam tempo e erros, tornando o código mais legível

## while
o loop `while` itera sobre um bloco de código enquanto a condição especificada é `true`
```c
while (condition) {
    // code block to be executed
}
```

```c
int i = 0;

while (i < 5) {
    printf("%d\n", i);
    i++;
}
```
* `i` é uma variável de contagem, auxiliar no loop, tradicionalmente significa 'index' (posição) ou 'iterator'

quando usamos um loop while, é importante nos atermos a condição e não esquecer de incrementar a variável em `i++` para não cair em um loop infinito

## do-while
é uma variação do loop `while`. esse loop executa o bloco de código pela primeira vez, antes de checar the a condição é verdadeira, depois continua repetindo o loop enquanto a condição é verdadeira
```c
do {
    // code block to be executed
} while (condition);
```
* o loop em um `do-while` sempre será executado pelo menos uma vez, mesmo se a condição for `false` na primeira iteração, já que o bloco de código é executado antes da testagem da condição
```c
int i = 0;

do {
    printf("%d\n", i++);
} while (i < 5);
```

* o comportamento de executar o loop pelo menos uma vez se torna útil quando queremos garantir que uma mensagem ou entrada de dados de usuário seja executado
```c
int number;

do {
  printf("Enter a positive number: ");
  scanf("%d", &number);
} while (number > 0);
```
* `scanf()` recebe como argumento o endereço de memória da variável (`&number`) para que a função, ao ler o dado, coloque o valor lido diretamente dentro da variável (`number`)

## for 
quando se sabe exatamente quantas vezes será necessário iterar um bloco de código em um loop, usamos `for` ao invés de `while`
```c
for (expreesion1; expression2; expression3) {
    // code bloco to be executed
}
```
* **expression 1**: executado uma vez antes da execução do bloco de código
* **expression 2**: define a condição de execução do bloco de código
* **expression 3**: executado todas as vezes depois que o bloco de código foi executado

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```
1. define a variável `i` index para começar com `int i = 0`
2. difine a condição de iteração de execução para `i < 5`. se a condição for `true`, o loop recomeça de novo, se for `false`, o loop se encerra
3. incrementa a variável

*alguns exemplos*
```c
int i;

for (i = 0; i <= 10; i += 2) {
    printf("even number: %d\n", i);
}
```

```c
int sum = 0;

for (int i = 0; i <= 5; i++) {
    sum += i;
}
```

```c
for (int i = 0; i > 0; i--) {
    printf("countdown: %d\n", i);
}
```

#### nested loops / loops aninhados
em um loop aninhado, teremos o "inner loop" e o "outer loop"
o "inner loop" será executado uma vez para cada iteração do "outer loop"

isso se torna útil quando é preciso repetir ações em "camadas", como:
* varrer uma matriz
* imprimir padrões em forma de triângulo ou tabela
* criar combinações entre elementos

*sintaxe geral*
```c
for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
        // codigo a ser repetido
    }
}
```
* o outer loop controla o ritmo maior, e o inner repete dentro de cada iteração do outer loop


```c
int i, j;

for (i = 1; i <=2; ++i) {
    printf("outer: %d\n", i); // executado duas vezes

    for (j = 1; j <=3; ++j) {
        printf("inner: %d\n", j); // executdo 6 vezes (2 * 3)
    }
}
```

1. **tabela simples**
- outer loop define o número de colunas
- inner loop define o número de linhas
- fazemos isso usando uma quebra de linha no outer loop depois da finalização das iterações do inner loop
```c
for (int i = 1; i <=3; i++) {
    for (int j = 1; j <= 4; j++) {
        printf("(%d, %d)", i, j);
    }
    printf("\n");
}
```
saída esperada:
```
(1,1) (1,2) (1,3) (1,4) 
(2,1) (2,2) (2,3) (2,4) 
(3,1) (3,2) (3,3) (3,4)
```
- i representa a linha
- j representa a coluna

2. **triângulo de asteriscos** 
```c
for (int linha = 1; linha <= 5; linha++) {
    for (int col = 1; col <= linha; col++) {
        printf("*");
    }
    printf("\n");
}
```

3. **tabela tipo tabuada**
```c
for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
        printf("%d", i * j);
    }
    printf("\n");
}
```

## `break`/`continue`

**`break`**
o primeiro caso de uso do `break` foi visto durante os estudos de `switch`, em que o usamos para sair imediatamente do bloco `switch` quando a condição foi satisfeita

o `break` é, na verdade, mais comumente

```c
for (int i = 0; i < 10; i++) {
    if (i == 4) {
        break;
    }
    printf("%d\n", i);
}
```

**`continue`**
a declaração do `continue` quebra uma iteração (dentro do loop), quando uma condição específica acontece, e continua com a próxima iteração do loop
```c
for (int i = 0; i < 10; i++) {
    if (i == 4) {
        continue
    }
    printf("%d\n", i);
}
```
