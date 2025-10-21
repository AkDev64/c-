#include <iostream>

int main() {
  int param = 0;
  int valor = 0;
  std::cin >> param;
  (param >= 0) ? valor = 1 : valor = -1;
  std::cout << "Valor: " << valor << std::endl;
  return 0;
}
