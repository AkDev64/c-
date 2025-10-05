/*
 * Esse programa apresenta construtores e destruidores de struct
 * Interessante observar também a questão do escopo private e public da struct
 * bem como o acesso direto e intdireto para criar instâncias da struct
 */

#include <cmath>
#include <iostream>
using namespace std;

struct Ponto {

private: // entender melhor
  int x,
      y; // define que a struct ponto contem dois inteiros na sua constituição

public:
  // Construtores
  Ponto(int a, int b) {
    x = a;
    y = b;
  }

  // Função Membro para imprimir
  void mostrar() { cout << x << " " << y << '\n'; }

  // Destruidor de instâncias
  ~Ponto() { cout << "Destruído o ponto específico" << endl; }

  // Devolve os elementos do Struct Ponto para acesso
  int X() { return x; }
  int Y() { return y; }

}; // necessário o uso de ponto e vírgula para terminhar a definição da struct

int main(int argc, char *argv[]) {

  // Defindo um ponto com base da struct Ponto --> direto como no primeiro
  // programa 31-Struct.cpp
  //  struct Ponto ptr1 = {0, 1}; a declaração direta não funciona mesmo hein.
  // struct Ponto ptr2 = {5, 5}; idem

  // Agora sim, criando as isntâncias por meio do construtor
  Ponto ptr1(0, 0);
  Ponto ptr2(4, 3);

  // Acessando os membros - assim como a criação direta, o acesso direto também
  // não funciona
  // cout << "ponto 1:" << ptr1.x << " " << ptr1.y << '\n';
  // cout << "ponto 2:" << ptr2.x << " " << ptr2.y << '\n';
  cout << "Ponto 1: ";
  ptr1.mostrar();
  cout << "Ponto 2: ";
  ptr2.mostrar();

  // Calculando a distância entre os pontos
  float distancia = 0;
  distancia =
      pow(pow(ptr2.X() - ptr1.X(), 2) + pow(ptr2.Y() - ptr1.Y(), 2), 0.5);
  cout << "distância entre os pontos é: " << distancia << endl;

  return 0;
}
