// Esse programinha é só para mostrar as funções setfill e setw da biblioteca
// iomanip.

#include <iomanip>
#include <iostream>
int numero = 0;

int main(int argc, char *argv[]) {
  std::cout << "digite um número menor que 10.000: ";
  std::cin >> numero;
  std::cout << std::setfill('0') << std::setw(4) << numero << '\n';

  return 0;
}
