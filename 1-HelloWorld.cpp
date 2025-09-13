#include <iostream>

int main(){ // mesmo a função main tem a definição do tipo de dados, que no caso é int.

	std::cout << "Hello, World!\n"; // 1) std:: define utilização do name space da biblioteca std (standard), há como evitar isso com a diretiva --using namespace std-- como será visto no próximo programa 2-UsingNamespace. 2) notar que "\n" equivale ao caracter especial <CR> de nova linha. 
  return 0;
}
