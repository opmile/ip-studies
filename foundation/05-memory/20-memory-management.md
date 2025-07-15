# gerenciamento de memória
gerenciamento de memória é o processo de manipular quanta memória um programa usa ao longo de diferentes operações

## memória em C
memória é o espaço onde seu programa guarda dados temporariamente enquanto está rodando. ela é volátil - ou seja, tudo se perde quando o programa termina
* por isso surge a persistência de dados, que consiste em armazenar dados de alguma forma (em um arquivo `.txt`, `.json`...) para que tenhamos informações salvas das execuções passadas

e na lingaugem C você trabalha a linha de frente com o controle desses espaços - ao contrário de linguagens como Python ou Java (que têm o *garbage collector*)

quando você cria uma variável comum, C vai automaticamente reservar espaço para essa variável. uma variável inteira int, por exemplo, vai tipicamente ocupar `4` bytes de memória, enquanto uma variável double vai ocupar `8` bytes

usamos `sizeof()` para descobrir o tamanho dos diferentes tipos
```c
int myInt;
float myFloat;
double myDouble;
char myChar;

printf("%zu\n", sizeof(myInt));      // 4 bytes
printf("%zu\n", sizeof(myFloat));    // 4 bytes
printf("%zu\n", sizeof(myDouble));   // 8 bytes
printf("%zu\n", sizeof(myChar));     // 1 byte
```

**por que isso importa?**
se você criar um programa que ocupa muito ou que usa memória desnecessária, pode resultar em performance lenta

em C, você é quem tem que trabalhar na linha de frente no controle desses espaços, diferente de outras linguagens de programação, como Python ou Java (que tem o *garbage collector*)
é uma tarefa um pouco complicada mas muito poderosa quando usada corretamente: gerenciar propriamente a memória do computador otimiza a performance do programa, então é útil saber como desocupar memória quando não é mais usada e ocupar apenas o necessário

em capítulos anteriores, você aprendeu sobre endereços de memória e ponteiros. ambos são de grande importante quando se diz sobre gerenciamento de memória, já que é possível trabalhar diretamente com a mamória atráves de ponteiros

novamente, tome cuidado! ponteiros devem ser usados com cuidados, já que é possível danificar ou corromper dados armazenados em outros endereços de memória

**o que é gerenciamento de memória?**
gerenciamento de memória é o processo de manipular quanto de memória um programa usa através de *alocação, realocação e dealocação* (ou "freeing")
* essas funções podem ser importadas usando `#include <stdlib.h>` no cabeçalho do arquivo (standard library)

## tipos de memória
quando você executa um programa em C, o sistema operacional aloca para ele um espaço contínuo de memória dividido logicalmente em regiões

*visualmente*
```less
endereços baixos
|
|  [Text Segment]       ← código do programa (instruções compiladas)
|  [Data Segment]       ← globais/estáticas inicializadas
|  [BSS Segment]        ← globais/estáticas não inicializadas
|  [Heap] ↑             ← cresce para cima
|                       ← espaço livre (gap entre heap e stack)
|  [Stack] ↓            ← cresce para baixo
|
endereços altos
```

1. **stack (pilha)**
* usada para variáveis locais, parâmetros e chamadas de função, endereços de retorno (controle da execução)
* cresce de endereços altos para baixos (ao contrário da heap)
* rápida mas limitada em tamanho
* liberada automaticamente quando a função retorna
* gerenciada pelo compilador
```c
int x = 10; // alocado na stack
```

2. **heap (montão)**
* usada para alocação dinâmica de memória
* cresce de endereços baixos para alto
* controlada pelo programador com `malloc`, `calloc`, `realloc`, e `free`
* perfeita para estruturas de dados que mudam de tamanho como listas, árvores, grafos
* mais lenta, mas flexível

*os ponteiros ficam na heap?* depende de como você declarou
```c
int* p = malloc(sizeof(int)); // ponteiro para um int na heap
```
* o conteúdo apontado (`*p`) está na heap
* o ponteiro `p` em si é uma variável local - está na stack

ponteiros geralmente moram na mesma região onde são declarados. mas o que eles apontam pode estar na heap, stack, data... depende!

3. **data segment**
* armazena variáveis globais e estáticas inicializadas
```c
int contador = 0; // variavel global -> data segment
```

4. **bss segment**
* armazena variáveis globais e estáticas não inicializadas
```c
static int tempo; // sem valor inicial -> bss
```

5. **text segment (ou code segment)**
* armazena as intruções do programa, ou seja, o código executável
* é somente leitura na maioria dos sistemas operacionais modernos 
ex.) funções compiladas, inclusive `main()`

### tipos de gerenciamento de memória

**alocação**: reservar espaço na memória
em C, para a heap, usamos:
* `malloc`: aloca um bloco sem inicializar
* `calloc`: aloca e inicializa com 0
* `realloc`: redimensiona um bloco existente
* `free`: libera um bloco previamente alocado

**realocação**: aumentar ou reduzir o tamanho de um bloco já alocado
usamos `realloc(ptr, novo_tamanho)`
```c
int* nums = malloc(5 * sizeof(int));
// agora quero 10 posições
nums = realloc(nums. 10 * sizeof(int));
```

**desalocação (dealocar)**
liberar a memória para que o sistema possa usá-la novamente
feita com `free`
```c
free(nums); // sempre libere o que alocou!
```

### cuidados essenciais
1. **vazamento de memória (memory leak)**
se você alocar memória mas nunca libear, seu programa vai consumir memória sem fim. isso é péssimo, especialmente em programas longos ou em sistemas embarcados

2. **acesso a memória inválida**
ler ou escrever onde não deveria (como acessar um ponteiro não inicializado ou já liberado) pode causar erros sérios (como *segment fault*)

3. **double free**
liberar duas vezes o mesmo ponteiro é perigoso e pode corromper a heap

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* vetor = malloc(5 * sizeof(int)); // aloca 5 ints

    if (vetor == NULL) {
        printf("erro ao alocar memória\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        vetor[i] = i * 2;
        printf("%d\n", vetor[i]);
    }

    vetor = realloc(vetor, 10 * sizeof(int)); // aumenta para 10 ints

    free(vetor); // libera a memória
    return 0;
}
```
---
## memória estática e memória dinâmica
essa é uma classificação prática, focada em como a memória é gerenciada no tempo de execução, e não em todas as regiões da memória (como stack, heap, etc)

### static memory
aqui, static não significa só a palavra-chave `static`, mas sim qualquer memória que o compilador aloca em tempo de compilação ou de forma fixa no início da execução
inclui:
* variáveis globais
* variáveis estáticas locais
* constantes
* funções
* em muitas definições, também incluir a stack
