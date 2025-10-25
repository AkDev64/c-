#include <iostream>
#include <memory>
#include <string>

/*
  EXPLICAÇÃO: std::weak_ptr e o Problema do Ciclo de Referências

  ### O Problema: Ciclos de Referência com `shared_ptr`
  Imagine que o Objeto A tem um `shared_ptr` para o Objeto B, e o Objeto B
  tem um `shared_ptr` de volta para o Objeto A.

  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();
  a->ptr_b = b; // Contador de B sobe para 2
  b->ptr_a = a; // Contador de A sobe para 2

  Quando os ponteiros originais 'a' and 'b' saem de escopo, os contadores de
  referência de ambos os objetos ficam em 1. O objeto A não pode ser destruído
  porque B ainda aponta para ele, e B não pode ser destruído porque A ainda
  aponta para ele. Temos um ciclo de posse que impede a liberação da memória,
  causando um **vazamento de memória (memory leak)**.

  ### A Solução: `std::weak_ptr`
  O `weak_ptr` é um ponteiro "observador", ele não é um "dono".

  - Ele "observa" um objeto que está sendo gerenciado por um ou mais
`shared_ptr`s.
  - **Crucial:** Criar um `weak_ptr` a partir de um `shared_ptr` **NÃO**
    incrementa o contador de referências.
  - Como ele não é dono, o objeto pode ser destruído mesmo que existam
`weak_ptr`s apontando para ele.
  - **Como usar:** Você não pode acessar o objeto diretamente por um `weak_ptr`.
    Você precisa primeiro tentar "travá-lo" com o método `lock()`.
    - `lock()`: Tenta criar um `shared_ptr` a partir do `weak_ptr`.
      - Se o objeto original ainda existir, `lock()` retorna um `shared_ptr`
válido.
      - Se o objeto original já foi destruído, `lock()` retorna um `shared_ptr`
vazio (nulo).
    - Isso garante que você nunca acesse um objeto que já foi destruído.

A solução para o ciclo de referência é usar `weak_ptr` em uma das direções
  do relacionamento, quebrando o ciclo de posse.
*/

// Forward declarations são necessárias pois as classes se referenciam
// mutuamente.
class Pessoa;

class Apartamento {
public:
  std::string numero;

  // O Apartamento "observa" seu inquilino, mas não o possui.
  // Se a Pessoa for destruída, o Apartamento saberá através do weak_ptr.
  std::weak_ptr<Pessoa> inquilino;

  Apartamento(std::string n) : numero(n) {
    std::cout << "Apartamento " << numero << " criado.\n";
  }
  ~Apartamento() { std::cout << "Apartamento " << numero << " destruído.\n"; }
};

class Pessoa {
public:
  std::string nome;

  // A Pessoa é "dona" de seu apartamento.
  std::shared_ptr<Apartamento> apartamento;

  Pessoa(std::string n) : nome(n) {
    std::cout << "Pessoa '" << nome << "' criada.\n";
  }
  ~Pessoa() { std::cout << "Pessoa '" << nome << "' destruída.\n"; }
};

int main() {
  std::cout << "--- Início do programa ---";
  {
    // Criamos os objetos gerenciados por shared_ptr
    auto joao = std::make_shared<Pessoa>("João");
    auto ap101 = std::make_shared<Apartamento>("101");

    std::cout << "Contagem do Ap: " << ap101.use_count()
              << " | Contagem do João: " << joao.use_count() << std::endl;

    // Ligamos os objetos
    joao->apartamento = ap101; // Pessoa é dona do Apartamento
    ap101->inquilino = joao;   // Apartamento observa a Pessoa (NÃO incrementa o
                               // contador de João)

    std::cout << "Após ligar os ponteiros:\n";
    std::cout << "Contagem do Ap: " << ap101.use_count()
              << " | Contagem do João: " << joao.use_count() << std::endl;
    std::cout << "--------------------------------\n";

    // Verificando o inquilino a partir do apartamento
    std::cout << "Verificando o inquilino do ap " << ap101->numero << "...\n";
    // Usamos lock() para obter um shared_ptr temporário e seguro
    if (auto inquilino_ptr = ap101->inquilino.lock()) {
      std::cout << "O inquilino é: " << inquilino_ptr->nome << std::endl;
    } else {
      std::cout << "O apartamento está vago.\n";
    }
    std::cout << "--------------------------------\n";
  } // joao e ap101 saem de escopo aqui.
    // 1. O destrutor de `joao` é chamado. O contador de `Pessoa` vai a zero.
    // `Pessoa` é destruída.
    // 2. Ao destruir `Pessoa`, seu membro `apartamento` (um shared_ptr) é
    // destruído.
    // 3. O contador de `Apartamento` vai a zero. `Apartamento` é destruído.
    // O ciclo foi quebrado e não há vazamento de memória!

  std::cout << "--- Fim do programa ---";
  return 0;
}
