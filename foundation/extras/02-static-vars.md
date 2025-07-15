# o que são variáveis estáticas em C
uma variável estática `static` é uma variável que mantém seu valor entre diferentes chamadas da função onde foi declarada, sem perder seu conteúdo quando a função termina
* ela é inicializada só uma vez e vive pelo tempo de execução total do progrma, mesmo se for declarada dentro do escopo de uma função

**sem `static`:**
```c
#include <stdio.h>

void contador() {
    int num = 0;
    num++
    printf("num = %d\n", num);
}

int main() {
    contador();
    contador();
    contador();
    return 0;
}
```
```
num = 1
num = 1
num = 1
```
`num` é uma variável local normal. toda vez que `contador()` é chamada, `num` é recriada zerada, usada e destruída

**usando `static`:**
```c
#include <stdio.h>

void contador() {
    static int num = 0;
    num++;
    printf("num = %d\n", num);
}

int main() {
    contador();
    contador();
    contador();
    return 0;
}
```
```
num = 1
num = 2
num = 3
```
com `static` a variável `num` é criada uma vez, fora da stack, e mantém seu valor entre chamadas. ou seja, ela não é destruída no fim da função

## o que `static` faz
1. **tempo de vida**
* variáveis `static` têm duração total do programa (igual as variáveis globais)

2. **escopo**
* se dentro da função, a variável `static` só pode ser usada ali (escopo local)
* se fora da função, o `static` restringe o acesso ao arquivo atual (escopo do arquivo, tipo "global privada")
```c
static int contador = 0;

void soma() {
    contador++;
    printf("%d\n", contador);
}
```
`contador` é global dentro do arquivo: outras funções podem usar, mas outros arquivos não tem acesso. isso é útil para proteger variáveis "internas" de bibliotecas `.c`


