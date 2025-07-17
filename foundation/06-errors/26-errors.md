# erros
esse capítulo se dedica a expor os erros mais comuns e te ajuda no debbuing com dicas para te ajudr a entender o que está dando errado e como concertar

### erros comuns de tempo de compilação 
erros de tempo de compilação são problemas que fazem seu programa não compilar

1. **missing semicolon**
```c
#include <stdio.h>

int main() {
  int x = 5
  printf("%d", x);
  return 0;
}
```
```
error: expected ',' or ';' before 'printf'
```

2. **undeclared variables**
```c
#include <stdio.h>

int main() {
  printf("%d", myVar);
  return 0;
}
```
```
error: 'myVar' undeclared
```

3. **mismatched types** (atribuir `string` a um `int`)
```c
#include <stdio.h>

int main() {
  int x = "Hello";
  return 0;
}
```
```
error: initialization makes integer from pointer without a cast
```

### erros comuns de tempo de execução
erros de tempo de execução acontecem quando o programa compila mas da crash ou se comporta de forma inesperada

1. **dividing by zero**
```c
#include <stdio.h>

int main() {
  int x = 10;
  int y = 0;
  int result = x / y;
  printf("%d\\n", result); // not possible
  return 0;
}
```

2. **acessing out-of-bounds array elements**
```c
#include <stdio.h>

int main() {
  int numbers[3] = {1, 2, 3};
  printf("%d\\n", numbers[8]); // element does not exist
  return 0;
}
```

3. **using freed memory**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr = malloc(sizeof(int));
  *ptr = 10;
  free(ptr);
  printf("%d\\n", *ptr); // Undefined behavior - accessing memory that was freed
  return 0;
}
```

### boas práticas para evitar erros
* sempre inicialize suas variáveis
* use nomes significativos para suas variáveis
* mantenha seu código limpo e identado
* mantenha funções pequenas e focadas
* cheque se loops ou condicionais estão correndo como esperado
* leia mensagens de erro com cuidado - normalmente elas te contam exatamente onde está o problema

## `NULL`
`NULL` é um valor especial que representa "ponteiro nulo" - um ponteiro que não aponta para lugar algum na memória

isso te ajuda a usar ponteiros que estão vazios ou inválidos. fazemos isso checando se um ponteiro aponta para `NULL` para seu uso seguro
* fizemos isso no capítulo anterior
```c
int len = 10;

int *arr = malloc(len * sizeof(int));

int *arr = realloc(arr, 2 * len * sizeof(*arr));

if (arr == NULL) {
    printf("não foi possível realocar memória");
    return 1;
}

free(arr);
arr = NULL; // agora podemos reutilizar esse ponteiro
```

muitas funções C retornam `NULL` quando algo da errado
* `fopen()` retorna `NULL` se um arquivo não pode ser aberto
* `malloc()` retorna `NULL` se a alocação de memória falhar

podemos checar por isso usando blocos condicionais `if` e imprimir uma mensagem de erro quando algo da errado
```c
#include <stdio.h>

int main () {
    FILE *fptr = fopen("nothing.txt", "r");

    if (fptr == NULL) {
        printf("impossível abrir arquivo \n");
        return 1;
    }

    fclose(fptr);
    return 0;
}
```

tentar alocar muita memória com `malloc()` pode falhar e retornar `NULL`
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = (int*) malloc(10000000000000000000 * sizeof(int));

    if (numbers == NULL) {
        printf("alocação de memória falhou \n");
        return 1;
    }

    printf("sucesso em alocar memória \n");

    free(numbers);
    numbers = NULL;

    return 0;
}
```

## manipulando erros
manipulação de erros te ajuda a detectar e responder a problemas no seu programa, como um arquivo que não pode ser aberto ou memória que não pode ser alocada, para que seu progama não de crash ou se comporte de forma inesperada

ao contrátio de outras linguagens, como Java, C não tem um sistema built-in de manipulação de exceções (como **try/catch**). na verdade, C retorna valores, códigos de erros globais, e funções auxiliares como `perror()` e `strerror()`

### usando valores de retorno
falha de abrir arquivo com `fopen()`
```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("nothing.txt", "r");

    if (ftpr == NULL) {
        printf("impossível abrir arquivo \n");
        return 1;
    }

    fclose(ftpr)
    return 0;
}
```
```
impossível abrir arquivo
```

### extrair detalhes
se queremos mais detalhes do que deu errado, podemos usar `perror()` que imprime uma mensagem customizada de erro seguida de uma descrição do último erro registrado
```c
#include <stdio.h>

int main() {
  FILE *f = fopen("nothing.txt", "r");

  if (f == NULL) {
    perror("erro ao abrir arquivo");
    return 1;
  }

  fclose(f);
  return 0;
}
```
```
erro ao abrir arquivo: No such file or directory
```

### usando `strerror()` and `errno`
`errno` é uma variável glocal que armazena o código de erro da última operação falha. para usá-lo, você deve incluir `<errno.h>` para acessá-lo e `strerror(errno)` vai converter o código de erro em uma mensagem legível
```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    file *f = fopen("nothing.txt", "r");

    if (f == NULL) {
        printf("erro: %s\n", strerror(errno));
        return 1;
    }
    
    fclose(f);
    return 0;
}
```
```
erro: No such file or directory
```

#### código de erro comuns
constantes de erro definidas em `<errno.h>`
* você pode compará-las com `errno` para detectar problemas especíicos

| código de erro |        significado        |
| -------------- | ------------------------- |
|   `ENOENT`     | No such file or directory |
|   `EACCES`     |      Permission denied    |
|   `ENOMEM`     |      Not enough memory    | 
|   `ENINVAL`    |      Invalid argument     |

mensagem customizada para `ENOENT`
```c
#include <stdio.h>
#include <errno.h>

int main() {
  FILE *f = fopen("nothing.txt", "r");

  if (f == NULL) {
    if (errno == ENOENT) {
      printf("The file was not found.\n");
    } else {
      printf("Some other file error occurred.\n");
    }
    return 1;
  }

  fclose(f);
  return 0;
}
```

### usando `exit()` para parar o programa
se você precisa que o programa pare imediatamente quando um erro acontece, você pode usar `exit()`. essa função te permite retornar um código de status para o sistema operacional

códigos de saída te ajudam a sinalizar se o programa terminou com sucesso ou se ocorreu um erro, como:
* `0` significa sucesso
* valores diferentes de zero (`1` ou `EXIST_FAILURE`) indica erro
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = fopen("nothing.txt", "r");

  if (f == NULL) {
    printf("Failed to open file.\n");
    exit(1);
  }

  fclose(f);
  return 0;
}
```
```
Failed to open file.
```

#### códigos de status de saída comuns 
| código de erro |  significado |
| -------------- | ------------ |
|      `0`       |   sucesso    |
|      `1`       |    erro      |
| `EXIT_SUCCESS` |   sucesso    |
| `EXIT_FAILURE` |    erro      |
* `EXIT_SUCCESS` e `EXIT_FAILURE` estão denifidas em `<stdlib.h>` e são comumente usar para tornar o código mais legível

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *f = fopen("nothing.txt", "r");

  if (f == NULL) {
    perror("Could not open nothing.txt");
    exit(EXIT_FAILURE); // More readable than exit(1)
  }

  fclose(f);
  return EXIT_SUCCESS;
}
```

## validação de input
quando o usuário insere dados no programa, ele pode digitar algo inesperado. a validação do input o torna correto antes do programa continuar
* sem essa validação o programa está exposto para dar crash

ex) *checar se um número está dentro de um intervalo válido*
```c
#include <stdio.h>

int main() {
    int number;

    do {
        printf("escolha um número entre 1 e 5");
        scanf("%d", &number);
        while (getchar() != '\n');
    } while (number < 1 || number > 5); // continua pedindo até que o número esteja entre 1 e 5

    printf("voce escolheu: %d\n", number);
    
    return 0;
}
```
```
escolha um número entre 1 e 5: 8
escolha um número entre 1 e 5: -2
escolha um número entre 1 e 5: 4
voce escolheu: 4
```

o papel do `getchar()` é o de limpar a bagunça deixada no buffer de entrada (stdin) depois do `scanf()`
o `scanf()` lê apenas o número, mas deixa o caractere enter `\n` e qualquer outra sujeira (como letras ou espaços extras) no buffer de entrada (stdin)
se tivessemos digitado:
```
42xyz
```
* `scanf("%d", &number)` lê o 42
* deixa o `xyz\n` no buffer
* isso pode zoar a próxima leitura

`while (getchar() != '\n')` vai ler caractere por caractere do buffer até encontrar `'\n'`, descartando tudo que estava ali - ou seja, ele faz tipo uma "faxina" na entrada antes da próxima leitura com `scanf()`

o papel do `getchar()` não é o de limpar a bagunça, na verdade a definição formal da função é o de ler um único caractere do `stdin` (entrada padrão, normalmente teclado) e retornar o valor numérico ASCII desse caractere
* nesse programa, estamos usando essa leitura de caractere, um por um, para descartar tudo que sobrou do buffer, até encontrar a tecla enter `\n`
* estamos lendo caractere por caractere e testando seus valores ASCII até achar o `\n`

ex) checar se um nome não esta vazio
```c
#include <stdio.h>

int main() {
    char name[100];

    do {
        printf("digite seu nome: ");
        fgets(name, sizeof(name), stdin); // lê input como string
        name[strcspn(name, "\n")] = 0; // remove o caractere enter
    } while (strlen(name) == 0); // repete enquanto o input está vazio

    printf("oi, %s\n", name);
    return 0;
}
```
digite seu nome: 
digite seu nome: 
digite seu nome: milena
oi, milena
```

ex) garanta que o usuário insira um número como input
```c
#include <stdio.h>

int main() {
  int number;       // Variable to store the user's number
  char input[100];  // Buffer to hold user input as a string

  printf("Enter a number: ");

  // Keep reading input until the user enters a valid integer
  while (fgets(input, sizeof(input), stdin)) {
    // Try to read an integer from the input string
    if (sscanf(input, "%d", &number) == 1) {
      break; // Success: break out of the loop
    } else {
      printf("Invalid input. Try again: "); // If not an integer, ask again
    }
  }

  // Print the valid number entered by the user
  printf("You entered: %d\n", number);
  return 0;
}
```
para mais informações sobre `sscanf()`: https://www.w3schools.com/c/ref_stdio_sscanf.php