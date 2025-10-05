/*
 * Nesse programa é apresentadao o coceitode função membro de uma struct
 */

#include <cmath>
#include <iostream>
using namespace std;

struct Ponto {
  int x,
      y; // define que a struct ponto contem dois inteiros na sua constituição

  float distancia() { // Calculando a distância do ponto à origem
    return pow(pow(x, 2) + pow(y, 2), 0.5);
  }
}; // necessário o uso de ponto e vírgula para terminhar a definição da struct

int main(int argc, char *argv[]) {

  // Defindo um ponto com base da struct Ponto
  struct Ponto ptr = {3, 4};

  // Chamando a função membro para o ptr1
  cout << "distância do ponto p(" << ptr.x << "," << ptr.y
       << ") para origem é: ";
  cout << ptr.distancia() << endl;

  // mesma coisa para um ponto definido pelo necessário
  cout << "Digite a coordenada x: ";
  cin >> ptr.x;
  cout << endl << "Digite a coordenada y: ";
  cin >> ptr.y;
  cout << ptr.distancia();

  return 0;
}
