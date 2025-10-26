// exemplo criado pelo Gemini para explicar o conceito de FRIEND FUNCTION e
// FRIEND CLASS em C++
#include <iostream>
#include <string>

// Forward declaration da classe Arrombador é necessária porque CaixaForte
// a menciona como 'friend' antes de ela ser totalmente definida.
class Arrombador;

// A classe CaixaForte que guarda um segredo.
class CaixaForte {
private:
  std::string segredo;

public:
  CaixaForte(std::string s) : segredo(s) {}

  // --- Declaração de FRIEND ---
  // 1. A função global 'espiaSegredo' é declarada como amiga desta classe.
  //    Isso dá a ela acesso aos membros 'private' e 'protected' de CaixaForte.
  friend void espiaSegredo(const CaixaForte &cofre);

  // 2. A classe 'Arrombador' é declarada como amiga.
  //    Isso dá a TODOS os métodos de 'Arrombador' acesso aos membros
  //    'private' e 'protected' de CaixaForte.
  friend class Arrombador;
};

// --- Implementação da FRIEND FUNCTION ---
// Esta é uma função normal, global, NÃO é um método de CaixaForte.
// No entanto, como foi declarada 'friend', ela pode acessar 'cofre.segredo'.
void espiaSegredo(const CaixaForte &cofre) {
  std::cout << "O espião descobriu o segredo: " << cofre.segredo << std::endl;
}

// --- Definição da FRIEND CLASS ---
// Esta classe foi declarada como amiga de CaixaForte.
class Arrombador {
public:
  // Este método, por pertencer a uma classe amiga, pode acessar
  // os membros privados de CaixaForte.
  void roubaSegredo(const CaixaForte &cofre) {
    std::cout << "O arrombador roubou o segredo: " << cofre.segredo
              << std::endl;
  }
};

int main() {
  CaixaForte cofre("1234-5678");

  std::cout << "--- Testando a Friend Function ---" << std::endl;
  // Chamando a função global que é amiga da classe.
  espiaSegredo(cofre);

  std::cout << "\n--- Testando a Friend Class ---" << std::endl;
  Arrombador ladrao;
  // Chamando um método de uma classe amiga.
  ladrao.roubaSegredo(cofre);

  // Tentar acessar o membro privado diretamente da main ainda causaria um erro.
  // O acesso só é permitido aos 'friends' declarados.
  // std::cout << cofre.segredo; // ERRO DE COMPILAÇÃO!

  return 0;
}
