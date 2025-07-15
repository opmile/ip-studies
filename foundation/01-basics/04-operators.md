# operadores
são símbolos que pedem ao compilador para realizar ações específicas: como somar, comparar, deslocar bits, atribuir, etc.

## operadores aritméticos
| operador | nome                      | exemplo  | resultado |
| -------- | ------------------------- | -------- | --------- |
| `+`      | adição                    | `5 + 3`  | `8`       |
| `-`      | subtração                 | `10 - 4` | `6`       |
| `*`      | multiplicação             | `2 * 4`  | `8`       |
| `/`      | divisão                   | `10 / 2` | `5`       |
| `%`      | módulo (resto da divisão) | `10 % 3` | `1`       |

## operadores de atribuição
| operador | significado          | exemplo  | equivalente |
| -------- | -------------------- | -------- | ----------- |
| `=`      | atribuição simples   | `x = 10` | —           |
| `+=`     | soma e atribui       | `x += 5` | `x = x + 5` |
| `-=`     | subtrai e atribui    | `x -= 2` | `x = x - 2` |
| `*=`     | multiplica e atribui | `x *= 3` | `x = x * 3` |
| `/=`     | divide e atribui     | `x /= 2` | `x = x / 2` |
| `%=`     | módulo e atribui     | `x %= 3` | `x = x % 3` |

## operadores de comparação
| operador | significado      | exemplo  | resultado (bool)          |
| -------- | ---------------- | -------- | ------------------------- |
| `==`     | igual a          | `a == b` | `1` (true) ou `0` (false) |
| `!=`     | diferente de     | `a != b` | `1` ou `0`                |
| `>`      | maior que        | `a > b`  | —                         |
| `<`      | menor que        | `a < b`  | —                         |
| `>=`     | maior ou igual a | `a >= b` | —                         |
| `<=`     | menor ou igual a | `a <= b` | —                         |

## operadores lógicos
| Operador | Nome       | Exemplo          | Significado                                  |
| -------- | ---------- | ---------------- | -------------------------------------------- |
| `&&`     | AND lógico | `cond1 && cond2` | verdadeiro se **ambos** forem verdadeiros    |
| `||`     | OR         | `cond1 || cond2` | OR lógico                                    |
| `!`      | NOT        | `!cond`          | inverte o valor (true → false, e vice-versa) |
* para o operador `!` é importante ressaltar que o retorno sera 0 se o resultado da condição for 1

## operadores unário
| operador | significado                 | exemplo                            |
| -------- | --------------------------- | ---------------------------------- |
| `++`     | incremento (aumenta 1)      | `x++` ou `++x`                     |
| `--`     | decremento (diminui 1)      | `x--` ou `--x`                     |
| `-`      | negativo                    | `-x`                               |
| `!`      | lógico “não”                | `!x`                               |
| `sizeof` | tamanho do tipo ou variável | `sizeof(int)` = 4 (bytes em geral) |
`x++` é diferente de `++x`
- `x++` -- primeiro usa o valor atual de x, depois incrementa
- `++x` -- primeiro incrementa ao valor atual de x, depois usa

## operadores bitwise
atuam no nível dos bits individuais dos números, muito usados para:
* otimizações hardcore de desempenho/memória
* manipulação de flags e máscaras de bits
* drivers, sistemas embarcados, redes e criptografia
* controle de hardware (arquino, sistemas de baixo nível, etc.)
