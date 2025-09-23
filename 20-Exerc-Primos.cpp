/*
 * Esse programa é para realizar um exercício.
 * Responder se um número fornecido pelo usuário é primo ou não.
 * Não é necessário tratamento de erro se a entrada não for número.
 * */

#include <iostream>
#include <cmath>
using namespace std;

bool testarPrimo(int parametro) {

  if (parametro<=1) {
    cout << "não é primo, retorno booleano: ";
      return 0;
  } else {
    int limite = pow(parametro, 0.5);
    cout << "pesquisar até " << limite << '\n'; 
    int testador = 2;
    int volta = 0;
    for(testador=2; testador<=limite; testador++){
      volta = volta + 1;
      cout << "volta: " << volta << ", testando módulo de: " << parametro << "%"<< testador << '\n';
      if (parametro % testador == 0){
//        cout << testador << "@4 \n";
        cout << "não é primo, retorno booleano: ";
        return 0;
      } 
    }
    cout << "é primo, retorno booleano: ";
    return 1;
  }

}


int main(){
  cout << "Entre com um número inteiro para testar se ele é primo:";
  int numero = 0;
  cin >> numero;
  cout << testarPrimo(numero);

  return 0;
}
