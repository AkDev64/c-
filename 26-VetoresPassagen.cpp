#include<iostream>
#include<vector>
using namespace std;

int main() {
  //definição do vector
  vector<int> vetor = {1, 10, 100, 1000, 10000};

  //algorítimo de passagem pelo vetor
  for (int i=0; i<vetor.size(); i++){
    cout << "Elemento " << i << ": " << vetor[i] << endl;
  }
  return 0;
}
