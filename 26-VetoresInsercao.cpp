#include<iostream>
#include<vector>
using namespace std;

int imprime(vector<char> v){ // observe a necesidade de definir o tipo de vetor no parâmetro da função
// imprimindo o vetor
  cout << endl;
for (char x : v ){
    cout << x << " ";
}
return 0;
}


int main () {
 
// incializando um vetor vazio
vector<char> vetor1;

// inserindo valores de forma eficiente ao final do vetor a cada inserção
vetor1.push_back('a');
vetor1.push_back('b');
vetor1.push_back('c');
vetor1.push_back('d');
vetor1.push_back('e');
vetor1.push_back('f');
vetor1.push_back('g');
vetor1.push_back('h');
imprime(vetor1);

// inserindo A no começo do vetor
vetor1.insert(vetor1.begin(), 'A');
imprime(vetor1);

// inserindo D na quarta posição, ou seja, .begin() + 3
vetor1.insert(vetor1.begin() + 3, 'D');
imprime(vetor1);

// imprimindo o tamanho do vetor1
cout << '\n' << "tamanho do vetor " << vetor1.size();

// uma outra forma de imprimir o vetor1
cout << '\n';
for(int i=0; i<vetor1.size(); i++){ // é necessário que a condição seja i < que size(), caso contrário ocorre erro em tempo de execução
  cout << vetor1[i] << " ";
}

return 0;
}
