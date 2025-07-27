# recursão em C - efeitos colaterais vs retorno de valor
existem diferentes padões recursivos em C e a forma como lidamos com o retorno da função recursiva muda completamente o comportamento do programa

*se lembre!*
recursão é uma ténica onde uma função chama a si mesma para resolver subproblemas menores. ela precisa de duas coisas
1. **caso base**: condição que interrompe o passo recursivo
2. **chamada recursiva**: onde o problema é reduzido e a função se chama de novo

## o que acontece na execução?
quando uma função chama a si mesma:
    * a execução atual é pausada e colocada numa pilha de execução (call stack)
    * cada chamada recursiva fica empilhada até chegar no caso base
    * a partir dali, a pilha começa a desempilhar e as funções anteriores retomam

## **padrões de uso de recursão**

1. **recursão com efeito colateral (sem retorno)**
ex) imprimir um array ao contrário
```c
void printReverse(int *arr, int len) {
    if (len == 0) return;
    
    printReverse(arr, len - 1);
    printf("%d \n", arr[0]);
}
```
aqui, observe que como a função foi declarada como `void`, ela não precisa retornar nada ao chamador
* o efeito desejado (imprimir valores) acontece na volta da pilha 
* cada chamada espera terminar a próxima, e só depois executa o `printf`
* útil quando a função não precisa realizar uma ação, não devolver algo ao chamador

2. **recursão com retorno de valor (acúmulo de resultado)**
ex) verificar se uma string é palíndromo
```c
bool isPalindrome(char *str, int start, int end) {

    if (start < end) {
        if (str[start] == str[end]) {
            return isPalidrome(str, start + 1, end - 1);
        } else {
            return false;
        }
    }
    return true;
}
```
erro comum
```c
if (str[start] == str[end]) {
    isPalindrome(str, start + 1, end - 1); // retorno ignorado
    return true; // não retorna o valor da chamada recursiva
}
```
aqui o objetivo é descobrir um resultado booleano (true ou false) por meio de uma verificação recursiva
* cada chamada precisa saber o resultado da próxima para decidir o que retornar
    * cada função da pilha recursiva depende do true da próxima função para ela mesma poder retornar true
    * a função atual só pode retornar true se a próxima chamada da recursão também retornou true. porque você não tem a visão completa da string - só enxerga suas pontas. o miolo fica escondido para a próxima chamada
* se você não retornar o valor da chamada recursiva em uma função que exige retorno acumulado, você está interrompendo a lógica
* é um padrão comum usado em
    * soma acumulada (`sum(n)`)
    * verificações (`isSorted`, `isPalindrome`)
    * fatorial, potência, busca, etc.

## regra geral:
**quando sua função precisa retornar algo que depende de chamadas internas, você deve usar `return` na frente da próxima chamada recursiva**

