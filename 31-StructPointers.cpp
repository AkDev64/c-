/*
 * Pointer to Structure In C++, a pointer to a structure is also known as a
 * structure pointer. It is a pointer that holds the address of the memory
 * location where the structure is stored. The normal way to access structure
 * members is to first dereference the pointer and then use dot operator, but
 * C++ provides -> arrow operator to directly access structure members using
 * pointer to it.
 */

#include <iostream>
using namespace std;

struct Simples {
  int numero;
  void mostra() { cout << numero << endl; }
};

int main() {
  Simples s = {224};

  // Criando um ponteiro
  Simples *sptr = &s;

  // Acessando usando o operador seta
  sptr->mostra();

  return 0;
}
