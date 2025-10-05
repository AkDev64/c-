/*
 * typedef: In C++, typedef is used to create an alias for an existing variable.
 * Similarly, with structures, typedef creates an alias for the original name of
 * the structure.
 */

#include <iostream>
using namespace std;

typedef struct Ponto {
  int x, y;

} ptr; // ptr servirá de apelido

int main() {

  // Using alias
  ptr p = {0, 1}; // usando o apelido ptr

  cout << p.x << " " << p.y << endl; // usando a instância criada p
  return 0;
}
