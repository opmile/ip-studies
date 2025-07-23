# o que é o buffer?
quando você digita algo no terminal e aperta Enter, tudo vai para uma área da memória chamada **stdin (entrada padrão)** - esse é o buffer de entrada
algumas funções, como `scanf()`, não consomem todo esse conteúdo

```c
int idade;
scanf("%d", &idade);
```
se você digita:
```
25[Enter]
```
o `scanf("%d", &idade)` pega o `25` mas o `\n` ainda fica no buffer

e é aí que surgem bugs, frequentemente quando usamos `fgets()` logo em seguida para ler strings do usuário
```c
scanf("%d", &idade);
fgets(nome, 50, stdin); // lê apenas o \n do buffer == nome vazio
```

criamos então uma solução eficiente, que limpa o buffer de entrada toda vez que é chamada
* ela é tão eficiente que limpa não só o `\n` mas qualquer outra entrada indesejada que já estava ali antes da próxima leitura

```c
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
```
* `getchar()` consome um caractere por vez do buffer
* ele continua consumindo e descartando os caracteres até encontrar `\n` (fim da linha) ou `EOF` (fim do arquivo)
    * usamos `EOF` como condição de parada porque ele indica que não há mais dados a serem lidos no buffer de entrada
    * isso evita loop infinito caso a quebra de linha nunca apareça. é uma segurança extra