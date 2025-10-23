# Estou com dificuldade de entender a 
  diferena de construtor padrão e construtor com parâmetro

✦ Ótima pergunta! Essa é uma dúvida muito comum e fundamental em programação orientada a objetos. Vou usar uma analogia para
  facilitar.

  Imagine que você está construindo uma casa.

  Construtor Padrão (A Casa "Modelo Padrão")

  Pense no construtor padrão como uma planta para uma casa modelo, pré-definida.

   * O que é? É um construtor que não recebe nenhum parâmetro (nenhuma informação de fora).
   * Para que serve? Ele cria um objeto com um estado inicial fixo, "padrão de fábrica". Você não precisa dar nenhuma instrução; ele
     simplesmente constrói o objeto da maneira mais básica possível.

  Exemplo:
  Vamos criar uma classe Pessoa. O construtor padrão pode criar uma pessoa "genérica".

    1 class Pessoa {
    2 public:
    3     std::string nome;
    4     int idade;
    5 
    6     // Este é o construtor padrão
    7     // Não recebe parâmetros
    8     Pessoa() {
    9         nome = "Não definido";
   10         idade = 0;
   11         std::cout << "Pessoa padrão criada!" << std::endl;
   12     }
   13 };
   14 
   15 // Como usar:
   16 Pessoa p1; // Chama o construtor padrão. p1 terá nome "Não definido" e idade 0.

  Ponto Importante: Se você não escrever nenhum construtor na sua classe, o C++ cria um construtor padrão vazio e invisível para
  você. Mas, no momento em que você define qualquer outro construtor (como um com parâmetros), o C++ não cria mais o padrão
  automaticamente. Se precisar dele, você terá que escrevê-lo.

  ---

  Construtor com Parâmetros (A Casa "Sob Medida")

  Este é como encomendar uma casa sob medida, onde você já informa ao construtor suas especificações.

   * O que é? É um construtor que recebe um ou mais parâmetros para inicializar o objeto.
   * Para que serve? Ele permite criar um objeto já com um estado específico e válido desde o início, sem precisar chamar outras
     funções (como set...) depois.

  Exemplo:
  Agora, vamos dar à classe Pessoa um jeito de ser criada já com nome e idade.

    1 class Pessoa {
    2 public:
    3     std::string nome;
    4     int idade;
    5 
    6     // Construtor padrão (opcional, mas bom ter)
    7     Pessoa() {
    8         nome = "Não definido";
    9         idade = 0;
   10     }
   11 
   12     // Este é um construtor com parâmetros
   13     Pessoa(std::string n, int i) {
   14         nome = n;
   15         idade = i;
   16         std::cout << "Pessoa sob medida criada!" << std::endl;
   17     }
   18 };
   19 
   20 // Como usar:
   21 Pessoa p2("Ana", 30); // Chama o construtor com parâmetros.
   22                       // p2 já nasce com nome "Ana" e idade 30.

  ---

  Resumo Rápido


  ┌─────────┬────────────────────────────────────────────────────────────────────┬──────────────────────────────────────────────────
  ─┐
  │ Cara... │ Construtor Padrão                                                  │ Construtor com Parâmetros
   │
  ├─────────┼────────────────────────────────────────────────────────────────────┼──────────────────────────────────────────────────
  ─┤
  │ **Parâ... │ Nenhum                                                             │ Um ou mais
     │
  │ Criação │ Objeto obj;                                                        │ Objeto obj("valor1", 20);
   │
  │ **Esta... │ Sempre o mesmo, pré-definido                                       │ Customizado, definido na criação
     │
  │ **Uso ... │ Criar arrays de objetos (Pessoa lista[10];) ou quando um objeto... │ Criar objetos que já precisam ser válidos e
  co... │
  └─────────┴────────────────────────────────────────────────────────────────────┴──────────────────────────────────────────────────
  ─┘

  Conectando com o seu Código

  No seu arquivo 45-Heranca.cpp, você tinha dois momentos importantes:

   1. Carro lista[max];
       * Esta linha só funciona porque você tinha um construtor padrão `Carro()`. Para criar um array de objetos, o C++ precisa saber
         como construir cada um dos 3 carros "padrão" antes de você fazer qualquer outra coisa com eles.

   2. lista[i] = Carro("a definir", 0);
       * Esta linha falhou porque você não tinha um construtor que aceitasse uma string e um inteiro, ou seja, um Carro(std::string, 
         int).

  Espero que a analogia e os exemplos tenham deixado a diferença bem clara

