# estruturas condicionais em c
estruturas condicionais em c controlam o **fluxo do programa**, ou seja, **o que será executado dependendo de uma condição**. são fundamentais pra tomada de decisão em tempo de execução.

### 1. `if` — **condição simples**
usado quando você **quer verificar uma única condição**.
```c
int idade = 18;
if (idade >= 18) {
    printf("Você é maior de idade\n");
}
```
> executa o bloco **apenas se** a condição for verdadeira (`true`).

### 2. `if...else` — **condição com alternativa**
permite tratar os dois caminhos possíveis.
```c
if (nota >= 60) {
    printf("aprovado\n");
} else {
    printf("reprovado\n");
}
```

### 3. `if...else if...else` — **condições em cadeia**
útil para **verificar múltiplas possibilidades em sequência**.
```c
if (nota >= 90) {
    printf("excelente\n");
} else if (nota >= 75) {
    printf("bom\n");
} else if (nota >= 60) {
    printf("suficiente\n");
} else {
    printf("reprovado\n");
}
```

### operadores Relacionais e Lógicos

#### **relacionais**
| operador | significado      |
| -------- | ---------------- |
| `==`     | igual a          |
| `!=`     | diferente de     |
| `>`      | maior que        |
| `<`      | menor que        |
| `>=`     | maior ou igual a |
| `<=`     | menor ou igual a |

#### **lógicos**
| Operador | Significado      | Exemplo                       |
| -------- | ---------------- | ----------------------------- |
| `&&`     | E lógico (AND)   | `(idade >= 18 && idade < 60)` |
| `||`     | OU lógico        | `(idade >= 18 || idade < 60)` |
| `!`      | NÃO lógico (NOT) | `!(nota >= 60)`               |

---

### 4. `switch` — **escolha por valor fixo**
o `switch` é útil **quando você quer testar várias opções possíveis de um mesmo valor**, como em menus ou decisões por código numérico.
```c
int opcao = 2;

switch (opcao) {
    case 1:
        printf("você escolheu a opção 1\n");
        break;
    case 2:
        printf("você escolheu a opção 2\n");
        break;
    case 3:
        printf("você escolheu a opção 3\n");
        break;
    default:
        printf("opção inválida\n");
}
```

* o valor de `opcao` é **comparado com cada `case`**.
* se houver correspondência, **executa aquele bloco de código**.
* o `break` serve para **parar a execução do `switch`**, impedindo que os próximos `case` sejam executados (evita o efeito "queda", chamado *fall-through*).
* o `default` é **executado quando nenhum `case` for igual ao valor**. funciona como um "else" do `switch`.

```c
char letra = 'A';

switch (letra) {
    case 'A':
        printf("letra A\n");
        break;
    case 'B':
        printf("letra B\n");
        break;
    default:
        printf("outra letra\n");
}
```

> o `switch` **não funciona com intervalos** como `x > 10` ou `x < 5`. apenas **valores exatos** (como `1`, `'A'`, etc.).

**quando usar:**
| situação                                                  | estrutura ideal |
| --------------------------------------------------------- | --------------- |
| verificar intervalos de valores                           | `if...else`     |
| verificar igualdade com muitos valores fixos (1, 2, 3...) | `switch`        |

### short-hand `if...else` (operador ternário)
existe uma forma mais simplificada de usar uma estrutura condicional, feita a partir do uso do operador ternário, chamado dessa forma porque consiste no uso de três operandos.
* usado para sobrescrever múltiplas linhas de código em uma única
* comumente usado para declarar simples if else

```c
variable = (condition) ? expressionIfTrue : expressionIfFalse;
```

*simplificações*
```c
int time = 20;
if (time < 18) {
    printf("good day.");
} else {
    printf("good evening.");
}
//

int time = 20;

```