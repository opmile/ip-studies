# functions
função é um bloco de código que só é executado no momento de sua chamada. podemos passar dados, conhecidos como parâmetros da função
* funções são usadas para operar certas ações, e são importantes para reutilizar código: definido uma vez, usado muitas vezes

## criar funções
para criar (declarar) uma função, precisamos do nome seguido de parênteses e chaves
```c
void myFunction() {
    // código a ser executado
}
```
* `void` significa que a função não retorna nenhum valor

## chamada de funções
quando declaradas, funções não são executadas imediatamente, na verdade elas são salvas pra usar depois, e serão executadas no momento de chamada

para chamar uma função, escreva o nome da função seguido de parênteses e `;`
```c
void myFunction() {
    printf("i just got executed");
}

int main() {
    myFunction(); // chama a função
    return 0
}
// i just got executed
```
* uma função pode ser chamada inúmeras vezes
```c
void myFunction() {
    printf("i just got executed");
}

int main() {
    myFunction(); // chama a função
    myFunction();
    myFunction();
    return 0
}
// i just got executed
// i just got executed
// i just got executed
```

## parâmetros e argumentos
informações podem ser passadas para funções como parâmetros. parâmetros atuam como variáveis locais dentro da função. 
* são especificados depois do nome da função, dentro dos parênteses
* podemos passar quantos parâmetros quisermos para a função
```c
returnType functionName(parameter1, parameter2, parameter3) {
    // código a ser executado
}
```
quando um parâmetro é passado para dentro de uma função, ele é chamado de argumento
```c
void myFunction(char name[]) {
  printf("Hello %s\n", name);
}

int main() {
  myFunction("Liam");
  myFunction("Jenny");
  myFunction("Anja");
  return 0;
}

// Hello Liam
// Hello Jenny
// Hello Anja
```
* `name` é um parâmetro e `Liam`, `Jenny` e `Anja` são os argumentos

## escopo
em C, variáveis são visíeis e acessíveis dentro da região onde foram declaradas. essa região é o que chamamos de *escopo*

### escopo local
uma variável criada dentro de uma função assume escopo local e só pode ser usada dentro da função onde foi criada
```c
void myFunction() {
  // local variable that belongs to myFunction
  int x = 5;
}

int main() {
  myFunction();

  // print the variable x in the main function
  printf("%d", x); // erro de compilação
  return 0;
}
```
* `x` não existe dentro do escopo da função `main()`

### escopo global
uma variável criada fora de qualquer função assume escopo global, se tornando visível e acessível dentro do escopo de qualquer função
* uma variável global pode ser usada por qualquer um (global ou local)
```c
// global variable x
int x = 5;

void myFunction() {
  // ee can use x here
  printf("%d", x);
}

int main() {
  myFunction();

  // we can also use x here
  printf("%d", x);
  return 0;
}
```
#### nomes de variáveis
se operarmos com a mesmo nome de variável dentro e fora de uma função, C vai tratar ambas como diferentes, apesar de carregarem o mesmo nome: uma está disponível no escopo global e a outra disponível no escopo local (dentro da função)
```c
// global variable x
int x = 5;

void myFunction() {
  // local variable with the same name as the global variable (x)
  int x = 22;
  printf("%d\n", x); // refers to the local variable x
}

int main() {
  myFunction();

  printf("%d\n", x); // refers to the global variable x
  return 0;
}
```
* imprime a variável local `x` e depois a variável global `x`
de qualquer forma, é uma boa prática garantir nomes únicos para cada variável para evitar erros e confusões futuras

em geral, devemos tomar cuidado com variáveis globais já que podem ser acessadas e modificadas em qualquer função

## declaração e definição de funções
uma função é dividida em duas partes:
* **declaração**: nome da função, tipo de retorno e parâmetros (se tiver)
* **definição**: o corpo da função, implementação (código a ser executado)
```c
void myFunction() { // declaração
    // body/implementação (definição)
}
```

por fins de otimização de código, é recomendado separar declaração e definição da função. em código C é comum encontrar a declaração de funções acima de `main()` e sua implementação abaixo de `main()`
```c
// function declaration
void myFunction();

// the main method
int main() {
  myFunction();  // call the function
  return 0;
}

// function definition
void myFunction() {
  printf("I just got executed!");
}
```
* isso torna o código mais organizado, limpo e legível

se a função contêm parâmetros, usamos a mesma lógica
```c
// function declaration
int myFunction(int x, int y);

// the main method
int main() {
  int result = myFunction(5, 3); // call the function
  printf("Result is = %d", result);
  return 0;
}

// function definition
int myFunction(int x, int y) {
  return x + y;
}
```

## chamadas de funções dentro de funções
desde que as funções sejam declaradas primeiro, é possível usar funções para chamar outras funções
```c
// declare two functions, myFunction and myOtherFunction
void myFunction();
void myOtherFunction();

int main() {
  myFunction(); // call myFunction (from main)
  return 0;
}

// define myFunction
void myFunction() {
  printf("Some text in myFunction\n");
  myOtherFunction(); // call myOtherFunction (from myFunction)
}

// define myOtherFunction
void myOtherFunction() {
  printf("Hey! Some text in myOtherFunction\n");
}
```

## recursão
recursão é uma técnica onde uma função se chama. essa técnica promove uma forma de quebrar problemas complicados em problemas mais simples que são mais fáceis de resolver

adicionar dois números é algo fácil de implementar, mas adicionar um intervalo de números se torna uma tarefa um pouco mais complicada. no exemplo a seguir, recursão é usada para somar um intervalo de números quebrando o problema em uma tarefa simples de adicionar dois números

```c
int sum(int k);

int main() {
    int result = sum(10);
    printf("%d\n", result);

    return 0;
}

int sum(int k) {
    if (k > 0) {
        return k + sum(k - 1);
    } else {
        return 0;
    }
}
```
quando a função `sum()` é chamada, ela adiciona o parâmetro `k` a soma de todos os números menores que `k`. e quando `k` se torna 0, a função retorna 0
```
10 + sum(9)
10 + ( 9 + sum(8) )
10 + ( 9 + ( 8 + sum(7) ) )
...
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + sum(0)
10 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 + 0
```

em vez de resolver tudo de uma vez, você divide o problema em partes menores, resolvendo cada parte com a mesma função - até chegar a um caso base
* imagine que é como se estivéssemos usando uma boneca russa, onde você precisa abrir todas as bonecas, uma dentro da outra e, ao final, voltamos elas de trás para frente para voltar para o formato original

```c
returnType function(type parameter) {
    if (stop condition) {
        return result;
    } else {
        return function(call with lowest values)
    }
}
```

* devemos tomar muito cuidado qunado usamos recursão porque é fácil escrever uma função que entra em loop infinito e nunca termina, ou uma que usa uma quantidade excessiva de memória e poder de processamento
* entretanto, quando escrita corretaente, recrusão é uma técnica de resolução de problemas muito eficiente e matematicamente elegante em programação

ex) rescursão com fatorial
fatorial de `n` (n!) é: 
`n! = n * (n - 1)!`
com exceção de: `0! = 1`

5! = 5 * (5 - 1)! = 5 * 4! = 5 * ( 4 * (4 - 1)! ) ...

```c
#include <stdio.h>

int fatorial(int n);

int main() {

    int resultado = fatorial(5);
    printf("5! = %d\n", resultado);

    return 0;
}

int fatorial(int n) {
    if (n == 0) {
        return 1; // caso base
    } else {
        return n * fatorial(n - 1); // chamada recursiva
    }
}
```

**principais tipos de problemas onde recursão brilha**

1. problemas que seguem uma definição recursiva
alguns problemas são definidos de forma recursiva - ou seja, eles se auto-referenciam
* fatorial
* sequência de fibonacci
* potência (`a^b = a * a^(b-1)`)

2. estruturas de dados hierárquicas (como árvores e grafos)
quando você precisa navegar por uma estrutura que tem nós filhos, a recursão entra como uma luva
* percorrer uma árvore binária (pré-ordem, in-ordem, pós-ordem)
* dfs (busca em profundidade) em grafos
* avaliar expressões matemáticas representadas em árvores 

3. divisão e conquista (divide and conquer)
esses algoritmos dividem o problema em subproblemas menores e resolvem cada um recursivamente 
* merge sort
* quick sort
* binary search
* fast exponentation

4. backtraking
usado quando você precisa explorar toasas as possibilidade de uma solução e voltar atrás quando uma tentativa falha
* resolver sudoku
* gerar combinações e permutações
* problema das n rainhas
* percorrer labirintos

5. programação dinâmica: problemas com subproblmeas repetidos
recursão combinada com memoization (armazenar resultados) pode resolver problemas complexos de forma elegante
* mochila (knapsack problem)
* caminhos mínimos em matrizes
* núemro de formas de subir escadas
* editar distância (levenshtein)

6. manipulação de listas encadeadas (listas, pilhas, etc.)
recursão facilita navegar ou modificar estruturas que possuem referências entre elementos 
* inverter uma lista encadeada
* verificar se uma lista é palíndromo
* remover elementos duplicados recursivamente

## funções matemáticas
C também disponibiliza um lib de funções matemáticas que podem ser adicionadas no cabeçalho do arquivo com `<math.h>`
```c
#include <math.h>
```

1. **raiz quadrada `sqrt()`**
```c
printf("%f", sqrt(16));
```

2. **aproximações**
* a função `ceil()` arredonda um número para cima para o inteiro mais próximo
* a função `floor()` arredonda o número para baixo para o inteiro mais próximo
```c
printf("%f", ceil(1.4));
printf("%f", floor(1.4));
```

3. **potência**
a função `pow()` retona o valor de x elevado a y (x^y)
```c
printf("%f", pow(4, 3));
```

para uma referência completa das funções presentes na lib `<math.h>` acesse:
https://www.w3schools.com/c/c_ref_math.php