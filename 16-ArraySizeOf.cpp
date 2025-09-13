#include <iostream>
// esser programa mostra como calcular o tamanho de um array em bites e em quantidade de elementos

int main(){
  int meuarray[10];
  std::cout << "o tamanho em byte do array é: " << sizeof(meuarray) << "\n";
  std::cout << "o número de elementos do array é: " << sizeof(meuarray)/sizeof(meuarray[0]) << "\n"; // observe que é necessário dividir o tamanho em bytes do array pelo tamanho em byte de um elemento para calcular a quantidade de elementos
return 0;
}
