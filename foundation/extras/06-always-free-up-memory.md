# todo espaço alocado deve ser liberado
todo espaço alocado com `malloc` ou `calloc` deve ser liberado com `free`, sempre

## por que isso é tão importante?
quando você usa `malloc` ou `calloc`, está pegando memória a heap - uma área de memória que não é automaticamente liberada quando a função termina, ao contrário da memória stack
* se lembre que quando o programa começa a stack inicia no topo da memória (endereços mais altos). quando ocorre a chamada de uma função, ela usa memória mais para baixo a cada variável local para ser armazenada. quando a função termina, ela "sobe" de volta liberando espaço

se você não usar `free()` depois, a memória fica ocupada pelo seu programa mesmo sem estar sendo usada, e a isso damos o nome de 
### "memory leak" (vazamento de memória)

**consequências de não usar `free`**
1. seu programa vai consumir mais e mais RAM à medida que roda, mesmo que não precise mais daquela memória

2. em programas pequenos, o sistema pode até "ignorar" esse desperdício

3. em programas gandes ou servidores, isso pode causar:
    * falta de memória
    * crashs
    * travamentos
    * lentidão
    * dor de cabeça para debugar

**importante**
* nunca use `free()` com ponteiros que:
    * não foram alocados com `malloc/calloc/realloc`
    * já foram liberados (double free)
    * apontam para variáveis da stack

> *se fez um `malloc`, tenha a responsabilidade de dar um `free` depois