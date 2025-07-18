# exercícios 3

## exercícios gerais

1. **soma de diagonal principal de matriz dinâmica**
* aloca uma matriz nxn com `int**`
* preenche com valores
* soma a diagonal principal
extra: faça o mesmo com a diagonal segundária

2. **clonar vetor dinâmico**
* dado um vetor alocado com `malloc`, escreva uma função que retorna uma cópia exata desse vetor em uma nova região da memória
* resolva tudo com aritmética de ponteiros

3. **função que modifica struct por ponteiro**
```c
typedef struct {
  char nome[100];
  int idade;
} Pessoa;
```
* crue uma função que recebe um `Pessoa*` e altera a idade 
* em `main` verifique se a modificação persistiu

4. **soma de cmapos em vetor de structs**
* crie um vetor de `Pessoa`, como acima
* escreva uma função que recebe um ponteiro para esse vetor e o número de elementos, e retorna a soma das idades

4. **soma recursiva dos elementos de um vetor**
escreva uma função recursiva que recebe um ponteiro para vetor e seu tamanho e retorna a soma total dos elementos

5. **maior elemento usando ponteiro**
escreva uma função `int* maiorElemento(int* vetor, int n)` que retorna o endereço do maior valor do vetor
depois, altere esse valor diretamente usando o ponteiro retornado

6. **função que recebe `int**` e preenche**
escreva uma função `void preencher(int **m, int linhas, int colunas)` que recebe uma matriz previamente alocada e a preenche com `i + j`

7. **remover ímpares de vetor dinâmico**
dado um vetor dinâmico de inteiros, crie uma função que remove os ímpares, realocando o vetor para novo tamanho

8. **recrie `strlen()`**
crie uma função que recebe um `char*` e retorna o tamanho da string sem usar nenhuma função da lib

9. **contador de vogais em vetor de strings**
recebe um `char** nomes` e `int n` e conta quantas vogais há no total de todas as strings

10. **soma dos quadrados com ponteiro**
recebe um vetor `int*` e retorna a soma dos quadrados de todos os elementos (use só aritmética de ponteiros)

11. **verificar palíndromo com ponteiro**
receba um `char*` e verifique se a string é palíndromo sem usar índices `[]`

## exercícios - alocação e realocação dinâmica

### **nível 1 – fundamentos e controle de memória**

1. **crie um vetor dinâmico de `n` inteiros.**
   * o usuário informa `n`
   * preencha com números aleatórios entre 1 e 100
   * imprima e libere a memória

2. **Realoque o vetor para o dobro do tamanho.**

   * Preencha os novos espaços com `-1`.
   * Imprima novamente o vetor completo.

3. **Crie uma matriz dinâmica de `m x n` inteiros.**

   * O usuário fornece `m` e `n`.
   * Preencha com a soma dos índices (`i + j`).
   * Imprima no formato de matriz.

4. **Libere toda a memória alocada da matriz.**

   * Garanta que **nenhum vazamento de memória** ocorra (use `valgrind` se quiser checar depois 😉).

---

### 🔧 **Nível 2 – Manipulação dinâmica real**

5. **Crie um programa de cadastro de notas.**

   * O usuário define quantos alunos (`n`) e quantas notas por aluno (`m`).
   * Use uma **matriz dinâmica** para armazenar as notas.
   * Permita que o usuário **adicione mais notas a um aluno** individualmente (use `realloc`).
   * Exiba a média de cada aluno.

6. **Crie um vetor de strings (char\*\*).**

   * O usuário informa quantos nomes serão cadastrados.
   * Para cada nome, aloque memória suficiente com `malloc`.
   * Após o preenchimento, **realoque um nome aleatório para ter o dobro do tamanho** e permita ao usuário editar.
   * Libere tudo no final.

---

### 🧪 **Nível 3 – Casos mistos com realloc (desafiador)**

7. **Crie um sistema de listas dinâmicas em 2D:**

   * Comece com uma matriz `n x m` inicial.
   * O usuário pode:

     * Adicionar linhas (`realloc` do ponteiro externo).
     * Adicionar colunas em uma linha específica (`realloc` do ponteiro interno).
   * Sempre que a matriz mudar, imprima o novo estado.

8. **Faça um programa que simule um "editor de pixels":**

   * Cada pixel é um número inteiro.
   * Comece com uma matriz 2x2.
   * O usuário pode:

     * Inserir novas linhas ou colunas.
     * Alterar valores de pixels.
     * Remover linhas ou colunas com `realloc`.
   * Exiba sempre o estado atual.

---

### 💥 Bônus de fixação

9. **Crie um histórico de comandos com realloc:**

   * Crie um vetor dinâmico de strings.
   * O programa lê comandos (strings) do usuário.
   * Cada novo comando é adicionado com `realloc`.
   * Ao digitar `"sair"`, o programa mostra todo o histórico e libera a memória.

---

Se quiser, posso criar um repositório de modelo com headers e funções separadas por exercício — ou ir revisando cada resolução sua para corrigir de forma detalhada. Quer fazer assim?

Qual exercício você quer resolver primeiro? 👩‍💻
