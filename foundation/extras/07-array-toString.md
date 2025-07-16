# simulando um `toString()` para um arr em C
em C não existe uma função `toString()` como em Java ou Python, mas você pode formatar sua própria saída com `printf()` (apesar de muito manual) para criar o mesmo visual, tipo:
```c
{1, 2, 3, 4, 5, 6, 7, 8, 10}
```

suponha o array:
```c
int numeros[] = {1, 2, 4, 5, 6, 8, 9, 10};
int len = sizeof(numeros) / sizeof(numeros[0]);
```
você pode simular um `toString()` assim:
```c
printf("{");

for (int i = 0; i < len; i++) {
    printf("%d", *(numeros + i));
    if (i < len - 1) {
        printf(", ");
    }
}

printf("{\n");
```
* temos a abertura e o fechamento da lista
* o laço para imprimir o número atual
* um separador que imprime a vírgula e o espaço apenas se não for o último elemento

*saída*
```
{1, 2, 4, 5, 6, 8, 9, 10}
```

*quer economizar linhas?* use o operador ternário
```c
printf("{");
for (int i = 0; i < len; i++) {
    printf("%d%s", *(numeros + i), (i < len ? ", " : ""));
}
printf("}\n");
```

se estiver imprimindo os dados de uma struct com array dinâmico (tipo `list->data`) podemos adaptar

```c
typedef struct {
    int *data;
    int numItems;
    int size;
} List;

void printList(List *list);

int main() {
    return 0;
}

void printList(List *list) {
    printf("{");
    for (int i = 0; i < list->numItems; i++) {
        printf("%d", *(list->data + i));
        if (i < list->numItems) printf(", ");
    }
    printf("}\n");
}

```
