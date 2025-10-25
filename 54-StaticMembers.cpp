// arquivo criado pelo Gemini para explicar membros static em C++
#include <iostream>
#include <string>

// Explicação:
// Membros 'static' pertencem à CLASSE como um todo, e não a cada objeto
// individualmente. Existe apenas UMA cópia de um membro static que é
// compartilhada entre todos os objetos da classe.

class Guerreiro {
private:
  std::string nome; // Membro normal: cada guerreiro tem seu próprio nome.

  // --- MEMBRO DE DADO STATIC ---
  // Membro static: esta variável é compartilhada por TODOS os objetos
  // Guerreiro.
  static int total_guerreiros;

public:
  // Construtor: chamado sempre que um novo objeto Guerreiro é criado.
  Guerreiro(std::string n) : nome(n) {
    std::cout << nome << " entrou na batalha!" << std::endl;
    // Incrementa a contagem TOTAL de guerreiros.
    total_guerreiros++;
  }

  // Destrutor: chamado quando um objeto Guerreiro é destruído.
  ~Guerreiro() {
    std::cout << nome << " foi derrotado!" << std::endl;
    // Decrementa a contagem TOTAL de guerreiros.
    total_guerreiros--;
  }

  // --- FUNÇÃO-MEMBRO STATIC ---
  // Uma função static também pertence à classe, não a um objeto específico.
  // Ela só pode acessar outros membros static.
  // Não pode acessar 'nome', pois não sabe 'de qual guerreiro' é o nome.
  static int getTotalGuerreiros() { return total_guerreiros; }
};

// --- INICIALIZAÇÃO DO MEMBRO STATIC ---
// A variável static precisa ser inicializada fora da classe, no escopo global.
// Isso efetivamente aloca a memória para a variável única.
int Guerreiro::total_guerreiros = 0;

void combate() {
  std::cout << "\n--- Entrando em um combate local ---\\n";
  Guerreiro g3("Poppy");
  std::cout << "Guerreiros em combate: " << Guerreiro::getTotalGuerreiros()
            << std::endl;
  std::cout << "--- Fim do combate local ---\\n";
  // 'g3' sai de escopo aqui, e seu destrutor é chamado.
}

int main() {
  // Podemos chamar a função static mesmo sem ter criado nenhum objeto.
  std::cout << "Guerreiros no início: " << Guerreiro::getTotalGuerreiros()
            << std::endl;

  // Criando dois guerreiros. O construtor de cada um incrementará o contador.
  Guerreiro g1("Garen");
  Guerreiro g2("Darius");

  std::cout << "Guerreiros após recrutamento: "
            << Guerreiro::getTotalGuerreiros() << std::endl;

  // Chamando a função que cria e destrói um guerreiro em seu próprio escopo.
  combate();

  std::cout << "Guerreiros após o combate: " << Guerreiro::getTotalGuerreiros()
            << std::endl;

  return 0;
  // g1 e g2 saem de escopo aqui, e seus destrutores são chamados.
}
