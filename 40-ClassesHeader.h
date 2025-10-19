// Esse programa é muito similar ao 40-ClassesGetSet.cpp, mas agora vamos
// criar algumas instância (objetos) da classe e criar uma função constructor
// com base na função setter.
#include <iostream>

// Definição de uma classe

class ClasseExemplo {

  // Segmento público da classe
public: // os elementos da classe que terão contato com o contexto externo a ela
  // função membro constructor --> tema desse programa
  ClasseExemplo(std::string strParam) { // Construtor padrão sem parâmetros,
                                        // obs: a função construtor sempre tem
                                        // o mesmo nome da classe.
    defineNome(strParam); // Chama o método setter para inicializar o atributo
  }

  // função membro (método) setter
  void defineNome(std::string strParam) { // Função setter para definir o valor
                                          // do atributo privado
    this->meuatributo =
        strParam; // Atribui o valor recebido ao atributo
                  // privado.The expression this->meuAtributo is functionally
                  // equivalent to (*this).meuAtributo = strParam. this is a
                  // special, implicit pointer that is automatically available
                  // inside any non-static member function of a class. It holds
                  // the memory address of the specific object that called the
                  // member function. This allows the function to know which
                  // object's data it should operate on. The arrow operator (->)
                  // is used to access the members (variables or functions) of a
                  // class through a pointer to an object.
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
