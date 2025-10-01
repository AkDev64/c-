#include<iostream>
#include<vector>
using namespace std;

int main() {
  
  // definição do vector
  vector<char> vtr = {'a','b','c','d','e','f','g','h','i','j','k','l'};
  cout << "testando a impressão direta e por referência dos elementos usando o for (int i : vetor): " << endl;
  for (int i : vtr) {
    // cout << "vtr[i]:" << vtr[i]; // não funciona nesse caso por se tratar de vetor do tipo char.
    cout << " i:" << i << endl; // imprime o código ascii de cada elemento do vetor vtr. Isso ocorre por causa da forma como foi feito o for(), Desta maneira ele converte para valor inteiro cada conteúdo achado nos elementos e tenta passar um por um na função for, pode ser útil para outras finalidade como conversão ou impressão de inteiros, melhor fazer o iterador for() da maneira abaixo.
  }

  cout << "testando a impressão direta e por referência dos elementos usando o for (int i; i < vetor.size()-1;i++): " << endl;
  for (int i = 0; i < vtr.size()-1; i++) { // essa forma de fazer o iterador for funciona melhor para casos mais genéricos
    cout << "vtr[i]:" << vtr[i]; 
    cout << " i:" << i << endl; 
  }


  return 0;
}
