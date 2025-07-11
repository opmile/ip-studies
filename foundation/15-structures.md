# structures
structures (structs) são uma forma de agrupar variáveis relacionadas em um único lugar, de modo que elas representem um todo

cada variável em um struct é considerado um membro do struct

diferentemente de um array, um struct pode conter diferentes tipos de dados para seus membros (`int`, `float`, `char`, etc.)

## criar um struct
podemos criar um struct usando a palavra-chave `struct` e declarar cada um de seus membros dentro de chaves
```c
struct MyStructure { // declaração de um struct
    int myNum; // memnbro (var int)
    char myLetter; // membro (var char)
}; // final do struct
```

para acessar um struct temos que criar uma variável para ele acompanhado da palavra-chave `struct` dentro do `main()`

```c
struct myStruct {
    int myNum;
    chat myLetter;
};

int main() {
    struct myStruct s1;
    return 0;
}
```

## acesso a membros
para acessar os membros de um struct, usamos a notação de ponto `.`
```c
struct myStruct {
    int myNum;
    chat myLetter;
};

int main() {

    struct myStruct s1;

    s1.myNum = 13;
    s1.myLetter = 'B';

    printf("my number: %d\n", s1.myNum);
    printf("my letter: %d\n", s1.myLetter);

    return 0;
}
```

agora podemos criar múltiplas variáveis struct com valores diferentes usando apenas um `struct`
```c
struct myStructure s1;
struct myStructure s2;

s1.myNum = 13;
s1.myLetter = 'B';

s2.myNum = 20;
s2.myLetter = 'C';
```

## string em structs
não podemos atribuir um valor a um array dessa forma:
```c
struct myStructure {
  int myNum;
  char myLetter;
  char myString[30];  // string
};

int main() {
  struct myStructure s1;

  s1.myString = "some text"; // error

  printf("My string: %s", s1.myString);

  return 0;
}
```
isso gera o seguinte erro:
```
prog.c:12:15: error: assignment to expression with array type
```

não podemos fazer `s1.myString = "some text"` quando `myString` é um `char[30]`. porque quando declaramos a string como `char myString[30]` estamos dizendo ao compilador:
> *"compilador, reserve 30 bytes contínuos aqui para guardar caracteres. esse espaço é fixo e diretamente embutido no struct"*

```c
s1.myString = "some text";
```
* `"some text"` é um **ponteiro constante** (`char*`) para um bloco de memória que contém a string
* mas `s1.myString` é um array de 30 caracteres já alocado na memória, não um ponteiro

isso acontece porque em C, um array é tratado como um bloco fixo de memória. ele não guarda um ponteiro internamente, ele é o próprio espaço de memória, ele é o ponteiro.
* com `char myString[30]`, o compilador aloca esses 30 bytes na stack (na memória do struct), e eles não podem ser substituídos por outro bloco de memória com `=`
* arrays não tem o comportamento de objetos atribuíveis


entretanto, se usarmos uma alternativa diferente:
```c
struct MyStruct {
    char *myString;
};
```
aqui estmaos dizendo que `myString` será um ponteiro para char, ou seja, vai apontar para algum endereço onde tem uma string. aí sim podemos fazer isso no `main()`:
```c
struct MyStruct s1;
s1.myString = "some text";`
```
agora sim `myString` é um ponteiro que aponta para uma string constante, e ponteiro podem receber novos endereços 

```c
s1.myString[0] = 'x'; // erro: comportamento indefinido
```
* `some text` é uma string literal armazenado em memória somente leitura. se queremos que nossa string seja mutável, devemos declarar a string como um array fixo `char[30]`

mas então qual seria a alternativa para atribuir um valor ao array que foi declarado com `char myString[30]` no struct?
* usamos o método `strcpy()` para copiar o conteúdo da string para o array
* seja `strcpy(destino, origem)` copia caractere por caractere até encontrar `\0`
* o array `s1.myString` já tem espaço alocado, então você só precisa preencher com os dados certos
```c
struct myStructure {
    int myNum;
    char myLetter;
    char myString[30];
};

int main() {
    struct myStructure s1;

    strcpy(s1.myString, "some text")

    printf("%s\n", s1.myString);

    return 0;
}
```

## sintaxe mais simples

1. **atribuição de valores dos memebros no momento da declaração da variável struct**
```c
struct myStruct {
    int myNum;
    char myLetter;
    char myString[30];
};

int main() {

    struct myStructure s1 = {13, '}

    return 0;
}
```