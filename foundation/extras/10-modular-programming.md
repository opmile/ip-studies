# organize seu código
modularização do código significa dividi-lo em pedaços menores e reutilizáveis

isso torna o código mais legível e mais fácil de manter e debbugar

a forma mais comum de organizar seus programas em C é separá-los em arquivos `.c` e arquivos de cabeçalho `.h`

modularização do código se torna muito útil para grandes projetos ou para programadores experientes que utilizam de boas práticas para manter seu código limpo e bem estruturado

## por que usar arquivos de cabeçalho?
* para declarar funções que são definidas em outros arquivos
* para compartilhar variáveis, constantes ou macros entre arquivos
* para organizar seu código em módulos lógicos

arquivos de cabeçalho normalmente contên declarações de funções, macros, e definições de structs

a divisão do programa acontece de acordo com os seguintes arquivos
* **arquivos de cabeçalho** `.h`: declara funções, tipos, constantes
* **arquivos de implementação** `.c`: define (implementa) as funções declaradas no `.h`
* **arquivo principal** `main.c`: chama as funções, inclui os cabeçalhos dos módulos

## estrutura básica de um projeto modular
```css
projeto/
├── main.c
├── math_utils.c
├── math_utils.h
├── data_utils.c
└── data_utils.h
```

## criando um módulo: `math_utils`
### `math_utils.h` (arquivo de cabeçalho)
só declara. não implementa. serve para outros arquivos saberem o que existe
```c
// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// funções disponíveis
int soma(int a, int b);
int subtrai(int a, int b);

#endif
```
* não escre o corpo da função aqui, só declara
* `#ifndef`, `#define`, `#endif` são "guardas de inclusão": evitam que o arquivo seja incluído duas vezes no mesmo programa

esses guardas de inclusão são extremamente importantes, imagine o caso:
```c
// aluno.h
typedef struct {
    char nome[100];
    int idade;
} Aluno;

// voce inclui aluno.h em dois arquivos:

// utils.c
#include "aluno.h"

// main.c
#include "aluno.h"
#include "utils.h" // mas utils.h também inclui aluno.h
```
* `aluno.h` é incluso duas vezes no seu projeto
* o compilador tenta definir o struct duas vezes, o que é ilegal e lega a um crash
```
error: redefinition of ‘struct Aluno’
```

* `#ifndef` (`"if not defined"`): se for a primeira vez que o compilador encontra essa linha, ele vai continuar
* `#define` define a constante: da próxima vez que esse mesmo arquivo for incluído, `ALUNO_H` já estará definido
* `#endif` fecha o bloco condicional 

### `math_utils.c` (arquivo de implementação)
aqui você escreve a lógica real das funções apresentando sua implementação anteriormente declarada no arquivo de cabeçalho
```c
// math_utils.c
#include "math_utils.h"

int soma(int a, int b) {
    return a + b;
}

int subtrai(int a, int b) {
    return a - b;
}
```
* aqui você inclui o módulo `.h` correspondente
* isso garante que as declarações no `.h` batam com as definições no `.c`

### usando o módulo no `main.c``
```c
// main.c
#include <stdio.h>
#include "math_utils.h" // inclui o modulo

int main() {
    int x = soma(5, 3);
    int y = subtrai(5, 2);

    printf("soma: %d\n", x);
    printf("subtração: %d\n", y);

    return 0;
}
```
* agora seu código está limpo, separado e bem organizado

### compilando arquivos corretamente
você deve compiar todos os `.c` juntos
```bash
gcc main.c math_utils.c -o meu_programa
```
ou em dois passos
```bash
gcc -c math_utils.c     # gera math_utils.o
gcc -c main.c           # gera main.o
gcc main.o math_utils.o -o meu_programa
```

## modularização de structs
**`aluno.h`**
```c
#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    char nome[100];
    int idade;
} Aluno;

void exibirAluno(Aluno a);

#endif ALUNO_H
```

**`aluno.c`**
```c
#include <stdio.h>
#include "aluno.h"

void exibirAluno(Aluno a) {
    printf("nome: %s | idade: %d\n", a.nome, a.idade);
}
```

mesmo que C não seja uma linguagem orientada a objetos, o exemplo acima de `Aluno` mostra como podemos simular conceitos de OOP de maneira manual e estrutural
* apesar de não possuir classes, você pode monstar componentes com estruturas + funções associadas, criando abstrações parecidas com objetos

## simulando orientação a objetos

**aluno.h**
```c
#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    char nome[100];
    int idade;
} Aluno;

// "metodos"
void buildAluno(Aluno *a, const char *nome, int idade);
void alunoToString(const Aluno *a)

#endif
```
* são declarados como `const` porque estamos dizendo que a função recebe esse ponteiro com argumento mas não tem permissão para modificar seu conteúdo

**aluno.c**
```c
#include <stdio.h>
#include <string.h>
#include "aluno.h"

void alunoToString(const Aluno *a) {
    printf("nome: %s | idade: %d\n", a->nome, a->idade);
}

void buildAluno(Aluno *a, cosnt char *nome, int idade) {
    strcpy(a->nome, nome, sizeof(a->nome));
    a->idade = idade;
}
```
* `strncpy(a->nome, nome, sizeof(a->nome))`
sabemos que o campo `nome` é um array de `char` com 100 posições alocadas na memória, ou seja, pode armazenar até 99 caracteres + `\0` 
esse trecho copia no máximo N caracteres da string `nome` para o compo `a->nome`

isso torna `strncpy()` mais segura do que `strcpy()` 
* `strcpy(dest, src)` copia até encontrar `\0`, sem verificar o tamanho do destino
* se `nome`tiver 150 caracteres e `a->nome` só aguenta 100, você causa um entouro de buffer (buffer overflow)
* isso é perigoso porque pode corromper a memória, causar falhas ou até abrir brechar de segurança
* `strncpy(dest, src, N)` só copia até no máximo N caracteres. `strcpy` é insegura. só use quando tem 100% de certeza do tamanho

* cuidados com `strncpy()`: ela não garante que a string vai terminar com `\0`, se `src` for do mesmo tamanho ou maior que o destino, ele não será copiado
```c
a->nome[sizeof(a->nome) - 1] = '\0';
```
garante que sempre termine corretamente

**main.c**
```c
#include "aluno.h"

int main() {
    Aluno aluno;

    buildAluno(&aluno, "milena", 19);
    alunoToString(&aluno);

    return 0;
}
```
* aqui você está encapsulando um módulo que controla como instanciar a manipular o tipo, igual ao que uma classe faria

