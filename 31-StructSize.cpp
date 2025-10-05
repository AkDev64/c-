/*
 * Size of Structure
 * The size of a structure is determined by the sum of the sizes of its
 * individual data members, with additional padding added by the compiler to
 * ensure proper memory alignment.
 */

#include <iostream>
using namespace std;
struct Mista {
  char c;
  int x, y;
};

int main() {

  // Imprimindo o tamanho da struct Mista
  cout << "O tamanho da estrutura é: " << sizeof(Mista);

  return 0;
}
