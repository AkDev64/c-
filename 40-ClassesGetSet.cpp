// Esse programa é muito similar ao 40-FuncoesParametro.cpp, mas agora vamos
// criar duas funções membros importantes, uma setter e uma getter, para definir
// e obter o valor de um atributo privado da classe.
#include <iostream>

// Definição de uma classe

class ClasseExemplo {

  // Segmento público da classe
public: // os elementos da classe que terão contato com o contexto externo a ela
  // função membro (método) setter
  void defineNome(std::string strParam) { // Função setter para definir o valor
                                          // do atributo privado
    this->meuatributo = strParam; // Atribui o valor recebido ao atributo
                                  // privado. entender esse tipo de sintaxe.
  }

  // função membro (método) getter
  std::string
  obterNome() {         // Função getter para obter o valor do atributo privado
    return meuatributo; // Retorna o valor do atributo privado
  }

  // Segmento privado da classe
private: // os elementos da classe que não terão contato com o contexto externo
  std::string meuatributo; // atributo privado da classe
};

int main(int argc, char *argv[]) {

  // criação da instância e de uma variável
  ClasseExemplo objetoExemplo; // apenas cria um objeto do tipo ClasseExemplo
  std::string strNome;         // string para receber o nome

  // solicitação de entrada e utilização dos métodos setter e getter
  std::cout << "Digite um texto: " << '\n';
  getline(std::cin, strNome);
  std::cout << '\n'; // getline é a função que realmente aguarda a entrada

  // setando (setter) o valor do meuatribudo dentro da classe
  objetoExemplo.defineNome(strNome); // chama a função membro do objeto
                                     //
  // capturando (getter) o valor do meuatribudo dentro da classe e imprimindo
  std::cout << objetoExemplo.obterNome()
            << " está registrado dentro do objeto e mostrando aqui usando "
               "respectivamente o método setter e getter definidos na classe"
            << '\n'; // chama a função membro do objeto

  return 0;
}
