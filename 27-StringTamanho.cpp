#include<iostream>
using namespace std;

int main(){

  cout << "*** Tamanho da String ***" << endl;

  // definido uma string
  string str = "Qual será o meu tamanho?";

  // tamanho da string usando o método length()
  cout << "Usando str.length()" << endl;
  cout << "O seu tamanho em caracteres é: " << str.length() << endl;
  // tamanho da string usando o método size()
  cout << "Usando str.size()" << endl;
  cout << "O seu tamanho em caracteres é: " << str.size() << endl;

  return 0;
}
