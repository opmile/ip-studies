# structures
**structures (structs)** são uma forma de agrupar variáveis relacionadas em um único lugar, de modo que elas representem um todo: uma única estrutura

cada variável em um struct é considerado um *membro* do struct

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
* aqui sempre precisamos escrever `struct MyStruct` toda vez que declarar uma variável ou ponteiro desse tipo

existe também uma outra forma de criar structs que é um pouco mais preferível por tornar o código mais organizado e legível

```c
typedef struct {
    int cpf;
    char nome_cliente[50];
    char email[50];
    char endereco[100];
    char telefone[50];
    float valor_total_gasto;
} Cliente;
```
para depois usar:
```c
Cliente c1;
```
* aqui `typedef` cria um apelido (um alias) para o tipo `struct` sem precisar usar a palavra-chave `struct` no momento da declaração da variável
* temos uma aproximação maior com a orientação a objetos, de certa forma

mas em projetos maiores ainda podemos encontrar
```c
typedef struct Cliente {
    int cpf;
    char nome_completo[50];
    ...
} Cliente;
```
* nesse caso podemos usar tanto `struct Cliente` quanto só `Cliente`


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
* mas `s1.myString` é um array de 30 caracteres já alocado na memória e embutido no struct, não um ponteiro

isso acontece porque em C, um array é tratado como um bloco fixo de memória. ele não guarda um ponteiro internamente, ele é o próprio espaço de memória. enquanto isso, seu identificador (nome) é tratado como um ponteiro que aponta para seu primeiro elemento
* com `char myString[30]`, o compilador aloca esses 30 bytes na stack (na memória do struct), e eles não podem ser substituídos por outro bloco de memória com `=`
* arrays não tem o comportamento de objetos atribuíveis


entretanto, se usarmos uma alternativa diferente:
```c
struct MyStruct {
    char *myString;
};
```
aqui estamos dizendo que `myString` será um ponteiro para char, ou seja, vai apontar para algum endereço onde tem uma string. aí sim podemos fazer isso no `main()`:
```c
struct MyStruct s1;
s1.myString = "some text";`
```
agora sim `myString` é um ponteiro que aponta para uma string constante, e ponteiros são reatribuíveis e podem receber novos endereços 

entretanto,
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

e se declararmos uma string da seguinte forma:
```c
struct myStruct {
    char myString[]; // erro
}
```
o compilador precisa saber o tamanho do array na hora de alocar memória do struct e com `char myString[]` não estamos dizendo qual é o tamanho 

## sintaxe mais simples
**atribuição de valores dos membros no momento da declaração da variável struct**
```c
struct myStruct {
    int myNum;
    char myLetter;
    char myString[30];
};

int main() {

    struct myStructure s1 = {13, 'B', "some text"};
    
    printf("%d %c %s\n", s1.myNum, s1.myLetter, s1.myString;);

    return 0;
}
```
* a ordem dos valores inseridos devem bater com a ordem das variáveis declaradas dentro do struct

## copiar estruturas
podemos atribuir uma estrutura à outra
```c
struct myStruct {
    int myNum;
    char myLetter;
    char myString[30];
};

int main() {

    struct myStructure s1 = {13, 'B', "some text"};
    struct myStructure s2;

    s2 = s1;

    return 0;
}
```
* `s2` agora carrega as mesmas referências de `s1`

## modificar valores
se queremos mudar/modificar um valor, ainda usamos a notação de ponto `.`
* para modificar o valor de uma string, ainda usamos o método `strcpy()`
```c
struct myStructure {
    int myNum;
    char myLetter;
    char myString[30];
};

int main() {
    struct myStruct s1 = {13, 'B', "some text"};

    s1.myNum = 14;
    s1.myLetter = 'M';
    strcpy(s1.myString, "something else");

    printf("%d %c %s", s1.myNum, s1.myLetter, s1.myString);

    return 0;
}
```
modificar valores se torna especialmente útil quando se copia valores de estruturas
```c
struct myStructure s1 = {13, 'B', "some text"};
struct myStructure s2;

// copiar valores de s1 para s2
s2 = s1;

// alterar valores de s2
s2.myNum = 30;
s2.myLetter = 'C';
strcpy(s2.myString, "something else");

// Print values
printf("%d %c %s\n", s1.myNum, s1.myLetter, s1.myString);
printf("%d %c %s\n", s2.myNum, s2.myLetter, s2.myString);
```
isso copia todos os campos de `s1` para `s2`, byte por byte - ou seja:
* `s2.myNum` vai ter uma cópia do número `13`
* `s2.myLetter` vai ter uma cópia do char `'B'`
* `s2.myString` vai ter uma *cópia dos 30 caracteres do array* de `s1.myString`

cada campo é copiado separadamente, ou seja, `s1` e `s2` ficam independente um do outro

é importante frisar isso porque em linguagens orientadas a objetos, Java por exemplo, `s1` e `s2` são considerados ponteiros para um objetos, isso significa que a variável não contêm o conteúdo mas uma referência a um objeto
* como são referências de objeto, ao usar `s2 = s1`, em java, isso significa que agora temos dois ponteiros que apontam para um mesmo objeto, e modificar o valor de algum atributo pode ser feito por `s1` ou por `s2`

`struct` é uma estrutura que, sob a ótica da orientação a objetos, pode ser considerada quase primitiva já que surgiu para agrupar valores que fazem sentido uando agrupados
* imagine que queremos armazenar diferentes inforções sobre carros, como marca, modelo, ano, preço de mercado... com struct, criamos um template para um carro e usamos para cada carro criado no programa