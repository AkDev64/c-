#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int a = 1;
  cout << "valor de a: " << a << '\n';
  cout << "o endereço de onde a está arquivado: " << &a << '\n';

  int *p = &a;
  cout << "endereço onde o ponterio p aponta: " << p << '\n';
  cout << "o endereço onde p está guardado: " << &p << '\n';
  cout << "o valor para o qual p aponta (desreferenciamento): " << *p << '\n';

  return 0;
}
