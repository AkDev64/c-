#include<iostream>
using namespace std;

int main(){

  cout << "*** Criando uma String, passando por ela e imprimindo na tela ***" << endl;

  // Criando uma string
  string str = "Oi Pessoal"; // str é o nome da string, string é uma classe do namespace std (std::string)
  
  // Passando pela string e imprimindo 
  cout << "Usando loop for normal: ";
  for (int i=0; i<str.size();i++){
    cout << str[i];
  }
  cout << endl;  

  // Passando pela string usando iterator
    cout << "Usando iterador: ";
    for (auto it = str.begin(); it != str.end(); it++) {
        cout << *it ;
    }
    cout << endl;

  return 0;
}
