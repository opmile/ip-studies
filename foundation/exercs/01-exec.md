#### 🟢 **Parte 1 – Aquecimento de Sintaxe e Ponteiros**

1. **Declare uma variável inteira, um ponteiro para inteiro e use o ponteiro para alterar o valor da variável.**

2. **Crie uma função que receba um ponteiro para inteiro e dobre o valor apontado.**

3. **Escreva uma função `swap()` que troca o valor de duas variáveis usando ponteiros.**

4. **Declare um array de 5 inteiros e imprima os valores usando aritmética de ponteiros.**
* ex: `*(arr + i)` ao invés de `arr[i]`.

5. **Escreva uma função que recebe um array de inteiros e seu tamanho, e retorna a média dos valores.**

---

#### 🟡 **Parte 2 – Vetores, Strings e Funções com Ponteiros**

6. **Implemente uma função que conte quantas letras há em uma string passada como ponteiro (`char*`).**

7. **Faça uma função que inverta uma string "in-place" (sem criar nova string).**

8. **Crie uma função que receba dois vetores e um tamanho, e preencha um terceiro vetor com a soma dos dois primeiros (posição por posição).**

---

#### 🔴 **Parte 3 – Desafios com Ponteiros**

9. **Crie uma função que receba um vetor de inteiros e remova todos os valores negativos.**

10. **Implemente uma função que aloque dinamicamente um vetor de `n` inteiros e inicialize com valores de 1 até `n`.**

11. **Faça uma função que recebe uma matriz (alocação dinâmica) e retorna a soma de todos os elementos.**

12. **Mini-Projeto: Crie um programa que leia nomes de até 10 pessoas (com `malloc`), e imprima apenas os nomes que começam com a letra 'M'.**

---

🔹 Exercício 3: Transformar List em Lista Encadeada Dinâmica
Objetivo: Consolidar domínio de alocação dinâmica com structs.

Descrição:
Crie uma nova versão de List, agora como lista encadeada dinâmica:

```c
typedef struct Node {
    int value;
    struct Node* next;
} Node;
```
Regras:

Crie funções:

void append(Node** head, int value);

void printList(Node* head);

void freeList(Node* head);

A função append deve inserir elementos no final da lista.

A função freeList deve liberar toda a memória corretamente.

A função printList deve mostrar os elementos em ordem.

Desafio bônus: Faça uma versão de removeByValue(Node** head, int value).


mini-projeto para treinar modularização de código — tipo criar um sistema de cadastro simples com módulo de pessoas, módulo de utilitários de string e o main.
* incluir persistência de dados em arquivos

