#include <iostream>

int main (){

  std::string lista[] = {"Adriano", "Bruno", "Camila", "Silvia"};
  int tamanho = sizeof(lista)/sizeof(lista[0]);
  std::cout << "Quantidade de elementos da lista: " << tamanho << '\n'; 

  for (int i = 0; i < tamanho; i++) { // não precisa declarar a variável i antes do for
    std::cout << "Elemento " << i << " da lista: " << lista[i] << '\n';

  }


  return 0;
}
