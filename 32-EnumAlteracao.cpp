/*
 * Alterando o valor de uma instância de uma estrutura enumerada (enum)
 */

#include <iostream>
using namespace std;

// Defining enum
enum Frutas {
  maça,
  banana = 5,
  laranja // observe que pode ser estabelecido um valor inicial diferente do
          // altomaticamente enumerado partindo de zero
};

int main() {

  // Criando umas instâncias do tipo enumerado Frutas
  Frutas frt1 = maça;
  Frutas frt2 = banana;
  Frutas frt3 = laranja;

  // Mostrando a situação original
  cout << "*** Situação Original do Tipo Enumerado Frutas" << endl;
  cout << "frt1: " << frt1 << endl;
  cout << "frt2: " << frt2 << endl;
  cout << "frt3: " << frt3 << endl;

  // Mudando as instâncias de fruta
  frt1 = banana;
  frt2 = laranja;
  frt3 = maça;

  // Mostrando a situação original
  cout << "*** Situação Após Alteração do Tipo Enumerado Frutas" << endl;
  cout << "frt1: " << frt1 << endl;
  cout << "frt2: " << frt2 << endl;
  cout << "frt3: " << frt3 << endl;

  return 0;
}
