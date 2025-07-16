# structs e ponteiros
podemos usar ponteiros com structs para tornar nosso código mais eficiente, especialmente quando passando structs como argumentos de funções ou para alterar o valor de seus membros
* para usar um ponteiro de struct adicione `*`, assim como usado para outros tipos de dados
* para acessar seus membros, devemos usar o operado `->`, ao invés da sintaxe `.`

```c
struct Car {
    char brand[50];
    int year;
};

int main() {
    struct Car car = {"Toyota", 2020};

    // declarar um ponteiro de struct
    struct Car *ptr = &car;

    // acesso aos membros via ->
    printf("brand: %s\n", ptr->brand);
    printf("year: %d\n", ptr->year);
    
    return 0;
}
```

## passando ponteiros de structs como argumento de funções
essa é a forma como passamos ponteiros de structs para funções para modificar seus valores
```c
struct Car {
    char brand[50];
    int year;
};

// função que toma um ponteiro para a estrutura Car e atualiza seu ano
void updateYear(struct Car *c) {
    c->year = 2025; // altera o ano
}

int main() {
    struct Car myCar = {"Toyota", 2020};
    struct Car *c = &myCar;
    
    updateYear(c); // passamos um ponteiro para que a função modifique o ano
    
    printf("brand: %s\n", myCar.brand);
    printf("year: %d\n", myCar.year);

    return 0;
}
```

**por que usar ponteiros de struct?**
usar ponteiros de struct se torna útil quando:

* **queremos evitar o comportamento de copiar grandes quantidades de dados**
ao invés de copiar todo o struct, podemos apenas passar um ponteiro. isso torna o programa mais rápido e usa menos memória

* **queremos modificar o valor dos membros dentro de uma função**
se passarmos um ponteiro como argumento de uma função, seremos capazes de modificar seu valor original

* **queremos criar structs dinamicamente usando alocação de memória**
com ponteiros, podemos usar `malloc()` para criar structs em tempo de execução

---
é aqui que nasce algumas semelhanças com ponteiros de objetos em linguagens orientadas a objetos, como Java, e C
```java
class Pessoa {
    String nome;
}

Pessoa p1 = new Pessoa();
p1.nome = "Milena";

Pessoa p2 = p1;
p2.nome = "Nova Milena";

System.out.println(p1.nome);  // "Nova Milena"
```
* `p1` e `p2` apontam para o mesmo objeto na heap
* o comportamento é parecido com ponteiros de struct em C: se você modifica um, o outro sente o efeito
exemplo equivalente de comportamento:
```c
struct Pessoa {
    char nome[30];
};

struct Pessoa p1 = {"Milena"};
struct Pessoa *p2 = &p1;

strcpy(p2->nome, "Nova milena");

printf("%s\n", p1.nome); // "nova milena"
```
* isso produz o mesmo resultado, mas em C você decide manualmente se quer usar ponteiros ou não
* em Java você não tem opção, objetos são sempre armazenados na heap e acessados por referência