> crie uma função que receba dois vetores e um tamanho, e preencha um terceiro vetor com a soma dos dois primeiros (posição por posição)

em C não dá pra retornar arrays diretamente, porque arrays não são tipos de valor - são decaídos para ponteiros. como simular isso?

1. **função que recebe o vetor de destino como parâmetro**
```c
void somarVetores(int *v1, int *v2, int *resultado, int len) {
    for (int i = 0; i < len; i++) {
        *(result + i) = *(v1 + i) + *(v2 + i); // ou result[i] = v1[i] + v2[i];
    }
}
```

**e se eu quiser retornar um vetor da função?**
você não pode retornar um array "cru", mas pode retornar um ponteiro para uma array alocado dinamicamente com `malloc()`

2. **retornando ponteiro com `malloc()` (cuidado com memória!)**
```c
int* somarVetores(int *v1, int *v2, int len) {
    int *resultado = malloc(tamanho * sizeof(int));

    for (int i = 0; i < len; i++) {
        *(resultado + i) = *(v1 + i) + *(v2 + i);
    }

    return resultado;
}