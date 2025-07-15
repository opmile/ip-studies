# `union`
uma `union` é um tipo especial de estrutura de dados, semelhante ao `struct`, onde seus membros armazenam diferentes tipos de dados, mas:
* `struct`: cada membro tem seu próprio espaço de memória
* `union`: membros compartilham a mesma memória - isso significa que você só pode usar um dos valores por vez

```c
union Dado {
    int i;
    float f;
    char str[20];
}
```
isso cria um único bloco de memória que pode ser interpretado de várias formas - mas só uma de cada vez!

na maior parte do tempo, prefirimos usar `struct`, já que pode armazenar e acessar diferentes valores ao mesmo tempo. entretanto, unions se tornam úteis quando queremos armazenam um de outros tipos por vez, e com isso salvar espaço na memória


```c
union Dado d;
d.i = 10;
printf("%d\n", d.i);     // 10

d.f = 3.14;
printf("%f\n", d.f);     // 3.14

printf("%d\n", d.i);     // lixo, valor de i foi sobrescrito por f!
```
*por que?* porque `i`, `f` e `str` usam o mesmo espaço de memória. ou seja: só um campo pode armazenar um valor válido por vez
* mudar um valor afetará os demais de modo que apenas o último membro atribuído carrega um valor válido

## tamanho de um `union`
o tamanho de um `union` sempre carrega o tamanho do elemento "mais pesado" (o que ocupa mais espaço na memória), todos os campos se sobrepõem
```c
union myUnion {
  int myNum;
  char myLetter;
  char myString[36];
};

int main() {
  union myUnion u1;
  printf("size of union: %zu bytes\n", sizeof(u1));
  return 0;
}
```
* como o maior membro ocupa 36 bytes, todo o union também ocupa 36 bytes

ao contrário do `struct` que considera o espaço ocupado por cada membro, o tamanho seria de 44 bytes:
`myNum` (4 bytes) + `myLetter` (4 bytes) + `myString` (36 bytes) = 44 bytes no total

## casos de uso

**quando usar `struct`?**
* precisa armazenar múltiplos dados ao mesmo tempo (ex. nome, idade, salário de uma pesssoa)
* os campos têm funções diferente se coexistem logcamente
* performance não é uma grande preocupação

**quando usar `union`?**
* só precisa de um valor de cada vez, mas esse valor pode ter formator diferentes
* econimia de memória, especialmente em sistemas embarcados ou drives
* situações onde você está modelando algo como uma variável genérica

ex) token de uma linguagem
```c
enum Tipo { INTEIRO, REAL, STRING };

struct Token {
    enum Tipo tipo;
    union {
        int i;
        float f;
        char str[20];
    } valor;
};
```
* aqui você economiza memória porque só um dos três valores será usado a cada token

*cuidados*
* você precisa saber qual campo está ativo. usar `enum` como discriminador ajuda.
* ler o campo errado causa comportamento indefinido (pode imprimir lixo ou dar crash).
* nada de `strcpy(u.str, "texto")` se o campo anterior era um `float` — você precisa gerenciar isso!