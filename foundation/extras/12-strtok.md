# `strtok`
o `strtok` (string tokenizer) é uma função da `<string.h>` que serve para quebrar uma string em pedaços (tokens) com base em um ou mais delimitadores (espaço, vírgula, etc.)

## sintaxe
```c
char *strtok(char *str, const char *delims);
```
* `str`: ponteiro para a string original na primeira chamada, depois deve ser `NULL`
* `delims`: caracteres que vão ser considerados como separadores (delimitadores)

## funcionamento
```c
char texto[] = "oi tudo bem";
char *token = strtok(texto, " "); // delim é espaço

// agora token aponta para "oi"
token = strtok(NULL, " "); // proximo token -> "tudo"
token = strtok(NULL, " "); // proximo token -> "bem"
token = strtok(NULL, " "); // NULL -> acabou
```
* passamos o `NULL` nas próximas chamadas para dizer: "continue de onde parou na última vez!"
**por que passar `NULL` depois?**
porque `strtok` é stateful - mantém o controle internamente de onde parou
ao chamar o token da primeira vez, a função encontra o primeiro token, e guarda um *ponteiro inteiro para a posição seguinte*

`strtok` mexe na string original!
1. substitui o delimitador encontrado por `'\0'` (fim de string)
2. retorna o início do token
3. guarda um ponteiro estático para saber de onde continuar na próxima chamada

**importante**
* só retorna um token por vez
* você precisa chamar `strtok(NULL, delimitadores)` em um loop para pegar todos os tokens
* modifica a string original! sempre faça uma cópia se precisar da string inteira depois

```c
char* copy(const char *frase) {
    char *copia = malloc(strlen(frase) + 1);
    strcpy(copa, frase)
}
```

ex) **contar palavras com struct**
> crie uma função que recebe uma string e conta a frequência de cada palavra, armazenando em uma `struct Palavra { char texto[50]; int freq; }`
> armazene todas as palavras diferentes em um vetor de `struct Palavra` dinâmico

*o que precisa ser feito*
1. receber uma string com várias palavras
2. separar as palavras
3. criaar um `struct Palavra` com
```c
typedef struct {
    char texto[50];
    int freq;
} Palavra;
```
4. usar um vetor dinãmico de `Palavra` para armazenar as palavras únicas
5. se uma palavra já existe, incrementar sua frequência
6. se não existe, adicionar ao vetor com frequência 1
7. no final, imprimri as palavras com suas frequências

*lógica principal*
* tokenização com `strtok`
* comparação de strings com `strcmp`
* alocação/realloc de `Palavra*`

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PALAVRA 50

typedef struct {
    char texto[MAX_PALAVRA;
    int freq;
} Palavra;

void contarPalavras(const char *frase) {
    Palavra *vetor = NULL;
    int tamanho = 0;

    char *copia = malloc(strlen(frase) + 1);
    strcpy(frase, copia);

    char *token = strtok(copia, " \n");

    while (token != NULL) {

        // verificar se a palavra já existe no vetor
        bool encontrada = false;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(vetor[i].texto, token) == 0) {
                vetor[i].freq++;
                encontrada = true;
                break;
            }
        }

        // se não encontrada, adiciona ao vetor
        if (!encontrada) {
            Palavra *temp = realloc(vetor, (tamanho + 1) * sizeof(Palavra));
            if (temp == NULL) {
                prinf("erro de alocação");
                free(vetor);
                free(copia);
                return;
            }
            vetor = temp;
            strcpy(vetor[tamanho].texto, token);
            vetor[tamanho].freq = 1;
            tamanho++;
        }

        token = strtok(copia, " \n");
    }

    // imprimir resultado
    printf("palavras encontradas: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s: %d\n", vetor[i].texto, vetor[i].freq);
    }

    free(vetor);
    free(copia);
}

int main() {
    char frase[300];
    printf("digite a frase: ");
    fgets(frase, sizeof(frase), stdin);

    contarPalavras(frase);

    return 0;
}
```