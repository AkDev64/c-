// Figura 9.3: fig09_03.cpp
// Programa para testar a classe Time.
// NOTA: Esse arquivo deve ser compilado com Time.cpp.
#include <iostream>
using std::cout;
using std::endl;

#include "42-Time.h" // inclui a definição da classe Time a partir de Time.h

int main() {
  Time t; // instancia o objeto t da classe Time

  // gera saída de valores iniciais do objeto Time t
  // ALTERADO: Aspas curvas (“”) trocadas por aspas retas (""")
  cout << "The initial universal time is ";
  t.printUniversal(); // 00:00:00
  cout << "\nThe initial standard time is ";
  t.printStandard(); // 12:00:00 AM

  t.setTime(13, 27, 6); // muda a hora

  // gera saída de novos valores do objeto Time t
  // ALTERADO: Aspas curvas (“”) trocadas por aspas retas (""")
  cout << "\n\nUniversal time after setTime is ";
  t.printUniversal(); // 13:27:06
  cout << "\nStandard time after setTime is ";
  t.printStandard(); // 1:27:06 PM

  t.setTime(99, 99, 99); // tenta configurações inválidas

  // gera saída de valores de t depois de especificar valores inválidos
  // ALTERADO: Aspas curvas (“”) trocadas por aspas retas (""")
  cout << "\n\nAfter attempting invalid settings:" << "\nUniversal time: ";
  t.printUniversal(); // 00:00:00
  cout << "\nStandard time: ";
  t.printStandard(); // 12:00:00 AM
  cout << endl;
  return 0;
} // fim de main