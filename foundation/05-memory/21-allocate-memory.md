# alocação de memória
o processo de revervar memória é chamado de alocação. a forma de alocação depende do tipo de memória

## memória estática e memória dinâmica
essa é uma classificação prática, *focada em como a memória é gerenciada no tempo de execução*, e não em todas as regiões da memória (como stack, heap, etc)

### static memory
aqui, static não significa qualquer memória que o **compilador aloca em tempo de compilação** ou de forma fixa no início da execução
* é a memória reservada para variáveis **antes** da execução do programa
* C automaticamente aloca memória para cada variável quando o programa é compilado

**inclui:**
* variáveis globais
* variáveis estáticas locais
* constantes
* funções
* em muitas definições, também inclui a stack, porque ela é alocada automaticamente pelo compilador antes da execução do programa

**características**
* tempo de vida: dura todo o tempo de execução do programa
* a memória é pré-reservada
* não precisa (nem pode) ser liberada manualmente

```c
int globalVar = 10; // global: memoria estatica
static int x = 10; // local estatica
void func() {
    int y = 3; // stack - ainda considerada memoria estatica
}
```

imagine que estamos criando um array de inteiros de 20 estudantes (para um período de verão/inverno, por exemplo), C vai reservar espaço para esses 20 elementos, que tipicamente ocupará 80 bytes de memória (20 * 4)
```c
int students[20];
printf("%zu\n", sizeof(students)); // 80 bytes
```

mas quando o semestre começa, descobrimos que na verdade apenas 12 estudantes comparecerão. então desperdiçamos espaço de 8 elementos subtilizados
* como você não pode mudar o tamanho de um array, isso te sobra com memória desnecessariamente reservada

o programa vai rodar, e ainda não foi comprometido de alguma forma, mas se seu programa possui muito desperdício, como esse, com certeza será mais lento do que idealmente poderia
* se quisermos ter melhor controle da alocação de memória, temos que entender como funciona a memória dinâmica

### dynamic memory
essa é a memória que o dev aloca *manualmente*, usando funções como `malloc`, `calloc`, `realloc`, e libera com `free`. alocação de memória dinâmica pode ser referenciada como **alocação de memória em tempo de execução**
* é a memória reservada depois do começo da execução do programa
* controle total de quanta memória está sendo usada 
* memória dinâmica não pertence a uma variável, e só pode ser acessada por ponteiros
*onde fica?* na heap!

**características**
* tempo de vida: você controla (só acaba quando chamar `free`)
* ideal para estruturas que mudam de tamanho (listas, árvores, buffers)
* mais flexível, mas mais perigosa (vazamentos, ponteiros soltos...)

```c
int *vetor = malloc(10 * sizeof(int)); // memeria dinamica
free(vetor);
```

para alocar memória dinâmica usamos `malloc()` ou `calloc` que são funções que alocam um espaço na memória e retornam um ponteiro com seu endereço
* é necessário incluir `<stdlib.h>` para seu uso

```c
int *ptr1 = malloc(size);
int *ptr2 = calloc(amount, size);
```
* `malloc()`: `size` como único parâmetro, que especifica quanta memória será alocada, medida em bytes
* `calloc()`: dois parâmetros
    * `amount`: especifica a quantidade de itens a serem alocados
    * `size`: especifica o tamanho de cada item medido em bytes

*obs*: a memória que você aloca com `malloc()` pode conter qualquer lixo (valores aleatórios que já estavam lá antes). portanto, você nunca deve ler essa memória antes de escrever algo nela, senão vai ler dados imprevisíveis
* porque `malloc()` simplesmente reserva um espaço na heap, ele não zera ou limpa essa espaço. como a memória RAM é usada por muitos programas, quando você aloca um bloco, ele pode conter:
    * bytes de outros dados antigos
    * valores aleatórios que sobraram da execução anterior
    * ou até padrões não definidos
* `malloc()` é mais rápido porque não inicaliza nada, se quiser memória zerada, deve usar `calloc()`

fazendo errado:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int len = 5;
    int *ptr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        printf("numeros[%d]: %d\n", i, *(ptr + i)); // nao faz isso animal!!
    }
    
    free(numeros);

    return 0;
}
```
saída possível:
```
numeros[0] = 32764
numeros[1] = -132574
numeros[2] = 0
numeros[3] = 10938423
numeros[4] = 1
```

fazendo certo:
1. inicializar manualmente
```c
for (int i = 0; i < len; i++) {
    *(numeros + i) = 0; // ou qualquer valor padrão
}
```

2. usar `calloc()` pra já vir inicializado com valores padrão zerados
```c
int* numeros = calloc(5, sizeof(int));
```
* entretanto, esse comportamento de já vir com valores padrão (0) torna `calloc()` um pouco menos efiiciente do que `malloc()`
* isso porque `calloc()` precisa percorrer byte por byte e escrever 0 em cada um, e isso é considerado um trabalho extra quando comparado com `malloc()`, que só reserva o espaço, sem tocar em seu conteúdo

a melhor forma de alocar a quantidade certa de memória para os tipos de dados que trabalhamos é usando a função `sizeof()`
```c
int *ptr1, *ptr2;
ptr1 = malloc(sizeof(*ptr1));
ptr2 = calloc(1, sizeof(*ptr2));
```
*cuidado!*
* `sizeof(*ptr1)` indica ao C para pedir o tamanho dos dados naquele endereço. esquecer o operador de desreferenciação `*` significa medir o tamanho do ponteiro em si (tipicamente 8 bytes)

note que a função `sizeof()` não consegue medir quanto de memíria dinâmica está sendo alocada
* é um operador em tempo de compilação (o compilador resolve ele antes de o programa rodar)
* isso significa que o operador não tem como saber quantos bytes você pediu com `malloc()` ou `calloc()` porque essa informação não está associada ao ponteiro em si

vamos melhorar agora o exemplo anterior dos estudantes no semestre de verão
```c
int *students;
int numStudents = 12;
studentes = calloc(numStudents, sizeof(*students));
printf("%d\n", numStudents * sizeof(*students)); // 48 bytes
```

**notas:**
quando se trabalha com alocação de memória dinâmica, você deve checar por erros e o espaço livre de memória no final do programa (aprenderemos isso mais tarde)