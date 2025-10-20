#include "41-ClassesInterface.h"
#include <iostream>
using namespace std;

void mostraAtributos(
    minhaClasse obj1,
    minhaClasse
        obj2); // apenas um protótipo da função para que a compilação não de
               // erro, outra opção seria colocar a função completa aqui. Ver
               // sugestões do Gemini ao final do arquivo.

int main(int argc, char *argv[]) {

  // inicializando algumas instâncias (objetos)
  minhaClasse obj1, obj2;

  // mostrando os valore originais
  mostraAtributos(obj1, obj2);

  // inicializando as variáveis para capturar valores do usuário
  int atr11, atr21;
  string atr12, atr22;
  bool atr13, atr23;

  // inserindo valores pelo usuário
  std::cout << "---Objeto  1---" << '\n';
  std::cout << "Atributo1: ";
  std::cin >> atr11;
  std::cout << '\n';
  std::cout << "Atributo2: ";
  std::cin >> atr12;
  std::cout << '\n';
  std::cout << "---Objeto  2---" << '\n';
  std::cout << "Atributo1: ";
  std::cin >> atr21;
  std::cout << '\n';
  std::cout << "Atributo2: ";
  std::cin >> atr22;
  std::cout << '\n';

  // atualizando os valores dos objetos
  obj1.setterClasse(atr11, atr12);
  obj2.setterClasse(atr21, atr22);
  // Não há adequado tratamento de erro no método setterClasse, ou seja, se o
  // usuário insirir dados indevidos o programa não funcionará corretamente.

  // mostrando valores novamete após as alterações
  mostraAtributos(obj1, obj2);

  return 0;
}

void mostraAtributos(minhaClasse obj1, minhaClasse obj2) {
  // mostrando os valores dos atributos dos objetos criados com o construtor da
  // minhaClasse
  std::cout << "Atributo1: " << obj1.getAtr1() << ' '
            << "Atributo2: " << obj1.getAtr2() << ' '
            << "Atributo3: " << obj1.getAtr3() << '\n';
  std::cout << "Atributo1: " << obj2.getAtr1() << ' '
            << "Atributo2: " << obj2.getAtr2() << ' '
            << "Atributo3: " << obj2.getAtr3() << '\n';
}
/* tambem tive dificuldades com a questão da definição da função, não funcionava
 nem antes nem depois da main.
 * após colocar a função acima do mains fucionou, outra opção seria declarar um
 protótipo como abaixo sugerido pelo Gemini.
 *  O próximo passo é corrigir o arquivo 41-ClassesImplementacao.cpp.
  Como mencionei, a função mostraAtributos é chamada antes de ser
  definida. Para resolver isso, precisamos adicionar uma "declaração
  antecipada" (ou protótipo) da função no início do arquivo.

  Passo 2: Adicionar o protótipo da função em
  `41-ClassesImplementacao.cpp`

  Vou adicionar a linha
void mostraAtributos(minhaClasse obj1, minhaClasse obj2) {
  // mostrando os valores dos atributos dos objetos criados com o construtor da
  // minhaClasse
  std::cout << "Atributo1: " << obj1.getAtr1() << ' '
            << "Atributo2: " << obj1.getAtr2() << ' '
            << "Atributo3: " << obj1.getAtr3() << '\n';
  std::cout << "Atributo1: " << obj2.getAtr1() << ' '
            << "Atributo2: " << obj2.getAtr2() << ' '
            << "Atributo3: " << obj2.getAtr3() << '\n';
}
 antes da função main.
*/
