#include <iostream>

// Definição de uma classe

class ClasseExemplo {
public: // os elementos da classe que terão contato com o contexto externo a ela
  void mostrarMensagem() { // Exemplo de uma função membro
    std::cout << "Essa mensagem é um exemplo de tarefa executada pela minha "
                 "função mebro da classe ClasseExemplo"
              << '\n';
  }
};

int main(int argc, char *argv[]) {

  ClasseExemplo objetoExemplo; // apenas cria um objeto do tipo ClasseExemplo
  objetoExemplo.mostrarMensagem(); // chama a função membro do objeto
  return 0;
}
