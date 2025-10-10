#include <cstdlib> // para manipular variaveis de ambiente
#include <iostream>
using namespace std;

// $env no shell do linux mostra o valor das variaveis de ambiente

int main(int argc, char *argv[]) {

  // capturar a variável HOME do ambiente linux
  string str1 = getenv("HOME");
  string str2 = getenv("SHELL");
  string str3 = getenv("PATH");
  cout << "Minha home fica em: " << str1 << '\n';
  cout << "Meu shell é: " << str2 << '\n';
  cout << "Meu Path: " << str3 << '\n';

  // rodar um comando no ambiente do Linux
  cout << "Lista dos meus arquivos: \n";
  system("ls"); // preferível não estar dentro cout, senão o que aparece é o
                // retorno da função system que seria 0 como restorno normal
  cout << "Lista dos meus arquivos: \n"
       << system("ls"); // não funciona assim como explicado acima
  return 0;
}
