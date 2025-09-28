#include<iostream>
#include<vector>
using namespace std;

int imprime(vector<double> vtr) {
  cout << endl;
  for (double i : vtr){
    cout << i << endl;
  }
  return 0;
}

int main () {
  // inicializando um vetor do tipo double
  vector<double> vetor = {1.1, 2.3, 3.4, 5.9, 10.0};
  
  // imprimindo o valor do elemento de indíce 2 antes da alteração
  cout << "Valor original do elemento de índice 2 " << vetor[2] << endl;

  // alterando o valor desse mesmo elemento
  vetor[2] = 9.9;

  cout << "Valor atualizado do mesmo elemento " << vetor[2] << endl;

  return 0;
}


