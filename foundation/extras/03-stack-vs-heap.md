> a *stack* cresce de endereços altos para baixos e a *heap* cresce de endereços baixos para altos

isso implica em entender como a memória RAM é organizada e como o sistema operacional distribui espaço para o programa

---

## a memória é uma linha contínua de endereços
pensa na memória RAM como um vetor gigante de bytes, com um início (endereços baixos) e um fim (endereços altos)
```
+--------------------+ → endereço 0 (baixo)
| código (text)      |
| dados globais      |
| heap               | ← cresce pra cima (endereços maiores)
| ... espaço livre   |
| stack              | ← cresce pra baixo (endereços menores)
+--------------------+ → endereço Máximo (alto)
```

### STACK: cresce de endereços altos para baixos
isso significa que:
* a stack começa no topo da memória do programa (endereços altos)
* a cada chamada de função, ela usa mais memória "para baixo"
* quando a função termina, a stack "sobe" de volta liberando espaço

```c
endereços altos
|
| ← stack frame da função main
| ← stack frame da função func1
| ← stack frame da função func2
|
endereços baixos
```
* cada `stack frame` (bloco de memória da função) ocupa esáço abaixo do anterior

### HEAP: cresde de endereços baixos para altos
* a heap começa logo abaixo dos dados globais, em endereços baixos
* usar `malloc`/`calloc` faz o sistema reservar espaço mais pra cima na memória
* cada nova alocação "empurra" a heap em direção ao meio da memória

```c
endereços baixos
|
| heap (malloc de 100 bytes)
| heap (malloc de mais 100 bytes)
|
| ← espaço livre entre heap e stack
|
endereços altos
```

### stack e heap crescem em direções opostas
essa separação é estratégica:
* quando a heap cresce (aloca memória dinamicamente), ela sobe
* quando a stack cresce (chama mais funções), ela desce
* isso cria um **colchão de memória** entre as duas regiões que evita soluções e deteca conflitos

se elas se encontrarem... BOOM - **stack overflow** ou **heap overflow**

1. stack é previsível: o compilador sabe quanto espaço cada função precisa
2. heap é felxível: cresce conforme você usa `malloc`, perfeita para dados dinâmicos