# segmentation fault
erros que acontecem quando seu programa tenta acessar uma área de memória que não tem permissão - ou seja, invade um território que não é dele

### o que o sistema operacinal faz?
quando o programa tenta acessar um endereço ilegal, o SO grita:
> *"EI! esse endereço não te pertence!"*
> em seguida, derruba o proframa com *segfault* (erro de segmentação)

## motivos mais comuns de segmentation fault

#### 1. acessar ponteiros não incializados
```c
int *p;
*p = 10; // crash: p aponta para lugar nenhum
```

### 2. acesso a memória já liberada (use-after-free)
```c
int *p = malloc(sizeof(int));
free(p);
*p = 42; // crash: você está acessando e tentando escrever em uma meória que já devolveu
```

### 3. double free
```c
free(p);
free(p); // comportamento indefinido: pode causar crash
```

### 4. acessar índice inválido de array
```c
int arr[3];
arr[10] = 5; // acesso fora dos limites do array (stack smashing ou segfault)
```

ex) exercício de interpolação de arrays
```c
int j;
for (int i = 0; i < len; i++) {
    arr[j++] = arr1[i];
    arr[j++] = arr2[i];
}
```
**a variável `j` não foi inicializada!** ou seja, o valor de `j` é lixo aleatório da memória (tipo 3928408 ou -14), e você está fazendo `result[j++] = ...` - acesso inválido ao array -> crash ou dados corrompidos

### 5. acessar `NULL`
```c
int *p = NULL;
*p = 1; // tentativa de acessar o endereço 0 (proibido pelo SO)
```

### 6. `realloc` que retorna `NULL` e você continua usando o ponteiro original
```c
int *p = malloc(10 * sizeof(int));
int *tmp = realloc(p, 100000000 * sizeof(int)); // fails!
p[0] = 1; // crash se tmp é NULL e você ainda usa p achando que foi realocado
```

### 7. esquecer de alocar memória antes de usar ponteiro
```c
int *arr;
arr[0] = 10; // mas você não alocou nada!
```

### 8. acessar além do que foi alocado com `malloc()``
```c
int *arr = malloc(5 * sizeof(int));
arr[5] = 99; // índice 5 é fora do intervalo (0 a 4)
```

### 9. strings mal finalizadas ou ponteiros de strings inválidos
```c
char *str = malloc(5);
strcpy(str, "abcdef"); // buffer overflow
```
* nessa situação, é mais seguro usar `strcnpy`

### 10. passar ponteiro inválido para função
```c
void print(int *p) {
    printf("%d\n", *p); // crash se p for NULL ou inválido
}
```

## checklist pro debug
1. ponteiros estão inicializados?
2. você alocou a memória antes de usar?
3. está dentro dos limites do array?
3. está acessando algo depois de free()?
4. usou `realloc()` e validou o retorno?
5. o `scanf`/`fgets` que você usou escreve onde deveria?
6. algum `for` ou `while` pode estar estourando índice?
7. você alterou algum ponteiro por referência e esqueceu de retornar ou atualizar?