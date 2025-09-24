#include <iostream>

int main () {
 
  std::string meuTexto; // inicializando uma string no contexto do namespace std
  std::cout << "digite um texto: \n";
  std::getline( std::cin, meuTexto);
  std::cout << meuTexto;

  return 0;
}
