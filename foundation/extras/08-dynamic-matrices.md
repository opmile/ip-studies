# ponteiro para ponteiro
se sabemos que `int*` é um ponteiro para inteiro, entender o que é `int**` significa entender o que é uma matriz dinâmica de inteiros (`int** matriz`)

## o que é uma matriz estática?
```c
int matriz[2][3]; // 2 linhas e 3 colunas
```
essa é uma matriz estática porque:
* foi criada em tempo de compilação, alocada na memória estática
* toda a memória é alocada de uma vez só
* fica na stack

*limitação:* o tamanho tem que ser fixo ou conhecido em tempo de compilação

## o que é uma matriz dinâmica
> uma matriz dinâmica é uma estrutura de dados em C onde a quantidade de linhas e colunas pode ser definida em tempo de execução - ou seja, só quando o programa já estiver rodando

você cria usando alocação dinâmica de memória (`malloc`), e ela vive na heap (maior flexibilidade e controle) até ser liberada com `free`

### funcinamento interno
imagine uma matriz dinâmica como um vetor de ponteiros, onde:
* cada ponteiro aponta para uma linha da matriz (um vetor de inteiro, por exemplo)

```c
int **matriz
```
* `matriz` é um ponteiro para ponteiro de inteiro
* `matriz[i]` é um ponteiro para a i-ésima linha (um `int*`)
* `matriz[i][j]` acessa o elemento da linha i e coluna j

```c
int **matriz = malloc(2 * sizeof(int*));
for (int i = 0; i < 2; i++) {
    matriz[i] = malloc(3 * sizeof(int));
}
```
o que foi alocado:
```sql
matriz (int**)
 ↓
+------------+------------+
| *          | *          | → cada * é um int*
+------------+------------+
      ↓            ↓
[int int int] [int int int]
```

agora podemos fazer:
```c
matriz[0][0] = 5;
matriz[1][2] = 9;
```

**por que isso é dinâmico?**
* você pode decidir quantas linhas e colunas só em tempo de execução (por exemplo, lendo do usuário ou de um arquivo)
* você pode alocar, liberar ou redimensionar a matriz conforme quiser
* você tem total controle sobre a memória

**e se eu quiser uma matrix 1000x100?**
```c
// matriz estática
int matriz[1000][1000]; // pode dar stack overflow

// matriz dinâmica
int **matriz = malloc(1000 * sizeof(int));
for (int i = 0; i< 1000; i++) {
    matriz[i] = malloc(1000 * sizeof(int));
}
```
* isso se torna mais seguro e escalável, especialmente em programas maiores

### como liberar a memória
você precisa liberar cada linha separadamente, e só depois o vetor de ponteiros
```c
for (int i = 0; i< linhas; i++) {
    free(matriz[i]);
}
free(matriz);
```

## passo a passo
| conceito          | explicação                                  |
| ----------------- | ------------------------------------------- |
| `int** matriz`    | ponteiro para vetor de ponteiros para `int` |
| `malloc(linhas)`  | cria um vetor de ponteiros (`int*`)         |
| `malloc(colunas)` | para cada linha, cria um vetor de `int`     |
| `matriz[i][j]`    | acessa o elemento na linha `i` e coluna `j` |
| `free(matriz[i])` | libera uma linha                            |
| `free(matriz)`    | libera o vetor de ponteiros                 |

## exercícios

1. faça uma função que recebe uma matriz (alocação dinâmica) e retorna a soma de todos os elementos

* usar `int**` para representar a matriz (`int** matriz`)
* receber o número de linhas e colunas como parâmetros
* percorrer a matriz com dois loops
* retornar a soma total

```c
int sumMatrix(int **matrix, int line, int column);

int main() {
    int line = 2;
    int column = 3;
    int sum = 0;

    int **matrix = malloc(line * sizeof(int));
    for (int i = 0; i< line; i++) {
        matrix[i] = malloc(column * (sizeof(int)));
    }

    int valor = 1;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = valor++;
        }
    }

    sum = sumMatrix(matrix, line, column);
    printf("a soma de todos os elementos é: %d\n", sum);

    for (int j = 0; j < line; j++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int sumMatrix(int **matrix, int line, int column) {
    int sum = 0;
    
    for (int i = 0; i < line; i++) {
        for (int j = 0; j< column; j++) {
            sum += matriz[i][j]; // ou *((matrix + i) + j)
        }
    }

    return sum;
}

```

```java
int[][] matriz = {
    {1, 2, 3},
    {4, 5, 6}
}

int sum = 0;

for (int i = 0; i < matriz.length; i++) {
    for (int j = 0; j < matriz[i].length; j++) {
        sum  += matriz[i][j];
    }
}
```

2. criando uma matriz identidade (elementos da diagonal principal = 1)
* seja a diagonal principal todos os elementos em que sua posição seja linha = coluna

```c
void fill(int **matrix, int line, int column);

int main() {
    int line = 3;
    int column = 3;

    int **matrix = malloc(line * sizeof(int*));
    for (int i = 0; i < line; i++) {
        matrix[i] = calloc(column, sizeof(int));
    }

    fill(matrix, line, column);

    printf("{");
    for (int i = 0; i < line; i++) {
        printf("{");
        for (int j = 0; j < column; j++) {
            printf("%d", matrix[i][j]);
            if (j < column - 1) printf(", ");
        }
        printf("}");
    }
    printf("}\n");

    for (int j = 0; j < len; j++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void fill(int **matrix, int line, int column) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            if (i == j) matrix[i][j] = 1;
        }
    }
}
```

3. crie um programa que leia nomes de até 10 pessoas (com malloc), e imprima apenas os nomes que começam com a letra 'M'
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 10
#define TAM_NOME 100

int main() {
    char* error = "erro ao alocar memória"

    char **nomes = malloc(MAX_PESSOAS * sizeof(char*));

    if (nomes == NULL) {
        printf("%s\n", error);
        return 1;
    }

    printf("digite o nome de 10 pessoas");

    for (int i = 0; i < MAX_PESSOAS; i++) {
        nomes[i] = malloc(TAM_NOME * sizeof(char));

        if (nomes[i] == NULL) {
            printf("%s\n", error);
            return 1;
        }

        printf("nome: %d", i + 1);
        fgets(nomes[i], TAM_NOME, stdin);

        // remover \n se existir
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    printf("nomes que começam com 'M':")    
    for (int i = 0; i < MAX_PESSOAS; i++) {
        if (nomes[i][0] == 'M') {
            printf("- %s\n", nomes[i]);
        }
    }

    for (int i = 0; i < MAX_PESSOAS; i++) {
        free(nomes[i]);
    }
    free(nomes);
    
    return 0;
}
```
