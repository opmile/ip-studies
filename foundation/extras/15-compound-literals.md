# compound literals

imagine que temos um vetor de `Funcionario`  e queremos criar uma instância de funcionário para cada posição do vetor
```c
funcionarios[0] = {"Milena Oliveira", 19, 1200.00, &departamentos[0]}; // ERRO!
```

a forma corre seria:
```c
funcionarios[0] = (Funcionario){"Milena Oliveira", 19, 1200.00, &departamentos[0]}; 
```
essa construção se chama *designated compound literal com cast de struct*

`(Funcionario){...}` cria um valor temporário do tipo `Funcionario` preenchido com os valores fornecidos, e o atribui diretamente à posição `funcionarios[0]`
* como se fosse um `malloc + preenchimento` tudo de uma vez, só que direto na stack (e sem alocação)

**por que não posso fazer isso com arrays diretamente?**
em C, você não pode reatribuir arrays. arrays não são variáveis de ponteiro como em outras linguagens - eles são blocos de memória fixo e não podem ser reatribuídos como um todo, apenas elemento por elemento
* *analogia*: um array em C é como uma casa de tijolos fixos. você pode pintar cada parede (modificar os elementos), mas não pode arrancar a casa inteira e botar outra no lugar
* usar compound literals funciona porque você está justamente modificando o conteúdo (no exemplo, de `funcionarios[0]`), não o ponteiro do array

```c
typedef struct {
    char nome[50];
    char sigla[10];
    int codigo;
} Departamento;

typedef struct {
    char nome[50];
    int idade;
    float salario;
    Departamento *dep;
} Funcionario;
```
agora queremos criar ou atribuir um `Funcionario` de forma eficiente

```c
Departamento d1 = {"Tecnologia da Informação", "TI", 101};

Funcionario f = {
    "Milena Oliveira", 
    19, 
    1200.00, 
    &d1
};

// ou com compound literal
Funcionario f = (Funcionario){
    .nome = "Milena Oliveira",
    .idade = 19,
    .salario = 1200.00,
    .dep = &d1
};

// ou atribuir depois com compound literal
Funcionario f;
f = (Funcionario){
    .nome = "Milena Oliveira",
    .idade = 19,
    .salario = 1200.00,
    .dep = &d1
};
// isso funciona porque o (Funcionario){...} cria um struct temporário que é copiado para f

// C não permite atribuição com lista de inicialização fora da declaração, só dentro da criação da variável ou via compund literal
f = {"Milena Oliveira", 19, 1200.00, &d1}; // ERRO
```
*obs*: quando o struct contém outro struct (não ponteiro)
```c
typedef struct {
    char nome[50];
    int idade;
    float salario;
    Departamento dep;  // struct aninhada, sem ponteiro
} Funcionario;

// ai podemos fazer
Funcionario f = {
    "Milena Oliveira", 19, 1200.00,
    {"Tecnologia da Informação", "TI", 101}
};
```

agora com array de struct e atribuição por índice:
```c
Funcionario funcionarios[10];

funcionarios[0] = (Funcionario){ // funciona
    "Camila", 25, 1300.00, &d1
};

// ou com designadores
funcionarios[0] = (Funcionario){
    .nome = "Camila",
    .idade = 25,
    .salario = 1300.00,
    .dep = &d1
};

// ou ainda
strcpy(funcionarios[0].nome, "Camila");
funcionarios[0].idade = 25;
funcionarios[0].salario = 1300.00;
funcionarios[0].dep = &d1;
```

**uso de designadores vs sem designadores**
```c
// sem designador
funcionarios[0] = (Funcionario){ 
    "Camila", 25, 1300.00, &d1
};

// com designadores
funcionarios[0] = (Funcionario){
    .nome = "Camila",
    .idade = 25,
    .salario = 1300.00,
    .dep = &d1
};
```
* *sem designadores*: esse estilo sem designadores exige ordem estrita e correta. qualquer mudança na ordem dos campos do struct ou esquecimento de algum campo, quebra o programa
* *com designadores*: mais seguro e legível, e com isso a ordem dos campos não importa, e você ainda pode pular campos que vão assumir valor zero/default

