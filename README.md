# Implementação de Padrões de Projeto
Trabalho realizado para a disciplina de Engenharia de Software. Trata-se da implementação de 3 **Padrões de Projeto**, sendo um comportamental, um criacional e um estrutural. Os padrões escolhidos foram: **Strategy**, **Builder** e **Composite**. Cada um possui uma pasta contendo um exemplo de código em **C++** e um **Diagrama UML** que descreve o propósito geral do padrão escolhido.

# Padrões implementados
## Padrão de Projeto Comportamental - Strategy
Às vezes um algoritmo ou comportamento pode ter várias variações possíveis que podem mudar em tempo de execução. O padrão de projeto **Strategy** encapsula cada comportamento em sua própria classe, fazendo possível adicionar ou modificar variações sem mexer no código existente e tornando possível trocar a estratégia em tempo de execução sem alterar o contexto. De acordo com o [Refactoring Guru](https://refactoring.guru/pt-br/design-patterns/strategy):

>O padrão Strategy sugere que você pegue uma classe que faz algo específico em diversas maneiras diferentes e extraia todos esses algoritmos para classes separadas chamadas estratégias.
### Explicação do código - strategy.ccp
O código implementado trata-se de um controlador de ações de inimigos em um jogo de RPG. Cada inimigo pode agir de quatro formas diferentes (Agressivo, Defensivo, Fugir e Patrulhar). ComportamentoStrategy define a ação genérica, enquanto cada estratégia implementa um comportamento diferente. A classe inimigo possui um ponteiro para uma estratégia, que pode ser modificada dinamicamente por setStrategy(). A função agir() apenas executa a ação da estratégia atual, sem precisar saber qual é. Com isso, comportamentos podem ser trocados durante o jogo sem alterar a classe Inimigo.

## Padrão de Projeto Criacional - Builder
Em muitos sistemas, o processo de construir um objeto complexo (com muitas etapas ou partes opcionais) torna-se complicado e difícil de manter. Além disso, diferentes versões/variações do mesmo objeto podem precisar ser construídas de formas diferentes, mas compartilhando uma mesma sequência de passos. O **Builder** separa o processo de construção do produto final, permitindo criar objetos complexos de forma clara e reutilizável. Nesse padrão, é possível criar vários **"builders"** que criaram diferentes versões do mesmo produto. Este padrão tem como benefíco tornar o código de construção fica isolado e organizado.

### Explicação do código - builder.cpp
Esse código trata-se de um montador de sanduíches. Um sanduíche possui pão, carne, molho e salada, como definido na classe Sanduiche. SannduicheBuilder é o builder genérico que mostra como deve ser contruído um lanche. Neste código, temos dois builders concretos: HaburguerBuilder e CachorroQuenteBuilder, que têm a função de contruir os lanches de acordo com seus respectivos nomes. Por fim temos o diretor, que sabe como construir um lanche comum, sem salada ou sem molho. Um builder é passado a ele, que cria o lanche da forma pedida, independente do tipo (Hamburguer ou Cachorro Quente).

## Padrão de Projeto Estrutural - Composite
Às vezes você precisa representar uma estrutura hierárquica, como um sistemas de arquivos. O problema é que você terá objetos que são simples (folhas) e outros que contêm outros objetos (compostos) e muitas vezes você precisar tratar eles de forma igual. Sem **Composite**, seria necessário tratar cada tipo separadamente, criando muitos `if/else` e lógica duplicada. Para resolver isso, o **Composite** propõe:
* Criar uma interface comum para folhas e contêineres;
* Fazer com que objetos compostos armazenem outros objetos que implementam a mesma interface;
* Permitir que o cliente trate uma “parte” e um “todo” da mesma forma.

Com isso, o composite permite que objetos simples e complexos sejam tratados de forma igual.

### Explicação do código - composite.cpp
O código implementado trata-se de um sistema de arquivos simples, com pastas e arquivos. A interface ItemSistema definine as funções de mostrar e ver o tamanho, que será utilizada tanto para as pastas, quanto para os arquivos. No objeto do tipo pasta é possível adicionar mais itens, inclusive mais pastas, formando assim uma estrutura hierárquica recursiva, ideal para o padrão **Composite**. Com esse código, é possível criar pastas e arquivos, além de poder mostrar seus conteúdos e tamanho de forma clara ao cliente.