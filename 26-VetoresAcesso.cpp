#include <iostream>
#include <vector>
using namespace std;


int imprime(vector<char> v){
  cout << endl;
  for (char x : v){ // passei 1 hora para entender o erro nessa linha tinha colocado (char x, v) com vírgula e não (char x : v) 
    cout << x << " ";

  }
  cout << "tamanho do vetor : " << v.size();
  return 0;
}

int main () {
 // inicializa um vetor
 vector<char> vetor = {'a','b','c','d','e','f','g','h'};
 imprime(vetor);
  return 0;
}
