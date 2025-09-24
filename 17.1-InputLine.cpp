#include <iostream>

int main () {
  char texto[100]; // array de char, diferente de uma string que requer o 
  std::cout << "Digite um texto: \n";
  std::cin.getline(texto,100);  
  std::cout << texto;
  return 0;
}
