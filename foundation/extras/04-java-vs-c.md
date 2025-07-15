# java vs. c
é mais difívil fazer um programa em C escalar do que um programa em Java orientado a objetos

## 1. **abstração e organização do código**

**em C**
* não tem classes, herança, polimorfismo, nem encapsulamento
* a estrutura do código depende exclusivamente de funç~eos soltas e, no máximo, `structs` sem comportamento
* à medida que o projeto cresce, fica mais difícil separar responsabilidades e modularizar o código

**em Java**
* a programação orientada a objetos é a base da linguagem
* pode-se criar modelos do mundo real com classes, agrupar comportamentos com dados, eaplicar princípior como SOLID
* escalar o código vira uma questão de organização arquitetural - e a própria linguagem te ajuda com isso
> em Java, o próprio paradigma te empurra para boas práticas que ajudam a escalar um projeto

## 2. **gerenciamento de memória**

**em C**
* gerenciamento de memória manual com `malloc`, `free`, ponteiros...
* erros como vazamento de meméria, double free e segfaults aumentam conforme o programa cresce
* a complexidade da memória cresce junto com a escala

**em Java**
* o *garbage collector* cuida da memória automaticamente
* você foca no comportamento e na lógica, não na alocação e liberação de recursos
* menos bugs relacionados à memória conforme o sistema cresce

## 3. **ferramentas e ecossistema**

**em C**
* compiladores como `gcc` são poderosos, mas não existem tantas bibliotecas padrão para coisas como redes, banco de dados, UI, etc.
* testes unitários, documentação automática e build systems precisam de mais configuração e conhecimento exta

**em Java**
* ecossistema rico: Maven/Gradle, JUnit, Spring, frameworkd RESTful, ORM como Hibernate
* as ferramentas de engenharia de software foram feitas para escalar com o projeto

## 4. **segurança e tipagem**

**em C**
* tipagem fraca em algumas situações, conversões implícitas perigosas
* buffer overflow é um risco real
* qualquer erro de ponteiro pode danificar os dados e comprometer todo o programa

**em Java**
* tipagem forte e segura
* a maioria dos eeros de tipo e memórria são capturados em tempo de compilação por exceções controladas

## 5. **reusabilidade e manutenção**

**em C**
* pouca reutilização nativa. sem classes, você depende de replicar funções com structs como parâmetros
* atualizar e estender funcionalidade exige muito cuidado e leitura de código legado

**em Java**
* herdabilidade, interfaces e composição favorecem reuso e extensão
* refatorar e dar manutenção em grandes bases Java é muito mais "humano"

### quando C se destaca?
* sistemas embarcados, drivers, kernel, firmware: onde controle absoluto da máquina é essencial
* código que não precisa escalar muito, mas sim ser extremamente eficiente

#### C do ponto de vista acadêmico
C é tipo o **latim da computação moderna** e está por trás de 
* sistemas operacionais
* compiladores (inclusive o do próprio Java e Python)
* linguagens modernas (C++, Rust, Go - todas bebem de C)
* linguagens de hardware e sistemas embarcados
> aprender C te dá clareza sobre o que realmente acontece por trás da cortina. linguagens modernas (Java, Python, JS...) abstraem muita coida. C te mostra tudo nu e cru

C te força a entender como a máquina funciona já que se deve aprender sobre
* ponteiros -> endereçamento direto de memória
* alocação dinâmica 
* como strings funcionam de verdade
* o que é uma stack e heap de forma prática
* representação binária, tipos primitivos, alinhamento de memória

isso é a base para entender outros conceito avançados depois, como garbage collector, threads e sincronização, algoritmos de alocação e estruturas de dados internas