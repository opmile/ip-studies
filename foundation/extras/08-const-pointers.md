# ponteiro constante
se usarmos `const` no parâmetro de uma função que recebe um ponteiro, como:
```c
void printList(const List *list)
```
é uma medida de proteção e clareza, considerada uma boa prática

`const List *list` é uma declaração que significa:
> *"a função `printList` receberá um ponteiro para uma `List`, mas não tem permissão para modificar o conteúdo dessa struct"*

**por que isso é útil?**
1. *evita modificações acidentais*
se dentro de `printList` alguém tentar fazer:
```c
list->numItems = 0;
```
o compilador vai bloquear porque não se pode alterar uma struct marcada como `const`

2. *deixa o propósito da função claro*
a função `printList` é somente para leitura/impressão e marcar como `const` comunica isso para quem lê o código (e pro compilador)

*obs* se você declarou uma lista struct com `const`, você só vai conseguir passar ela para a funções que aceitem `const List*`

> usar `const` em C é como uma forma primitiva (e manual) de encapsulamento, sob a ótica da orientação a objetos

em C não existe orientação a obejtos, então tudo que se quer "proteger" precisa ser feito com: 
* `const` - evita modificações indevidas
* separação por arquivos e modularização de código (`.h`, `.c`) - abstrair implementação
* cuidado ao expor campos diretamente