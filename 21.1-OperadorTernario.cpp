#include <iostream>
using namespace std;

int main (){
  
  // incializando num e capturando um valor para ele pela entrada do usuário
  int num = 0;
  std::cout << "digite um número: \n";
  std::cin >> num;

  // operador ternário: condicao? expressão1 : expressão1
  num > 10 ? cout << "sim" : cout << "não";
  cout << endl;

  // outra forma de usar o operador ternário
  cout << (num > 10 ? "SIM" : "NÃO") << '\n';
  

  return 0;
}
