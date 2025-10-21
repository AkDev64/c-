// Esse programa simples mostra a diferença entre o uso de ponteiros e
// referências em C++.
#include <iostream>

int main(int argc, char *argv[]) {
  int a = 9999;
  int *ptr = &a;
  int &ref = a;

  std::cout << "valor de a consultado direto pela variável: " << a << '\n';
  std::cout << "valor que é apontado pelo ponteiro que aponta para a: " << *ptr
            << '\n';
  std::cout << "valor que é referenciado para a: " << ref << '\n';

  a = 1111; // observe que *ptr e ref não são alterados, mas como apontam para o
            // endereço de memória de a também são impactados
  std::cout << "valor de a consultado direto pela variável: " << a << '\n';
  std::cout << "valor que é apontado pelo ponteiro que aponta para a: " << *ptr
            << '\n';
  std::cout << "valor que é referenciado para a: " << ref << '\n';

  return 0;
}
