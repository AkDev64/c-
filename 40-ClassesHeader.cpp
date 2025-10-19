// Esse programa é muito similar ao 40-ClassesConstructor.cpp, mas agora vamos
// criar separar a definição da classe em um arquivo cabeçalho .h do corpo da
// função main
#include "40-ClassesHeader.h" // fundamental para que a definição da classe seja entendida pelo programa principal.
#include <iostream>
// Definição de uma classe

int main(int argc, char *argv[]) {

  // String auxiliares
  std::string strNome1, strNome2; // string para receber o nome

  // Capturando Valores do Usuário
  std::cout << "Digite o primeiro nome: ";
  getline(std::cin, strNome1);
  std::cout << '\n';
  std::cout << "Digite o segundo nome: ";
  getline(std::cin, strNome2);

  // Criando os objetos da classe com a função membro constructor
  ClasseExemplo obj1(strNome1); // Cria o primeiro objeto da classe
  ClasseExemplo obj2(strNome2); // Cria o segundo objeto da classe

  // Capturando os valores dos atributos dos objetos via método getter
  std::cout << "O primeiro nome é: " << obj1.obterNome() << '\n';
  std::cout << '\n';
  std::cout << "O segundo nome é: " << obj2.obterNome() << '\n';

  return 0;
}
