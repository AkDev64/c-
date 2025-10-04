/*
 * Esse programa mostra como passar parâmetros para o programa direto pela linha de comando que o chama
 */

#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
  // argc é a variável inteira que conta quantos parâmetros foram passados direto pela linha de comando, por exemplo $> ./a.out par2 par3 par4 tem esse valor 4. Observe que o próprio nome do programa é o primeiro parâmetro
  // *argv[] ou seu equivalente **argv representam um ponteiro para um array ou falando de outra forma pontiro de ponteiro, cada elemento desse array guarda o texto do parâmetro correspondente vindo da linha de comando

  cout << "*** Parametros Passados ao Programa pela Linha de Comando" << endl;

  for (int i=0; i<argc; i++){
    cout << "o argumento número: " << i << " é:" << argv[i] << endl;
  }

  return 0;
}
