#include<iostream>
using namespace std;

int main () {
 
int valor = 0;
int* ptr = NULL;
//ptr = &valor; // comente essa linha para ver diferença no comportamento do programa

// entrando valor pelo usuário
cout << "digite um valor inteiro:";
cin >> valor;

//testando se o ponteiro foi apontado para algum valor não nulo
if (ptr!=NULL) {
  cout << "o valor contido no endereço de memória " << ptr << " é " <<*ptr;
} else {
  cout << "o ponteiro é nulo";
}

return 0;
}

