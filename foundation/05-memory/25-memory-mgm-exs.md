# exemplo de caso de uso de gerenciamento de memória
para demonstrar um exemplo prático de memória dinâmica, criamos um programa que cria uma lista de qualquer tamanho
* arrays em C possuem tamanho fixo e não podem ser mudados, mas com memória dinâmica, podemos criar uma list do tamanho que quisermos

```c
typedef struct {
    int data*; // array com memória dinâmica
    int numItems; // indica o número de itens atuais
    int size; // indica a capacidade total de itens
} List;

void addItemToList(List *myList, int item);

int main() {
    myList.size = 10;
    myList.numItems = 0;
    myList.data = malloc(myList->size * sizeof(int));

    int amount;

    if (myList->data == NULL) {
        printf("alocação de memória falhou");
        return 1;
    }

    amount = 44;

    for (int i = 0; i < amount; i++) {
        addItemToList(&myList, i + 1);
    }

    for (int j = 0; j < myList->numItems; j++) {
        printf("data[%d]: %d\n", j, *(myList.data + j));
    }

    free(myList.data);
    myList.data = NULL;

    return 0;
}

void addItemToList(List *myList, int item) {

    // verificar se a lista está cheia, se estiver, realocar memória para mais 10 elementos
    if (myList->numItems == myList->size) {
        myList->size += 10;
        myList->data = realloc(myList->data, myList->size * sizeof(int));
    }

    // adicionar item ao final da lista
    myList.data[myList->numItems] = item;
    myList->numItems++;
}

```