# enums
um `enum` é um tipo especial que representa um grupo de constantes (valores não modificáveis)
* abreviação para enumerações

```c
enum Level {
    LOW,
    MEDIUM,
    HIGH
};
```
* é considerada uma boa prática nomear constantes em uppercase

crie uma variável `enum` em `main()` acompanhado do nome do `enum` (Level) e do nome da variável
```c
enum Level myVar;
```

depois de criar uma variável `enum`, agora podemos atribuí-la a um valor que deve ser um dos itens listados no enum (`LOW`, `MEDIUM`, `HIGH`)
```c
enum Level myVar = MEDIUM;
```

**enums em C possuem um valor númerico inteiro associado a cada item**
por padrão, o primeiro item (`LOW`) tem o valor `0`, o segundo (`MEDIUM`) tem o valor `1` e assim por diante para os próximos itens
```c
int main() {
    enum Level myVar = MEDIUM;

    printf("%d", myVar); // 1

    return 0;
}
```

**mude valores**
podemos alterar o padrão numérico embutido para cada item do enum
```c
enum Level {
    LOW = 25;
    MEDIUM = 50;
    HIGH = 75
};

int main() {
    enum Level l = MEDIUM;
    printf("%d\n", l); // 50
}
```

* note que se você atribuir um valor para um item específico, seus próximos items atualizarão seus números de acordo
```c
enum Level {
    LOW  = 5,
    MEDIUM, // 6
    HIGH // 7
}
```

esse tipo de comportamento se torna muito útil em estruruas condicionais `switch`
```c
enum Level {
    LOW = 1,
    MEDIUM,
    HIGH
};

int main() {
    enum Level myVar = MEDIUM;

    switch (myVar) {
        case 1:
            printf("low level");
            break;
        case 2:
            printf("medium level");
            break;
        case 3:
            printf("high level");
            break;
    }
    return 0;
}
```

*aplicações:*

ex.01)
```c
enum DiaDaSemana {
    DOMINGO,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};

int main() {
    enum DiaDaSemana hoje = QUARTA;

    if (hoje == QUARTA) {
        printf("hoje é quarta-feira!");
    }

    return 0;
}
```

ex.02)
```c
#include <stdio.h>

enum StatusPedido {
    PENDENTE,
    EM_ANDAMENTO,
    ENTREGUE,
    CANCELADO
};

void imprimirStatus(enum StatusPedido status) {
    switch (status) {
        case PENDENTE:      printf("pedido pendente\n"); break;
        case EM_ANDAMENTO:  printf("pedido em andamento\n"); break;
        case ENTREGUE:      printf("pedido entregue\n"); break;
        case CACELADO:      printf("pedido cancelado\n"); break;
        default:            printf("status desconhecido"); 
    }
}

int main() {
    enum StatusPedido status = EM_ANDAMENTO;
    imprimirStatus(status);
    return 0;
}
```

como o `switch` opera nesse caso?
enums são na prática apenas `int` com nomes
```c
enum StatusPedido {
    PENDENTE,
    EM_ANDAMENTO,
    ENTREGUE,
    CANCELADO
};
```
o compilador transforma isso mais ou menos assim:
```c
#define PENDENTE 0
#define EM_ANDAMENTO 1 
#define ENTREGUE 2
#define CANCELADO 3
```
ou seja, você criou constantes inteiras com nomes legíveis, então
```c
enum StatusPedido stauts = EM_ANDAMENTO;
// é igual a 
int status = 1;
```
por isso o `switch` funciona:
```c
switch (status) {
    case PENDENTE:      // case 0:
    case EM_ANDAMENTO:  // case 1:
}
```

ex.03) `enum` + `struct`
```c
#include <stdio.h>

enum TipoConta {
    CORRENTE,
    POUPANCA,
    SALARIO
};

struct ContaBancaria {
    int numero;
    enum TipoConta tipo;
    float saldo;
};

void exibirConta(struct ContaBancaria *conta) {
    printf("conta: %d - saldo: %.2f - tipo: ", conta->numero, conta->saldo);

    switch (conta->tipo) {
        case CORRENTE: printf("corrente\n"); break;
        case POUPANCA: printf("poupança\n"); break;
        case SALARIO: printf("salário\n"); break;
    }
}

int main() {
    struct ContaBancaria c1 = {123, POUPANCA, 1000.00f};
    exibirConta(&c1)
    return 0;
}
```
**por que usar ponteiro de struct é melhor aqui?**
1. *eficiência*
* ao passar `struct ContaBancaria conta`, você está fazendo uma cópia de todos os dados do struct
* se a estrutura for grande (com strings, arrays, outros campos complexos), essa cópia pode ser custosa
* usar ponteiro (`struct ContaBancaria *`) evita a cópia: só passa o endereço

2. *possibilidade de modificar os dados*
* com ponteiro, você pode alterar os dados originais dentro da função, se quiser (bas não usar const)
* isso te dá mais flexibilidade

3. coerência com práticas reais de C
* em C real, structs são quase sempre passados por ponteiro (ou ponteiro constante), principalmente em sistemas reais, drivers, bancos de dados, etc