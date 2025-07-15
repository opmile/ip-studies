# manipulação de arquivos
em C, você pode criar, abrir, ler e escrever em arquivos declarando um ponteiro do tipo `FILE` e usando a função `fopen()`
```c
FILE *fptr;
ftpr = fopen(filename, mode);
```

* `FILE` é basicamente um tipo de dado, e precisamos criar um ponteiro para trabalhar com epe (`ftpr`)

usamos a função `fopen()` para abrir arquivos, e ela aceita dois parâmtros
* `filename` - o nome do arquivo que queremos abrir (ou criar), como `filename.txt`
* `mode` - caractere úninco que indica o que queremos fazer com o arquivo (ler, escrever ou adicionar)
    * `w` - escerever em um arquivo
    * `a` - adicionar novos dados no arquivo
    * `r` - ler do arquivo

## criar um arquivo
para criar um arquivo, podemos usar o mode `w` dentro da função `fopen()`
* o mode `w` é usada para escrever no arquivo, entretanto, se o arquivo ainda não existe, um novo arquivo é crado para o chamador
```c
FILE *ftpr

// cria um arquivo
ftpr = fopen("filename.txt", "w");

// fecha o arquivo
fclose(ftpr);
```
* note que o arquivo é criado no mesmo diretório que os outros arquivos C se nada for especificado
* se queremos criar um novo arquivo em uma pasta específica, apenas retorne o caminho absoluto onde o arquivo deve ser salvo (se lembre de usar `\\` para criar um único `\\` na string)
```c
fptr = fopen("C:\\directoryname\\filename.txt", "w");
```

a função `fclose()` fecha o arquivo quando terminamos nossa manipulação. é uma boa prática porque garante que:
* mudanças são salvas de forma apopriada
* outros programas podem usar o arquivo
* limpa espaço desnecessário na memória

## escrever em um arquivo
o mode `w` significa escrita no arquivo aberto. para inserir conteúdo nesse arquivo, usamos a função `fprintf()` e adicionamos nosso ponteiro `fptr`
```c
FILE *ftpr;

// abre o arquivo no modo de escrita
ftpr = fopen("filename.txt", "w");

// escreve algum texto no arquivo
fprintf(ftpr, "some text");

// fecha o arquivo
fclose(ftpr);
```

se você escrever em um arquivo que já existe, o conteúdo antigo será deletado, e o novo conteúdo será inserido. cuidado para não apagar conteúdo já existente

## adicionar conteúdo em um arquivo
se queremos adicionar novo conteúdo sem deletar o conteúd antigo já inserido, usamos o modo `a` que adiciona novos conteúdos ao final do documento

```c
FILE *ftpr;

// abre o arquivo no modo de adição de conteúdo
ftpr = fopoen("filename.txt", "a");

// adicionar novo conteúdo de texto ao arquivo
fprintf(ftpr, "\nhi everybody");

fclose(ftpr);
```

assim como no modo `w`, se o arquivo ainda não existir, o modo `a` cria um novo arquivo com o conteúdo adicionado

## ler um arquivo
para ler um arquivo usando `fopen()` devemos abrir o arquivo no modo `r`
```c
FILE *ftpr;

ftpr = fopen("filename.txt", "r");
```
* isso para `filename.txt` aberto para leitura

agora precisamos criar uma string que deve ser grande o suficiente para comportar o conteúdo do arquivo
```c
char myString[100]
```

para ler o arquivo precisaremos da função `fgets()` que aceita 3 parâmetros
```c
fgets(myString, 100, ftpr);
```
1. o primeiro parâmetro especifica onde armazenar o conteúdo, que será referente ao array `myString` criado
2. o segundo parâmetro que especifica o tamanho máximo de dados a serem lidos, que deve corresponder ao tamanho de `myString`
3. o terceiro parâmetro que requere um ponteiro de arquivo que é usado para ler os dados

```c
FILE *ftpr;

ftpr = fopen("filename.txt", "r");

char myString[100];

fgets(myString, 100, ftpr)

printf("%s\n", myString);

fclose(ftpr)
```

a função `fgets()` apenas lê a primeira linha do arquivo. se tivermos mais linhas no arquivo, podemos iterá-lo com um loop `while`
```c
FILE *ftpr;

ftpr = fopen("filename.txt", "r");

char myString[100];

while(fgets(myString, 100, ftpr)) {
    printf("%s\n", myString);
}

fclose(ftpr);
```

tentar abrir para leitura um arquivo que não existe força a função `fopen()` a retonnar `NULL`
* como uma boa prática, é importante incluir um condicional que confere se o arquivo retorna `NULL`

```c
FILE *fptr;

// abre o arquivo no modo de leitura
fptr = fopen("loremipsum.txt", "r");

// imprime texto se o arquivo não existir
if(fptr == NULL) {
  printf("Not able to open the file.");
}

fclose(fptr);
```

então nosso código final é
```c
FILE *fptr;

// Open a file in read mode
fptr = fopen("filename.txt", "r");

char myString[100];

// se o arquivo existe
if(fptr != NULL) {

  // Read the content and print it
  while(fgets(myString, 100, fptr)) {
    printf("%s", myString);
  }

// se o arquivo não existe
} else {
  printf("Not able to open the file.");
}

fclose(fptr);
```