#### 🟢 **Parte 1 – Aquecimento de Sintaxe e Ponteiros**

1. **Declare uma variável inteira, um ponteiro para inteiro e use o ponteiro para alterar o valor da variável.**

   * *Objetivo: entender como ponteiros referenciam variáveis.*

2. **Crie uma função que receba um ponteiro para inteiro e dobre o valor apontado.**

   * *Teste com diferentes números.*

3. **Escreva uma função `swap()` que troca o valor de duas variáveis usando ponteiros.**

   * *Essa é clássica e essencial!*

4. **Declare um array de 5 inteiros e imprima os valores usando aritmética de ponteiros.**

   * *Ex: `*(arr + i)` ao invés de `arr[i]`.*

5. **Escreva uma função que recebe um array de inteiros e seu tamanho, e retorna a média dos valores.**

   * *Use apenas ponteiros, sem `[]` dentro da função.*

---

#### 🟡 **Parte 2 – Vetores, Strings e Funções com Ponteiros**

6. **Implemente uma função que conte quantas letras há em uma string passada como ponteiro (`char*`).**

   * *Sem usar `strlen()`!*

7. **Faça uma função que inverta uma string "in-place" (sem criar nova string).**

   * *Dica: troque `s[0]` com `s[n-1]`, e assim por diante, usando ponteiros.*

8. **Crie uma função que receba dois vetores e um tamanho, e preencha um terceiro vetor com a soma dos dois primeiros (posição por posição).**

   * *Tudo via ponteiro.*

---

#### 🔴 **Parte 3 – Desafios com Ponteiros**

9. **Crie uma função que receba um vetor de inteiros e remova todos os valores negativos.**

   * *Dica: use dois ponteiros (um para leitura, outro para escrita).*

10. **Implemente uma função que aloque dinamicamente um vetor de `n` inteiros e inicialize com valores de 1 até `n`.**

    * *Use `malloc()` e libere com `free()`.*

11. **Faça uma função que recebe uma matriz (alocação dinâmica) e retorna a soma de todos os elementos.**

    * *Treine `int**` aqui.*

12. **Mini-Projeto: Crie um programa que leia nomes de até 10 pessoas (com `malloc`), e imprima apenas os nomes que começam com a letra 'M'.**

    * *Alocação dinâmica + strings + ponteiros = 🔥.*

---

