#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {

int* ptr = new int[4];
cout << "digite um número: ";
cin >> *ptr; // guarda a entrada do usuário no primeiro elemento apontado por ptr

cout << "Você digitou: " << *ptr << endl; // como pode ser ver abaixo *ptr aponta para o primeiro elemento do array apontado pelo ponteiro ptr
int n = *ptr;
for (int i=0; i<4; i++){ // 4 por que foi definido como o tamanho do array acima
  cout << ptr[i] << endl;
}

delete[] ptr;
ptr= NULL;
  return 0;
}
