#include <iostream>

int main(){

// criando e imprimindo os valores da string
  std::string meuarray[3] = {"Elis","Tim","James"}; // o índice do string vai de 0 a n-1
  std::cout << meuarray[0] << ", " << meuarray[1] << ", " << meuarray[2] << '\n';
  std::cout << "O ponteiro a seguir aponta para o endereço de memória do array: \n" << meuarray << '\n'; // entender melhor como usar esse endereço 

// alterando valores dos elementos da string
 // meuarray = {"Adriano", "Bruno", "Camila"}; // não é possivel atribuir valores dessa forma para um array já inicializado
  meuarray[0] = "Rafaela"; // essa é a maneira correta, elemento a elemento. Pode ser facilitado por algum método de loop.
  std::cout << "imprimindo o valor alterado para primeira posição do array \n";
  std::cout << meuarray[0] << '\n';

  return 0;
}
