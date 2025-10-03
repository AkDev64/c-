#include<iostream>
using namespace std;

int main(){

  cout << "*** Acessando Caracter de Uma String ***" << endl;

  // definindo a string
  string str = "Uma String Qualquer";

  // Acessando um caracter da string diretamente str[]
  cout << "Acessando um caracter da string diretamente str[]" << endl;
  cout << "Primeiro caracter da string: " << str[0] << endl;
  cout << "Décimo caracter da string:   " << str[9] << endl;


  // Acessando um caracter da string usando at()
  cout << "Acessando um caracter da string usando at()" << endl;
  cout << "Primeiro caracter da string: " << str.at(0) << endl;
  cout << "Décimo caracter da string:   " << str.at(9) << endl;

  return 0;
}
