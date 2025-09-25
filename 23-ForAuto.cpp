#include <iostream>

int main () {
 
  std::string lista[] = {"Adriano", "Kelen", "Rafela", "Elvis"};
  int tamanhoLista = sizeof(lista)/sizeof(lista[0]);

  for (auto i : lista){
    std::cout << "Elemento: " << i << '\n';
  }

  return 0;
}
