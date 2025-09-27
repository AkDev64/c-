#include<iostream>
#include<vector>
using namespace std;

int imprime(vector<char> v){
  cout << endl;
  for (int x : v){
    cout << x << " ";
  }
  return 0;
}

int main () {
    //inicialização do vector
    vector<char> vetor = {'a','b','c','d','e','f'};

    //acessando usando operador
    cout << "Elemento com índice 2 usando o operador []: " << vetor[2] << endl;

    //acesando usando o método at()
    cout << "Elemento com índice 3 usando o método at(): " << vetor.at(3) << endl;
  return 0;
}
