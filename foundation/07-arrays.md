# array / vetor
um array é uma coleção de variáveis do mesmo tipo, armazenadas em posições consecutivas da memória e acessadas por índices
* funciona como uma fileira de caixas numeras em que cada caixa guarda um valor, e você pode acessar a que quiser usando o número da posição (índice)

## declaração
existem duas formas principais de declarar e inicializar arrays, e a escolha entre elas depende do contexto de uso

1. **tamanho explícito**
```c
int arr[5] = {1, 2, 3, 4, 5};
int numbers[5];
```

2. **tamanho implícito**
```c
int arr[] = {1, 2, 3, 4, 5};
int numbers[];
```
* aqui o compilador conta quantos elementos existem e aloca o espaço exato na memória

*quando usar?*
**use sem tamanho `int numbers[] = {...}` quando**
* estamos inicializando com todos os elementos no momento da declaração
* você quer evitar erros de contagem ou deixá-lo mais legível
* o array nunca vai crescer (arrays em c têm tamanho fixo)
de certa forma, é mais legível e seguro (menos chance de errar a contagem) e mais flexível durante o desenvolvimento

**use com tamanho fixo `int numbers[x]` quando**
* não inicializará imediatamente, ou pretendo preencher depois (com `scanf` por exemplo)
* se deseja o controle exato do tamanho alocado (com arrays grandes ou sensíveis à memória)
* se trabaçha com arrays parciais ou parcialmente preenchidos
observe:
```c
int myNumbers[4];

myNumbers[0] = 1;
myNumbers[1] = 2;
myNumbers[2] = 3;
myNumbers[3] = 4;
```

*cuidados*
```c
int numbers[5] = {1, 2, 3}; // válido, mas o restante vira 0 (implícito)
```
isso funciona, mas deve-se tomar cuidado pois é fácil esquecer que se deixou posições não inicializadas. assim é melhor:
```c
int numeros[] = {1, 2, 3};
```

> **se você já sabe todos os valores na hora da declaração, prefira deixar o compilador contar

**string literal**
em arrays de `char` (strings) isso se torna mais prático
```c
char name1[] = "milena"; // tamanho 7 (inclui o '\0')
char name2[10] = "milena"; // cabe até 9 letras + '\0'
```

## acesso por índice
para acessar um elemento de uma array, devemos nos referir a ele a partir do seu número de índice
* os índices do array sempre começam em 0: 
    * [0] representa o elemento que ocupa a primeira posição
    * [1] repretsenta o elemento que ocupa a segunda posição
```c
int myNumbers[] = {25, 50, 75, 100};
printf("%d", myNumbers[0]); //25
```

para modificar o elemento que ocupa a posição `[i]` no array, usamos a mesma lógica de acesso por índice
```c
myElement[i] = a;
```

```c
int myNumbers[] = {25, 50, 75, 100};
myNumbers[0] = 33;

printf("%d", myNumbers[0]); // 33
```

## iterando em um array
arrays geralmente andam de mãos dadas com loops, em específico loops `for`
```c
int myNumbers[] = {25, 50, 75, 100};

for (int i = 0; i < 4; i++) {
    printf("index %d: %d\n", i, myNumbers[i]);
}
```
* isso nos ajuda entender porque usamos `i`, e é justamente para se referir ao index (posição) de um elemento no array

## retornar tamanho do array
> nota pessoal
para retornar o tamanho de um array, temos que fazer uma verdadeira gambiarra usando o método `sizeof`
* não se esqueça que essa função retorna o tamanho em bytes de um tipo de dado ou variável 
* o especificador de tipo é o `%zu`

```c
int myNumbers[] = {10, 25, 50, 75, 100};
printf("%zu", sizeof(myNumbers)); // imprime 20
```
lembra que um `int` ocupa 4 bytes na memória? então como temos um array de 5 inteiros, teremos (4 * 5) 20 bytes na memória

saber o tamanho em memória de um array é muito útil quando se trabalha com programas longos que requerem bom gerenciamento de memória

então para descobrir quantos elementos um array possui, podemos fazer uma simples conta aritmética que divide o tamanho do array em bytes pelo tamanho de algum dos elementos do array (preferível o primeiro elemento)
```c
int myNumbers[] = {10, 25, 50, 75, 100};
int length = sizeof(myNumbers) / sizeof(myNumbers[0]);

printf("%d", length); // 5
```

## implementando loops melhores
como não temos uma função pronta e específica que já retorna o tamanho do array (como acontece em outras linguagens de programação), devemos nós mesmo definir uma variável que armazena o tamanho do array

isso é de extrema importância para melhorar a implementação de iterações em arrays. no exemplo anterior definimos a condição máxima de iteração a partir de um número (`i < 4`), mas fazer isso não é nem um pouco ideal já que a iteração só funcionaria com arrays de 4 elementos
* imagine que queremos construir uma função que recebe como argumento um array e a partir dele imprime todos seus elementos. nesse caso, dentro da função, precisamos construir nossa lógica para o tamanho de qualquer array passado como parâmetro

```c
int myNumbers[] = {25, 50, 75, 100};
int length = sizeof(myNumbers) / sizeof(myNumbers[0]);

for (int i = 0; i < length; i++) {
    printf("%d\n", myNumbers[i]);
}
```

#### exs)
```c
int ages = {20, 22, 21, 18, 35, 26, 87, 70, 48};

float avg, sum = 0;
int length = sizeof(ages) / sizeof(ages[0]);

for (int i = 0; i < length; i++) {
    sum += ages[i];
}

avg = sum / length;

printf("the average age is: %.2f", avg);
```

```c
int ages = {20, 22, 21, 18, 35, 26, 87, 70, 48};

int lowestAge = ages[0];
int length = sizeof(ages) / sizeof(ages[0]);

for (int i = 0; i < length; i++) {
    if (lowestAge > ages[i]) {
        lowestAge = ages[i];
    }
}

printf("menor idade: %d", lowestAge);
```

