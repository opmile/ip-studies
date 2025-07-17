# data e hora
em C, você pode usar a lib `<time.h>` no cabeçalho para trabalhar com data e hora. essa biblioteca te permite extair o horário atual, formatá-lo e performar cálculos de períodos

ela fornece:
* tipos como `time_t` e `struct tm`
* funções para capturar, formatar e manipular tempo

em C, "tempo" é manipulado de duas formas principais
| tipo de tempo                     | significado                                                           |
| --------------------------------- | --------------------------------------------------------------------- |
| **tempo do sistema (tempo real)** | a hora e data atuais do mundo real. ex: 15/07/2025 21:33              |
| **tempo de CPU/processador**      | quanto tempo o programa ocupou o processador (medição de desempenho). |


### o que é `time_t`
é um tipo de dado especial que armazena o temp em segundo desde a "Época Unix":
**1º de janeiro de 1970, 00:00:00 UTC**
```c
time_t agora;
time(&agora); // captura o tempo atual
```
* `time_t` geralmente é um inteiro de 64 bits
* armazena o tempo de forma absoluta, útil para cálculos (ex: diferença entre duas datas)
* internamente, é geralmente um `long int`

> você não entende data legível com `time_t` diretamente. ele é só um contador bruto de segundos, ex.: `1721087862`

### o que é `struct tm`
é uma estrutura que divide o tempo em partes legíveis com campos como ano, mês, dia, etc.
```c
struct tm {
    int tm_sec; // segundos (0-60)
    int tm_min; // minutos (0-59)
    int tm_hour; // horas (0-23)
    int tm_mday; // dia do mês (1-31)
    int tm_mon; // mês (0-11) - jan = 0!
    int tm_year; // anos desde 1900 (ex. 2025 -> 125)
    int tm_wday; // dia da semana (0 = domindo)
    int tm_yday; // dia do ano (0 a 365)
    int tm_isdst; // horário de verão (positivo, 0 ou negativo)
}
```
você precisa converter `time_t` para `struct tm` usando funções como '`localTime()`' para interpretar esses campos

## obtendo a data e hora atuais
1. obtenha o tempo atual (`time_t`)
2. converta para `struct tm`
3. formate ou use os campos


ex.01) data e hora simples com `asctime()`
`asctime()` converte uma `struct tm` em uma string com formatação data/hora padrão
```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora;
    struct tm *infoTempo;

    time(&agora); // pega o tempo bruto
    infoTempo = localtime(&agora) // converte para local legível

    printf("agora: %s\n", asctime(infoTempo)); // imprime formatado padrão

    return 0;
}
```
* `time(&agora)` - coloca no `agora` o número de segundo desde 1970
* `localtime()` - retorna ponteiro para `struct tm` com hora local
* `asctime(infoTempo)` - imprime formatado padrão

ex.02) data e hora com `ctime()`
`ctime()` é converter um valor `time_t` em uma string legível, como "Mon Jun 24 10:15:00 2025"

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t currentTime;
    time(&currentTime); // extrai o horário atual

    printf("horário atual é: %s", ctime(&currentTime));
    
    return 0;
}
```

ex.03) formatação personalizada com `strftime()`
`strftime()` formata uma `struct tm` em uma data e hora customizadas
```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm *tempo = localtime(&t);
    char buffer[100];

    strftime(buffer, sizeof(buffer), "hoje é %d/%m/%Y, %H:%M:%S", tempo)
    printf("%s\n", buffer);

    return 0;
}
```
* tabela de códigos de formatação
| código | significado        |
| ------ | ------------------ |
| `%d`   | dia do mês (01–31) |
| `%m`   | mês (01–12)        |
| `%Y`   | ano (ex: 2025)     |
| `%H`   | hora (00–23)       |
| `%M`   | minuto (00–59)     |
| `%S`   | segundo (00–60)    |

* **`time_t t = time(NULL)`**
a função time() tem essa assinatura
```c
time_t time(time_t *arg)
```
* se você passar um ponteiro válido, ele guarda o tempo lá dentro
* se você passar `NULL`, ela só retorna o valor
então `time_t t = time(NULL)` significa: "me dê o tempo atual em segundos desde 1970 e guarde esse valor na variável `t`

* **`struct tm *tempo = localtime(&t)`**
a função `localtime()` tem a seguinte assinatura
```c
struct tm *localtime(const time_t *timer);
```
* recebe um ponteiro para o `time_t` (tempo em segundos desde 1970)
* converte esse número para uma `struct tm` com data e hora locais
* retorna um ponteiro para uma struct estática interna (isto é, não precisa liberar a memória, mas ela é sobrescrita a cada chamada)

C separa tempo bruto (`time_t`) de tempo formatado (`struct tm`), para manter a linguagem simples e modular

## quebrando o tempo em partes
```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("ano: %d\n", t->tm+year + 1900);
    printf("mês: %d\n", t->tm_mon + 1);
    printf("dia: %d\n", t->tm_mday);
    printf("hora: %d\n", t->tm_hour);
    printf("minuto: %d\n", t->tm_min);
    printf("segundo: %d\n", t->tm_sec);

    return 0;
}
```

## medir tempo de execução
use o tipo `clock_t` para medir tempo de CPU
```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fim;
    double tempo_total;

    inicio = clock();

    for (volatile int i = 0; i < 100000000; i++); // Simula uma tarefa

    fim = clock();

    tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.3f segundos\n", tempo_total);

    return 0;
}
```
* o `clock()` mede ciclos de clock da CPU, e `CLOCKS_PER_SECOND` converte isso apra segundos 

## diferença entre duas datas
você pode fazer operações com `time_t` porque ele é só um número
```c
time_t inicio = time(NULL);

// espera alguns segundos, ou roda um código demorado

time_t fim = time(NULL);

printf("Passaram-se %ld segundos\n", fim - inicio);
```

## feramentas adicionais
| função       | significado                                                         |
| ------------ | ------------------------------------------------------------------- |
| `gmtime()`   | converte `time_t` para UTC (em vez da hora local)                   |
| `mktime()`   | faz o contrário de `localtime()` — converte `struct tm` em `time_t` |
| `difftime()` | retorna a diferença entre dois `time_t` como `double`               |

## cuidados importante
1. `asctime()` inclui `\n` no final da string
2. `localtime()` retorna ponteiro para `struct` estática, então cuidado com sobrescrita
3. para tempo preciso (milissegundos), `<time.h>` não dá suporte total → precisa de outras libs como `<sys/time.h>` no Linux
