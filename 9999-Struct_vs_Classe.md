✦ Em C++, uma struct (abreviação de structure, ou estrutura) é um tipo de dado composto que permite agrupar múltiplas variáveis, de
  tipos diferentes, sob um único nome.

  Pense nela como uma "ficha" ou um "registro" que contém vários campos de informação relacionados.

  Exemplo Básico:

  Imagine que você quer representar uma pessoa. Uma pessoa tem nome, idade e altura. Em vez de criar variáveis separadas:

   1 std::string nomePessoa;
   2 int idadePessoa;
   3 float alturaPessoa;

  Você pode agrupá-las em uma struct:

    1 #include <iostream>
    2 #include <string>
    3 
    4 // 1. Definição da struct
    5 struct Pessoa {
    6     std::string nome;
    7     int idade;
    8     float altura;
    9 };
   10 
   11 int main() {
   12     // 2. Declaração de uma variável do tipo Pessoa
   13     Pessoa p1;
   14 
   15     // 3. Acesso e atribuição de valores aos membros (campos)
   16     p1.nome = "Adriano";
   17     p1.idade = 30;
   18     p1.altura = 1.75f;
   19 
   20     // 4. Leitura dos valores
   21     std::cout << "Nome: " << p1.nome << std::endl;
   22     std::cout << "Idade: " << p1.idade << " anos" << std::endl;
   23     std::cout << "Altura: " << p1.altura << "m" << std::endl;
   24 
   25     return 0;
   26 }

  ---

  A Grande Questão em C++: struct vs. class

  Em C++, struct e class são quase idênticas. Elas podem ter construtores, destrutores, funções-membro e herança. A única diferença 
  técnica entre elas é o modificador de acesso padrão:

   1. `struct`: Os membros são `public` por padrão.
   2. `class`: Os membros são `private` por padrão.

  Exemplo da diferença:

    1 struct MinhaStruct {
    2     int x; // Este membro é public por padrão
    3 };
    4 
    5 class MinhaClasse {
    6     int y; // Este membro é private por padrão
    7 };
    8 
    9 int main() {
   10     MinhaStruct s;
   11     s.x = 10; // OK! 'x' é público e pode ser acessado diretamente.
   12 
   13     MinhaClasse c;
   14     // c.y = 20; // ERRO DE COMPILAÇÃO! 'y' é privado e não pode ser acessado de fora da classe.
   15 }

  Quando usar struct? (Convenção)

  Apesar de serem tecnicamente muito parecidas, a comunidade C++ segue uma convenção forte:

  Use `struct` para agrupar dados que não possuem lógica complexa ou "invariantes" (regras que os dados devem sempre seguir). Pense
  em structs como "sacos de dados" passivos. O acesso público aos membros é geralmente aceitável.

   * Exemplos: Um ponto 2D (struct Ponto { int x; int y; }), uma cor RGB, um registro de configuração.

  Use `class` quando você precisa de encapsulamento. Ou seja, quando você quer proteger os dados (tornando-os private) e forçar que
  o acesso e a modificação sejam feitos através de funções-membro (public). Isso permite que a classe garanta que seus dados
  internos permaneçam em um estado válido.

   * Exemplos: Uma classe ContaBancaria (onde o saldo não pode ficar negativo sem regras), uma conexão com banco de dados, um
     gerenciador de arquivos.

