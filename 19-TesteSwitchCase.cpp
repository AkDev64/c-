#include <iostream>

/*
 Teste Shitch/Case
 */

#include<iostream>

bool testar(char parametro){
  switch(parametro) {
    case 's':
      std::cout << "você disse sim";
      return true;
    case 'n':
      std::cout << "você disse não";
      return false;
    default:
      std::cout << "vou entender que você disse não, por outros meios";
      return false;
  }
}

int main(){
  char escolha;
  std::cout << "sim ou não?";
  std::cin >> escolha;
  testar(escolha);
  return 0;
}
