# Linha de Atribuição

Quando você escreve dentro do construtor:

   1 int atr1 = 0;

  Você está declarando uma nova variável chamada atr1 que é local ao construtor. Esta variável:
   1. "Esconde" (shadows) o atributo atr1 da classe.
   2. Recebe o valor 0.
   3. É destruída assim que a execução do construtor termina.

  O atributo atr1 da sua classe nunca foi tocado e permaneceu com um valor indefinido (lixo de memória), o que poderia causar bugs
  difíceis de rastrear no futuro.

  A Correção

  Ao remover o tipo (int), você muda o significado da linha:

   1 atr1 = 0;

  Agora, você não está mais declarando uma nova variável. Você está se referindo ao atributo atr1 que já existe na classe e
  atribuindo um valor a ele. Isso funciona e corrige o problema.

  ---

  Melhor Prática em C++: Lista de Inicialização

  Embora sua correção funcione, a forma mais idiomática e eficiente de inicializar atributos em C++ é usar uma lista de 
  inicialização.

  A sintaxe é a seguinte:

   1 public:
   2   minhaClasse() : atr1(0), atr2(""), atr3(false) {
   3     // O corpo do construtor pode ficar vazio se você só precisa inicializar.
   4   }

  Por que isso é melhor?

   1. Eficiência: Para tipos complexos (classes, structs), a lista de inicialização constrói o objeto diretamente com o valor correto.
      A atribuição no corpo do construtor primeiro cria o objeto (com um construtor padrão) e depois atribui um novo valor, o que pode
      ser menos performático.
   2. Necessidade: Atributos que são const ou referências (&) não podem ser inicializados por atribuição no corpo do construtor. Eles
      obrigatoriamente precisam ser inicializados na lista de inicialização.

  Resumindo: sua intuição sobre o erro estava certa, e a correção funciona, mas para escrever um código C++ mais robusto e
  eficiente, prefira usar a lista de inicialização.

> me fale mais sobre lista de inicializaçõa, nesse contexto em c++

✦ Com certeza. Vamos aprofundar no conceito de listas de inicialização em C++, um dos recursos fundamentais da linguagem para escrever
  construtores de forma correta e eficiente.

  O que é e qual a sintaxe?

  A lista de inicialização é uma parte da definição de um construtor. Ela começa com dois pontos (:) depois da lista de parâmetros e
  antes do corpo {} do construtor. Nela, você especifica os valores iniciais dos atributos da classe.

  Sintaxe:

    1 class Exemplo {
    2 private:
    3   int numero;
    4   std::string texto;
    5   const float PI; // Atributo constante
    6 
    7 public:
    8   // Construtor usando lista de inicialização
    9   Exemplo(int n, std::string t) : numero(n), texto(t), PI(3.14159f) {
   10     // O corpo do construtor agora pode ser usado para outras lógicas,
   11     // ou pode simplesmente ficar vazio.
   12   }
   13 };

  A Diferença Crucial: Inicialização vs. Atribuição

  Este é o ponto mais importante.

   * Inicialização (na lista): É o processo de criar a variável já com seu valor. A memória é alocada para o atributo e o valor inicial
     é construído diretamente nesse espaço.
   * Atribuição (no corpo `{}`): É um processo de duas etapas:
       1. Primeiro, antes do corpo do construtor ser executado, cada atributo é inicializado com seu construtor padrão (ex: std::string
          é criado como uma string vazia, int fica com valor indefinido).
       2. Depois, dentro do corpo, o operador de atribuição (=) é chamado para copiar um novo valor para o atributo que já existe.

  Pense nisso como construir uma casa:
   * Inicialização: É como construir uma parede já com a cor de tijolo que você quer.
   * Atribuição: É como construir uma parede com tijolos padrão e, só depois, pintá-la. O primeiro método é mais direto.

  Quando a Lista de Inicialização é OBRIGATÓRIA?

  Existem situações em que a atribuição no corpo do construtor simplesmente não funciona e o C++ exige o uso da lista de
  inicialização.

  1. Atributos `const` (constantes):
  Uma variável const deve receber seu valor no momento de sua criação e não pode ser modificada depois. A lista de inicialização é o
  único lugar para fazer isso em um atributo de classe.

   1 class Circulo {
   2   const double PI;
   3 public:
   4   Circulo() : PI(3.14159) {} // CORRETO
   5 
   6   Circulo(double valor) {
   7     // PI = valor; // ERRO DE COMPILAÇÃO! Não se pode atribuir a uma const.
   8   }
   9 };

  2. Atributos que são Referências (`&`):
  Referências devem ser "ligadas" a outra variável no momento de sua criação. Elas não podem ser "re-ligadas" depois.

   1 class Janela {
   2   OutraClasse& objetoExterno;
   3 public:
   4   Janela(OutraClasse& obj) : objetoExterno(obj) {} // CORRETO
   5 
   6   Janela(OutraClasse& obj) {
   7     // objetoExterno = obj; // ERRO DE COMPILAÇÃO!
   8   }
   9 };

  3. Atributos de classes que não têm construtor padrão:
  Se um atributo é um objeto de outra classe e essa classe não tem um construtor que não recebe argumentos (MinhaClasse()), você é
  obrigado a chamar um dos construtores existentes na lista de inicialização.

    1 class Motor {
    2 public:
    3   Motor(int potencia) { /*...*/ } // Não tem construtor padrão Motor()
    4 };
    5 
    6 class Carro {
    7   Motor motor;
    8 public:
    9   // CORRETO: precisamos chamar o construtor de Motor
   10   Carro() : motor(150) {}
   11 
   12   Carro() {
   13     // ERRO DE COMPILAÇÃO! O compilador não sabe como criar 'motor'
   14     // porque a classe Motor não tem um construtor Motor().
   15   }
   16 };

  4. Chamar construtores de uma classe base (Herança):
  A lista de inicialização é a forma de passar parâmetros para o construtor da classe da qual você está herdando.

    1 class Veiculo {
    2 public:
    3   Veiculo(int numRodas) { /*...*/ }
    4 };
    5 
    6 class Moto : public Veiculo {
    7 public:
    8   // CORRETO: chamamos o construtor de Veiculo com o valor 2
    9   Moto() : Veiculo(2) {}
   10 };

  Uma Regra Importante: Ordem de Inicialização

  Os atributos são inicializados na ordem em que são declarados na classe, e não na ordem em que aparecem na lista de inicialização.
  Escrever a lista fora de ordem pode causar bugs sutis.

    1 class Perigoso {
    2   int a;
    3   int b;
    4 public:
    5   // PERIGOSO, mas compila!
    6   // 'a' será inicializado PRIMEIRO, pois foi declarado antes.
    7   // No momento em que 'a' é inicializado com o valor de 'b', 'b' ainda não foi inicializado!
    8   // 'a' receberá um valor lixo.
    9   Perigoso(int x) : b(x), a(b) {}
   10 };

  Boa prática: Sempre escreva sua lista de inicialização na mesma ordem em que os atributos foram declarados na classe para evitar
  confusão.

   1 class Seguro {
   2   int a;
   3   int b;
   4 public:
   5   // CORRETO E SEGURO
   6   Seguro(int x) : a(x), b(a) {} // 'a' é inicializado com x, 'b' é inicializado com o valor de 'a'.
   7 };

  Resumo

  Use a lista de inicialização sempre que for definir o valor inicial de um atributo em um construtor. É a forma mais segura, mais
  eficiente e, em muitos casos, a única forma permitida pelo C++. A atribuição no corpo do construtor deve ser reservada para
  lógicas mais complexas que não podem ser feitas com uma simples inicialização.

