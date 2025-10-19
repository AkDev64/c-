// Esse programa é muito paracido como anteiror, mas agora invocamos a função
// membro com a passagem de um parâmetro
#include <iostream>

// Definição de uma classe

class ClasseExemplo {
public: // os elementos da classe que terão contato com o contexto externo a ela
  void mostrarMensagem(std::string str) { // Exemplo de uma função membro
    std::cout << "Essa mensagem é um exemplo de tarefa executada pela minha "
                 "função mebro da classe ClasseExemplo"
              << ' ' << '\n'
              << str << '\n';
  }
};

int main(int argc, char *argv[]) {

  ClasseExemplo objetoExemplo; // apenas cria um objeto do tipo ClasseExemplo
  std::string strExemplo;      // define uma variável do tipo std::string para
                               // receber o valor definido pelo usuário
  std::cout
      << "Digite um texto: "
      << '\n'; // apenas o texto para solicitar a entrada de dados pelo usuário
  getline(std::cin,
          strExemplo); // getline é a função que realmente aguarda a entrada
  std::cout << '\n';   // apenas para inserir uma linha
  objetoExemplo.mostrarMensagem(strExemplo); // chama a função membro do objeto
  return 0;
}
