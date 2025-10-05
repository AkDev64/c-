/*
 * Nested Structure Nested structure in C++ refers to a structure that is
 * defined inside another structure. Just as structure members are declared
 * within a structure, one structure can be declared as a member inside another
 * structure.
 */

#include <iostream>
using namespace std;

// Definindo a struct interna (do ninho)
struct interna {
  int a, b;
};

// Definindo a estrutra externa que também conterá a interna acima
struct externa {
  interna in;
  int x, y;
};

int main() {
  externa obj = {{1, 2}, 10, 20};
  cout << "Interna: " << obj.in.a << " " << obj.in.b << endl;
  cout << "Externa: " << obj.x << " " << obj.y;

  return 0;
}
