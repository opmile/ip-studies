# pré-processador e macros
o pré-processador roda antes mesmo do processo de compilação começar. ele lida com fatores de incluir arquivos e definir macros

comandos de pré-processamento começam com o símbolo `#`, chamado de *diretivas*

## `#include` - include header files
a diretiva `#include` informa o compilador para incluir arquivos
* usado para adicionar bibliotecas ou header files customizados

```c
#include <stdio.h>
#include "myfile.h"
```
* o uso de `< >` são para bibliotecas padrão e `" "` para seus próprios arquivos

## `#define` - crie um macro
um macro é um nome que representa um valor (como PI), ou um pedaço de código, definido usando a diretiva `#define`
```c
#define PI 3.14

int main() {
    printf("value of PI: %.2f\n", PI);
    return 0;
}
```
isso significa que toda vez que o compilador encontrar `PI`, ele vai substituir por `3.14`

macros também podem receber parâmetros como funções
```c
#define SQUARE(x) ((x) * (x))

int main() {
    printf("square of 4: %d\n", SQUARE(4));
    return 0;
}
```
* macros com parâmetros funcionam como atalhos, mas tome cuidado com os parênteses para evitar erros

### compilação condicional - `#ifdef` e `#ifndef`
as diretivas `#ifdef` e `#ifndef` permitem a inclusão ou o salto de partes de código dependendo se um macro está ou não definido no escopo
* a compilação condicional é útil para debuggar ou criar diferentes versões do programa
```c
#define DEBUG

int main() {
    #ifdef DEBUG
        printf("debug mode is ON\n");
    #endif
    return 0;
}
```
* se `DEBUG` foi definido, a mensagem será impressa. caso contrarário, essa parte do código será pulada

ainda nos próximos capítulos aprenderemos a como criar nossos próprios header files e a modularizar nosso código