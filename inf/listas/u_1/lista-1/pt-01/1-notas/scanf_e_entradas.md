# Inicialização das Variáveis para o `scanf`

O analisador estático `cppcheck` reclama que as variáveis no código a seguir não foram inicializadas, mas o `scanf` lê a entrada do usuário e registra os dados a partir do ponteiro.

```c
#include <stdio.h>

void generateTaxPowerReport(float minSalary, float totalKW) {
    float kW = minSalary / 5;
    float totalDue = kW * totalKW;
    float totalWithDiscount = totalDue * 0.85;

    printf("kW = R$ %.2f\n", kW);
    printf("TOTAL DEVIDO = R$ %.2f\n", totalDue);
    printf("TOTAL COM DESCONTO = R$ %.2f\n", totalWithDiscount);
}

int main() {
    float minSalary, totalKW;
    
    printf("SALÁRIO MÍNIMO = R$ ");
    scanf("%f", &minSalary);

    printf("TOTAL DE ENERGIA CONSUMIDA (kW) = ");
    scanf("%f", &totalKW);
    
    generateTaxPowerReport(minSalary, totalKW);

    return 0;
}
```
* *fragmento retirado da primeira versão do código do exercício 06*

## O que de fato está acontecendo?

O `cppcheck` consegue, muitas vezes, ser paranoico: ele não interpreta que o `scanf` vai, de fato, atribuir um valor válido às variáveis. 

Na verdade, ele tem toda razão. Essa é uma tentativa de te indicar *"e se o `scanf` falhar?"*. Isso pode acontecer quando:

* O usuário não digita nada válido (lixo).

* Retorna EOF (*End of File*, quando a área de memória de entrada padrão - stdin - chega ao fim, a exemplo do `scanf`).

    > *EOF isn't a character - it's a special value that the input functions return to indicate a condition, that the "end of file" on that input stream has been reached. As Martin v. Löwis says, once that "end of file" condition occurs, it means that no more input will be available on that stream.*

    ref: https://stackoverflow.com/questions/1622092/probiem-with-eof-in-c

    * Muito usado para limpar o buffer de entrada com `getchar`, para quando queremos usar `fgets` logo após `scanf`.


Por isso recebemos um *warning*: existe um caminho de execução onde as variáveis `minSalary` e `totalKW` permanecem não inicializadas.

### Observação sobre a limitação do analisar estático `cppcheck`

Observe o código a seguir:
```c
#include <stdio.h>

float calculateAvgSalary(float minSalary, float salary) {
    return salary / minSalary;
}

int main() {
    
    float minSalary, salary;
    
    printf("SALÁRIO MÍNIMO: ");
    scanf("%f", &minSalary);

    printf("SALÁRIO DO FUNCIONÁRIO: ");
    scanf("%f", &salary);

    printf("SALÁRIO DO FUNCIONÁRIO: R$ %.2f\n", salary);
    printf("SALÁRIO MÍNIMO: R$ %.2f\n", minSalary);
    printf("EQUIVALENTE A %.2f SALÁRIOS MÍNIMOS\n", 
        calculateAvgSalary(minSalary, salary));

}
```
* *fragmento retirado da primeira versão do exercício 03*

Aqui, de forma contraditória, o `cppcheck` não acusa nenhum *warning*, apesar de que as variáveis também sofrem o mesmo risco de não serem inicializadas no momento de leitura com `scanf`.

Isso acontece porque as variáveis são usadas apensa no mesmo escopo (`main`), e logo após o `scanf`. Nesse caso, o `cppcheck` parece assumir que o fluxo é direto o bastante e "não reclama".

Em outras palavras, não é que esse segundo código esteja "mais correto", é só que o analisador estático aplica heurísticas diferentes a depender do contexto.


## Resolução

1. **Inicializar as variáveis no momento de declaração**

```c
float minSalary = 0.00f, totalKW = 0.00f;
```

* Em C, variáveis locais não tem valor definido até que se atribua algo, e por isso podem conter lixo de memória quando não inicializadas.

* Inicializar com `0.00f` garante que, se o `scanf` falhar, a variável pelo menos tem um valor previsível e seguro.

* O 'f' indica que é `float` literal, não `double`. Nesse caso porque no exercício o contexto nos pede que seja `float`, mas se usassemos `0.0`, o compilador faria a conversão de `double` para `float` automaticamente.

A ideia de inicializar nossas variáveis locais é a mesma para ponteiro locais. Quando declarado, ele aponta para um endereço aleatório na memória, lixo. Sempre devemos inicializar um ponteiro com `NULL` para evitar `segfault`

2. **Checar o retorno do `scanf`**

```c
if (scanf("%f", &minSalary) != 1) {
    printf("Erro: entrada inválida para salário mínimo.\n");
    return 1;
}

if (scanf("%f", &totalKW) != 1) {
    printf("Erro: entrada inválida para energia consumida.\n");
    return 1;
}
```

O `scanf` tenta ler dados do *input stream* padrão (stdin) e, a partir do ponteiro, guarda a informação no endereço da variável.

O retorno da função se baseia em quantos itens ele conseguiu ler com sucesso.

* Se o usuário digitou um número válido = retorna `1` (= `true`, conseguiu preencher em `%f`)

* Se o usuário digitou algo inválido 
    
    * letra = retorna `0` (= `false`)
    
    * EOF = retorna `-1`


Sempre que indicamos `return 1;`, significa que o programa deve evitar imediatamente com código de saída `1`

* Convencionalmente, `0` significa execução bem sucedida, e é por isso que ao final da função `main` usamos `return 0`. O código de erro é `1`, mas qualquer outro valor poderia indicar a mesma coisa

    * Esse raciocínio é muito usado nos momentos de alocação ou realocação de memória, onde o ponteiro usado para essa operação pode apontar para `NULL`, significando erro de manipulação dinâmica de memória.
