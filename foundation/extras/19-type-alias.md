# estudando o `typedef`
`typedef` (type definition) permite criar um apelido (alias) para um tipo de dado
> estruturalmente, ele não cria um novo tipo, mas renomeia algo para facilitar o uso ou dar mais sentido semântico

```c
typedef int inteiro;

inteiro idade = 20;
```
agora podeos usar `inteiro` no lugar de `int`


**nome com tamanho fixo**
```c
#define NOME_TAM 100
typedef char Nome[NOME_TAM];

// são equivalentes!
Nome cliente;
char cliente[100];
```
se depois quiser mudar o tamanho do nome para 150, é só mudar #define NOME_TAM 150, e tudo se atualiza automaticamente

quando usamos caracteres, é uma boa prática defini-los como `unsigned char` ao invés de `char`
isso porque o tipo `char`em C tem duas versões:
| tipo            | intervalo de valores      | exemplo de uso             |
| --------------- | ------------------------- | -------------------------- |
| `char`          | -128 a 127 **ou** 0 a 255 | depende do compilador      |
| `signed char`   | **-128 a 127**            | armazena valores negativos |
| `unsigned char` | **0 a 255**               | só valores positivos       |

usar `unsigned char` garante que valores acima de 127 não sejam transformados em negativos, de modo a proteger contra bugs ao lidar com caracteres acentuados ou strings binárias.

riscos de usar valores char como negativos:
| risco              | o que pode acontecer                                            |
| ------------------ | --------------------------------------------------------------- |
| comparações        | valores negativos quebram lógicas de tipo                       |
| indexação          | pode acessar `array[-alguma_coisa]` sem querer                  |
| bibliotecas padrão | podem segfaultar com `char` negativo                            |
| portabilidade      | um compilador trata `char` como `signed`, outro como `unsigned` |
