# endereço de memória
quando uma variável é criada em C, um endereço de memória é atribuído a essa variável
* o endereço de memória é a localização de onde de onde a variável está sendo armazenada no computador
* quando atribuimos um valor à variável, ela é colocada nesse endereço de memória
* para acessar esse endereço usamos o operador de referência `&`, e seu resultado representa onde a variável é armazenada

```c
int myAge = 19;
printf("%p", &myAge); // outputs 0x7ffe5367e044
```
* note que o endereço de memória está em sua forma hexadecimal. é pouco provável de obter o mesmo resultado do exemplo `0x7ffe5367e044`, já que isso depende de onde a variável está sendo armazenada no seu computador

`&myAge` é chamado de ponteiro
um ponteiro armazena o endereço de memória da variável e aponta para o valor que ela representa 

usamos o especificador de formato `%p` para imprimir valores na tela

ponteiros são extramemnte importantes em C, já que nos permite manipular dados dentro da memória do computador, o que reduz código e melhora performance
* é o que torna C diferente de outras linguagens de programação