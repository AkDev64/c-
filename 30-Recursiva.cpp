#include<iostream>
using namespace std;
// apanhei feio da recursividade
// meu código não ficou legal
// não consegui passar o retorno com o número correto para o main 
//
int recursiva(int x, int r){
  if (x>0) {
  int resultado = r * (x);
  cout << r << "*" << x << " é igual: " << resultado << endl;
  recursiva(x-1, resultado);
  } 
  int resultado = r;
  return resultado;
}

int main (int argc, char *argv[]) {
  cout << "argv[1]: " << argv[1] << endl;
  int y = stoi(argv[1]);
  if(y!=0){
    int z = recursiva(y, 1);
  } else {
    cout << "não posso calcular o fatorial desse argumento: " << argv[1];
  }

  return 0;
}
