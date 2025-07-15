# multidimensinal arrays
vetores (ou também chamados arrays) como vistos anteriormente possuem apenas uma dimensão (1D), mas se quisermos armazenas informações de maneira tabular, como uma tabela com linhas e colunas, precisamos nos familiarizar com arrays multidimensionais

um array multidimensional é basicamente um array de arrays

arrays podem ter qualquer número de dimensões, mas a mas comum é a bidimensional (2D) que compõe o que chamamos de matrizes

## arrays bidimensionais
um array bidimensional é conhecido como uma matriz (uma tabela de linhas e colunas)
```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```
* a primeira dimensão corresponde ao número de linhas `[2]`
* a segunda dimensão é corresponde ao número de colunas `[3]`

|           |   column 0   |   column 1   |   column 2   |
| --------- | ------------ | ------------ | ------------ |
|   row 0   |      1       |      2       |      3       |
|   row 1   |      4       |      5       |      6       |

### acesso de elementos no array bidimensional
para acessar um elemento em uma matriz, é necessário especificar tanto o índice da linha como o da coluna
```c
int matrix[2][3] = {
    {1, 4, 2},
    {3, 6, 8}
};

printf("%d", matrix[0][2]); // 2
```
* acessa o elemento da primeira linha e terceira coluna
* outra forma de pensar é relembrando que uma matriz nada mais é do que um array de arrays, então cada elemento correpsonde a um array. o acesso pelo primeiro índice significa acessar um dos arrays, e acesso pelo segundo índice corresponde ao elemento do array escolhido

para modificar o valor de um elemento na matrix, usamos a mesma lógica do acesso explicada anteriormente: se refere ao número de índice do elemento de cada dimensão
```c
int matrix[2][3] = {
    {1, 4, 2},
    {3, 6, 8}
};
matrix[0][0] = 9;

printf("%d", matrix[0][0]); // 9
```

### iterando uma matriz
aqui precisamos usar nossos conhecimentos em nested loops, um loop para cada dimensão do array
* *outer loop*: para iterar sobre a linha da matriz
* *inner loop*: para iterar sobre a coluna da matriz
```c
int matrix[2][3] = {
    {1, 4, 2},
    {3, 6, 8}
};

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d\n", matrix[i][j]);
    }
}
```

### arrays tridimensionais
também podemos declarar mais de duas dimensões
```c
// array 3D com 2 blocos, cada um com 4 linhas e 3 colunas
int example[2][4][3];
```
isso cria um array 3D com 
* 2 blocos (primeiro índice)
* 4 linhas por bloco (segundo índice)
* 3 colunas por linha (terceiro índice)

#### casos de uso
* arrays 2D são ótimos para armazenar pontuações, tabela de jogos ou planilhas
* arrays 3D podem representar estruturas mais complexas como um conjunto de tabelas ou níveis em um jogo