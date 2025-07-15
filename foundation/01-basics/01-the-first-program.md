# a estrutura mínima de um programa em c

*preliminares:*
**1. todo programa em c começa no `main()`**
o `main()` é como o ponto de partida. é ali que o programa começa a rodar. sem ele, nada acontece. ele é o coração do programa.
* devemos lembrar que c é uma linguagem compilada estaticamente tipada, precisamos declarar o tipo de dado de retorno de uma função e na declaração de variáveis
* o tipo de retorno do método `main()` é um `int`, esse número tem um significado especial para o sistema operacional
* o valor retornado pelo `main` é o status de saída do programa. quando um programa termina, ele comunica ao sistema se ele foi executado com sucesso ou com erro
* essa informação é muito útil para scripts automatizados (tomam decisões baseadas no retorno de outro programa), debuggers (que detectam se algo deu errado), outros programas que podem encadear ações

**2. `#include <stdio.h>` é um comando de pré-processamento** 
serve para incluir libs. a lib `<studio.h>` (standard input/output and file handling header) te dá acesso a funções como `printf()` e `scanf()` justamente por ser uma *header file library*

**3. `printf()` serve para imprimir coisas na tela**

### o primeiro código funcional em c
```c
#include <stdio.h> // lib padrão para entrada e saída de dados

int main() {
    // printf() imprime uma mensagem na tela
    printf("olá, milena! bem-vinda a linguagem c. \n");
    printf("esse é seu primeiro programa e ele já rodou perfeitamente \n");

    return 0; // indica que o programa terminou corretamente
}
```
* `include <stdio.h>` - importa a lib que tem o printf
* `int main()` - início da função principal do programa
* `printf()`- imprime textos na tela
* `return 0` - diz pro sistema operacional que o programa terminou com sucesso

### como compilar e rodar arquivos c no terminal
o compilador traduz seu código escrito em C (ex. `meu_programa.c`) para um arquivo (binário) executável, que o sistema pode entender e rodar
- usaremos o `gcc` (gnu compiler collection) - um dos compiladores mais populares da linguagem c

*etapas*
1. **compilar (build)**
antes de rodar, precisamos compilar o código com:
```bash
gcc nome_do_arquivo.c -o nome_do_executavel
```

ex)
```bash
gcc 01-first-program.c -o 01-first-program
```
isso cria um executável chamado `01-first-program` (sem extensão) no mesmo diretório do seu arquivo `.c`

2. **executar**
depois da compilação, você roda o programa assim:
```bash
./01-first-program
```
o `./` significa "rode o executável que está qui no diretório atual"

#### organização: executáveis na pasta `bin/`
para evitar bagunça no seu projeto, o ideal é guardar os executáveis em uma pasta separada, como `bin/`

1. **crie a pasta `bin/` no mesmo diretório de `.c`**
```bash
mkdir -p bin
```
`-p` significa que forçaremos a criação da pasta mesmo se outra pasta com o mesmo nome já existir dentro do diretório

2. **compile o código e jogue o resultado em `bin/`**
```bash
gcc 01-first-program.c -o bin/01-first-program
```

3. **rode o programa que está na `bin/`**
```bash
./bin/01-first-program
```

**exemplo de estrutura de projeto**
```css
project/
├── bin/
│   └── (executáveis vão aqui)
├── src/
│   └── 01-first-program.c
```
seguindo a mesma lógica que anteriormente usamos o gcc para compilar `src/01-first-program.c` e salvar o executável em `bin/01-first-program`
```bash
gcc src/01-first-program.c -o bin/01-first-program
```
e agora para rodar o código dentro da pasta do projeto usamos `./bin/01-first-program`
