/*
 * In C++, enumeration is a user-defined data type that consists of a set of
 * named integer constants. It helps in assigning meaningful names to integer
 * values to improve code readability and maintainability.
 */

#include <iostream>
using namespace std;

// Defining enum
enum direcao {
  leste,
  norte,
  oeste,
  sul // note que não precisa nem "", nem ''
};

int main() {

  // Creating enum variable
  direcao dir1 = leste; // novamente sem "" ou '', retornará 0
  direcao dir2 = norte; // novamente sem "" ou '', retornará 1
  direcao dir3 = oeste; // novamente sem "" ou '', retornará 2
  direcao dir4 = sul;   // novamente sem "" ou '', retornará 3
  cout << "direção leste: " << dir1
       << endl; // observe que retorna o número referente
                // ao nome, iniciando em zero
  cout << "direção norte: " << dir2 << endl;
  cout << "direção oeste: " << dir3 << endl;
  cout << "direção sul  : " << dir4 << endl;
  return 0;
}
