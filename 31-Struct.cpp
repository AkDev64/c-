/*
 * Uso de struct permite em c++ permite criar tipo de dados definido pelo
 * usuário para armazenar dados de diferentes tipos de dados
 */

#include <cmath>
#include <iostream>
using namespace std;

struct Ponto {
  int x,
      y; // define que a struct ponto contem dois inteiros na sua constituição
}; // necessário o uso de ponto e vírgula para terminhar a definição da struct

int main(int argc, char *argv[]) {

  // Defindo um ponto com base da struct Ponto
  struct Ponto ptr1 = {0, 1};
  struct Ponto ptr2 = {5, 5};

  // Acessando os membros
  cout << "ponto 1:" << ptr1.x << " " << ptr1.y << '\n';
  cout << "ponto 2:" << ptr2.x << " " << ptr2.y << '\n';

  // Calculando a distância entre os pontos
  float distancia = 0;
  distancia = pow(pow(ptr2.x - ptr1.x, 2) + pow(ptr2.y - ptr1.y, 2), 0.5);
  cout << "distância entre os pontos é: " << distancia;

  return 0;
}

/*
 * <BS>Initialize Structure Members

Structure members cannot be initialized with declaration. For example, the
following C++ program fails in compilation.

struct Point
{
    int x = 0;
    int y = 0;
};
*/
