#include <iostream>

/*
Entrada padrão do usuário std::cin 
*/

int main(){
  std::cout << "Digite sua primeira entrada em C++: \n";
  char resposta = 0;
  std::cin >> resposta;
  std::cout << "você digitou: " << resposta << "\n  veja que só aparaceu a primeira tecla digitada, o tipo é char \n";
return 0;
}
