#include<iostream>
using namespace std;

int main(){

cout << "*** Procurando na String***" << endl;

// Definindo uma string grande
string str = "Uma string que pode ter muito conteúdo interessante";

// Procurando
int posFind = str.find("conteúdo");

if (posFind < str.size()){
  cout << "Achei conteúdo na string na posição: " << posFind << endl;
}

  return 0;
}
