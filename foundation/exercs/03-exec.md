1. **soma de diagonal principal de matriz dinâmica**
* aloca uma matriz nxn com `int**`
* preenche com valores
* soma a diagonal principal
extra: faça o mesmo com a diagonal segundária

2. **clonar vetor dinâmico**
* dado um vetor alocado com `malloc`, escreva uma função que retorna uma cópia exata desse vetor em uma nova região da memória
* resolva tudo com aritmética de ponteiros

3. **função que modifica struct por ponteiro**
```c
typedef struct {
  char nome[100];
  int idade;
} Pessoa;
```
* crue uma função que recebe um `Pessoa*` e altera a idade 
* em `main` verifique se a modificação persistiu

4. **soma de cmapos em vetor de structs**
* crie um vetor de `Pessoa`, como acima
* escreva uma função que recebe um ponteiro para esse vetor e o número de elementos, e retorna a soma das idades