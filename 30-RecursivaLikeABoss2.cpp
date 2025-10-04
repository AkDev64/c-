#include <iostream>
using namespace std;

int recursiva(int x) {
  return (x <= 1) ? 1 : x * recursiva(x - 1);

  // if (x == 0 || x == 1) { // esse bloco foi todo substituído pelo operador
  // ternário acima, mantive esse código só para lembrar dessa opção eficiente e
  // elegante
  //   return 1;
  // } else {
  //   return x * recursiva(x-1);
  // }
}

int main(int argc, char *argv[]) {
  int y = 10; // valor fixo, difere do mesmo programa 30-RecursivaLikeABoss.cpp
              // apenas por não receber o parâmetro da linha de comando. Fiz
              // isso para testar a compilação dessa linha que estava dando erro
              // no GCB debugger
  cout << "o fatorial de " << y << " é: " << recursiva(y) << endl;
  return 0;
}
