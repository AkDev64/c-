#include<iostream>
// teste de comparação

int main(){

  std:: cout<<"Continuar? \n";
  char resposta = 0;
  std::cin >> resposta;

  if(resposta=='s') 
    std::cout << "quer sim";
  else  
    std::cout << "quer não";
  return 0;
}
