## **uma introdução a streams**
no contexto de C, uma stream é uma **abstração de fluxo contínuo de dados** - seja ele vindo *de* ou indo *para* algum lugar (como teclado, tela, arquivo, etc.)

> pensa numa stream como **um cano por onde os dados passam**, e seu programa só se preocupa em ler ou escrever nesse cano, em saber *como* ou *onde* os dados estão de verdade

existem 3 streams padrões em C, abertas automaticamente quando o programa começa:
| stream  | nome     | usada para...     | tipo em C |
| ------- | -------- | ----------------- | --------- |
| entrada | `stdin`  | ler do teclado    | `FILE *`  |
| saída   | `stdout` | escrever na tela  | `FILE *`  |
| erro    | `stderr` | mensagens de erro | `FILE *`  |

* stream em C é um ponteiro para uma estrutura de dados do tipo `FILE`, com funções da lib padrão `<stdio.h>` inclusas no cabeçalho
* C trata arquivos, teclados, telas... tudo como um fluxo de bytes sequenciais, e você acessa esses fluxos usando funções, como:
    * `fgetc()`, `fgets()` - leitura
    * `fputc()`, `fputs()`, `fprintf()` - escrita
    todas essas funções usam uma stream como argumento (`stdin`, `stdout`, `stderr`, ou outras são abertas com `fopen()`)

---

> *"stream em C é um ponteiro para uma estrutura de dados do tipo `FILE`." O que isso significa?*

ao trabalhar com entrada e saída de dados em C (como ler do teclado ou escrever em arquivos), você usa streams, que são fluxos de dados que vêm de algum lugar (como teclado, arquivos, etc.) ou vão para algum lugar (como tela ou arquivos)

```c
FILE *fp
```
aqui, `fp` é um ponteiro para uma struct `FILE` - essa estrutura guarda todas as informações necessárias para o sistema controlar a entrada/saída daquele aquivo (ou dispositivo)

*por que é um ponteiro?*
porque `FILE` é uma estrutura de dados complexa, com muitos campos internos:
* nome do arquivo
* posição atual do cursor
* modo de abertura (leitura, escrita, etc.)
* buffers internos
* flags de erro ou fim de arquivo

*obs* um buffer é uma região de memória usada para armazenar dados temporariamente enquanto eles são trasferidos entre diferentes partes de um sistema ou entre diferentes dispositivos. age como um "intermediário" para lidar com diferen;as de velocidade ou temporização entre processos

se lembre que sempre será melhor passar só o ponteiro do que passar uma estrutura inteiro para todo lado. C é "mão na massa" porque você manipula endereços de memória diretamente para ser mais eficiente

```c
struct FILE {
    int file_descriptor;
    char *buffer;
    int buffer_size;
    int mode;
    int position;
    // ... e muitos outros
};
```