#include <iostream>
#include "10-Produto.h"  // observar que não há <>, mas sim "", errei feio e fiquei quebrando a cabeça sem perceber.
/* Esse programa demostra a criação de uma função com uma biblioteca responsável pela prototipação da funação a ser executada
 Ou seja 10-Produto.h tem o protótipo da função produto, já o arquivo 10-Produto.cpp tem a função em si.
 Para compilar esse programa é preciso compilar junto a fonte da função -- g++ 10-PrototipoMain.cpp 10-Produto.cpp -o 10-PrototipoFuncao
 Obervar que a biblioteca prototipadora .h e a função compilada .cpp precisam ter o mesmo nome, nesse caso: Produto, derivando Produto.h e Produto.cpp 
*/

int main(){
  std::cout << "o produto de 10 * 20 é: " << produto(10,20) << '\n';
  return 0;
}
