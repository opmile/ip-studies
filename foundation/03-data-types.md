# tipos de dados
o tipo de data especifica o tamanho e o tipo de informação que uma variável (ou função) armazena
```md
| Data Type | Size | Description | Ex |
| -------- | ------- | -------- | ------- |
|   int  | 2 or 4 bytes | whole numbers  | 1 |
|  float | 4 bytes | fractional nunmbers. up to 6-7 decimal digits | 1.99 |
| double | 8 bytes | fractional numbers. up to 15 decimal digits | 1.99 |
|  char  | 1 byte  | single caracter/letter/nymber/ASCII values  | 'a' |
```

### char
se você tentar atribuir mais de um caractere, apenas imprimirá o último caractere. para armazenar uma sequeência de caracteres (strings) fazemos isso assumindo toda string é um array
```c
char myText[] = "hello"
pringf("%s", myText);
```

### numéricos
* use `int` para armazenar inteiros
* use `float` ou `double` para armazenar decimais

`float` vs. `double`
a precisão de um ponto flutuante indica quantas casas decimais o valor pode armazenar depois do `.`
- `float` tem precisão de 6-7 casas decimais
- `double` tem precisão de 15 casas decimais
para a maioria dos cálculos, é mais seguro usar `double`, mas observe que ocupa o dobro de memória que um `float` (8 bytes vs. 4 bytes)

*notação científica*
podemos escrever números muito grandes ou muito pequenos usando uma notação específica. isso é feio usando a letra `e` (ou `E`), que significa "vezes 10 elevado a potência de..."
- `35e3` significa 35 × 10³ = 35000
```c
float f1 = 35e3;   // 35 * 10^3 = 35000
double d1 = 12E4;  // 12 * 10^4 = 120000

printf("%f\n", f1);
printf("%lf", d1);
```

#### definindo precisão decimal
imprimir um ponto flutuante traz como saída muitas casas decimais
```c
float myFloatNum = 3.5;
double myDoubleNum = 19.99;

printf("%f\n", myFloatNum); // Outputs 3.500000
printf("%lf", myDoubleNum); // Outputs 19.990000
```

remover os zeros extras (definir precisão decimal), implica usar `.` seguido de quantas casas decimais 
```c
float myFloatNum = 3.5;

printf("%f\n", myFloatNum);   // Default will show 6 digits after the decimal point
printf("%.1f\n", myFloatNum); // Only show 1 digit
printf("%.2f\n", myFloatNum); // Only show 2 digits
printf("%.4f", myFloatNum);   // Only show 4 digits 
```

### tamanho na memória
o tamanho na mamória se refere a quanto de espaço um tupo de dado pode ocupar na memória do computaodor
| Data Type |     Size     |
| --------- | ------------ |
|    int    | 2 or 4 bytes |
|   float   |    4 bytes   |
|   double  |    8 bytes   |
|   char    |    1 bytes   |

* para realmente retornar o tamanho (em bytes) de um tipo de dado ou variável usamos a função `sizeof` 
```c
int myInt;
float myFloat;
double myDouble;
char myChar;

printf("%zu\n", sizeof(myInt));
printf("%zu\n", sizeof(myFloat));
printf("%zu\n", sizeof(myDouble));
printf("%zu\n", sizeof(myChar));
```
* note aqui que usamos especificador de formato `%zu` para imprimir o resultado ao invés de `%d`. isso porque o compilador espera que a função retorne um valor do tipo `size_t`, que é um *tipo de inteiro não assinado*

saber o tamanho dos tipos de dado nos ajuda a entender o quanto de memória um programa usa. isso é muito importante quando passamos a escrever longos progamas que trabalham com limitação de memória, porque pode afetar tanto performance como eficiência
* um `char` ocupa 1 byte. um aray de 1000 `char` ocupará 1000 bytes (1KB) de memória

usar o tipo certo de dado para o propósito corre salva memória e melhora a performance do programa

```c
int items = 50;
float cost_per_item = 1.99;
float total_cost = items * cost_per_item;
char currency = '$';

printf("número de itens: %d", items);
printf("custo por item: %c%.2f", currency, cost_per_item);
printf("preço final: %c%.2f", total_cost);
```

### conversão de tipos de dados
converter um tipo de dado em outro é conhecido como conversão de tipo

tentar dividir `5` por `2` resulta em `2.5`, mas como estamos trabalhando com inteiros (e não pontos flutuantes) o exemplo a seguir resulta apenas em `2`
```c
int x = 5;
int y = 2;
int div = x / y;
```

existem dois tipos de conversão de tipos
* conversão implícita - automática
* conversão explícita - manual

1. **conversão implícita** 
feita automaticamente pelo compilador quando atribuimos um valor de um tipo para outro
```c
float myFloat = 9; // conversão automática: int para float

printf("%f", myFloat); // 9.0;
```
o compilador automaticamente converteu o `int` `9` no valor `float` de `9.000000`
* esse tipo de conversão de torna arriscada quando o programa cresce e se perde o controle de valores específicos in determinadas situações. observe:
```c
int myInt = 9.99;

printf("%d", myInt); // 9
```
`.99` foi totalmente apagado, já que a conversão implícita sempre arredonda o valor para baixo

corrigindo o exemplo anterior, dividir `5` por `2` resulta em `2.5`. se declararmos a variável `div` como `int`, ela armazenará um valor inteiro, mas e se declararmos como `float` dessa vez?
```c
float div = 5 / 2;

printf("%f", div); // 2.000000
```
por que o resultado é `2.000000` e não `2.5`? isso acontece porque 5 e 2 ainda são inteiros na divisão. nesse caso, precisamos manualmente converter valores inteiros em números de ponto fluturante

2. **conversão explícita**
a conversão explícita é feita manualmete colocando o tipo desejado entre parênteses `()` na frente do valor
```c
// conversão manual: int para float
float div = (float) 5 / 2;

printf("%f", div); // 2.500000

// também podemos adotar essa estratégia em variáveis
int num1 = 5;
int num2 = 2;
float div = (float) num1 / num2;

printf("%.1f", div) // 2.5
```

*funcionamento prático*
```c
int maxScore = 500;

int userScore = 423;

// porcentagem de pontuação do usuário
float percentage = (float) userScore / maxScore * 100.0;

printf("pontuação: %.1f", percentage);
```
nesse exemplos estamos convertendo apenas o valor de `userScore` para `float`, antes da divisão acontecer. e isso já pe suficiente para forçar a divisão a ser feita com ponto flutuante, o que evita a divisão inteira, que truncaria o resultado

```c
(float) userScore       // converte 432 -> 432.0 (float)
423.0 / 500             // float dividivo por int -> float 0.846
0.846 * 100.0           // float * float -> 84.6
```
o compilador automaticamente promove o `maxScore` (que é `int`) para `float` na hora da divisão, porque c sempre promove os tipos para os mais "preciso" em operações mistas

### booleans
frequetemente, em programação, precisaremos um tipo de dado que pode representar dois tipos de valor
* YES / NO
* ON / OFF
* TRUE / FALSE

para essa representação, c possui `bool` como tipo de dado, conhecido como booleans. eles podem representar dois tipos de valores `true` ou `false`

**boolean variables**
`bool` em c não é um tipo de dado built-in como `int` ou `char`. na verdade, foi introduzido no c99 e, para usá-lo, devemos importar uma lib no cabeçalho do arquivo
```c
#include <stdbool.h>
```

uma variável booleana é declarada com `bool` e só pode assumir dois tipos de valores: `true` ou `false`
```c
bool isProgrammingFun = true;
bool isFishTasty = false;
```

os valores armazenados por variáveis booleanas são retornadas como inteiros
* `1` (ou qualquer número diferente de 0) representa `true`
* `0` representa `false`
por esse motivo, devemos usar o especificador de formato `%d` para imprimir um valor booleano
```c
bool isProgrammingFun = true;
bool isFishTasty = false;

printf("%d", isProgrammingFun); // 1 - true
printf("%d", isFishTasty); // 0 - false
```

é mais comum retornar valores booleanos quando comparando valores e variáveis
```c
//1
printf("%d", 10 > 9); // 1

//2
int x = 10;
int y = 9;
printf("%d", x > y); // 1 

//3
printf("%d", 10 == 10); // 1
printf("%d", 10 == 15); // 0
```