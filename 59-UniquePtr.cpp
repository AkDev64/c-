#include <iostream>
#include <memory> // Header obrigatório para ponteiros inteligentes!
#include <string>

/*
  EXPLICAÇÃO GERAL: PONTEIROS INTELIGENTES E RAII

  ### O Problema: `new` e `delete` Manuais
  Ao usar `new` para alocar memória, nós nos tornamos responsáveis por chamar
  `delete` para liberá-la. Esquecer de fazer isso (especialmente em funções
  com múltiplos pontos de saída ou em caso de exceções) causa vazamentos de
  memória (memory leaks).

  ### A Solução: RAII (Resource Acquisition Is Initialization)
  A solução do C++ moderno para isso é o princípio de RAII, que significa
  "Aquisição de Recurso é a Inicialização". A ideia é encapsular o recurso
  (neste caso, a memória do heap) dentro de um objeto.
  1. A "aquisição" do recurso (`new`) é feita no construtor do objeto.
  2. A "liberação" do recurso (`delete`) é feita no DESTRUTOR do objeto.

  Como o C++ garante que o destrutor de um objeto na stack é sempre chamado
  quando ele sai de escopo, a liberação da memória se torna automática e segura.
  Ponteiros inteligentes são exatamente isso: classes que encapsulam um ponteiro
  bruto e aplicam o princípio RAII.

  ---

  EXPLICAÇÃO ESPECÍFICA: std::unique_ptr (Ponteiro de Posse Única)

  O `std::unique_ptr` é a forma mais simples e comum de ponteiro inteligente.

  PRINCÍPIOS:
  1. POSSE EXCLUSIVA: Apenas um `unique_ptr` pode ser "dono" de um objeto
     em um determinado momento.
  2. LEVEZA: Não tem custo de performance ou memória em relação a um
     ponteiro bruto (raw pointer). É uma "abstração de custo zero".
  3. NÃO-COPIÁVEL: Você não pode copiar um `unique_ptr` (`=`). Isso reforça
     a garantia de que sempre haverá apenas um dono.
  4. MOVÍVEL: Você pode transferir a posse de um `unique_ptr` para outro
     usando `std::move`. O ponteiro original se torna nulo após a transferência.
*/

// Uma classe de exemplo para podermos ver quando ela é criada e destruída.
class Recurso {
private:
  std::string nome;

public:
  Recurso(std::string n) : nome(n) {
    std::cout << "Recurso '" << nome << "' ADQUIRIDO (Construtor)."
              << std::endl;
  }
  ~Recurso() {
    std::cout << "Recurso '" << nome << "' LIBERADO (Destrutor)." << std::endl;
  }
  void usar() {
    std::cout << "Usando o recurso '" << nome << "'." << std::endl;
  }
};

void demonstrar_posse() {
  std::cout << "\n--- Entrando na função demonstrar_posse ---\n";

  // --- CRIAÇÃO ---
  // A forma preferida de criar um unique_ptr é com `std::make_unique`.
  // Ele aloca o objeto e cria o ponteiro de forma segura e eficiente.
  // `ptr1` agora é o único dono do objeto Recurso("Teste 1") no heap.
  std::unique_ptr<Recurso> ptr1 = std::make_unique<Recurso>("Teste 1");

  // Usamos o ponteiro da mesma forma que um ponteiro bruto.
  ptr1->usar();

  std::cout << "--- Saindo da função demonstrar_posse ---\n";
  // `ptr1` sai de escopo AQUI. Seu destrutor é chamado, que por sua vez
  // chama `delete` no objeto Recurso que ele gerencia.
  // A memória é liberada automaticamente!
}

int main() {
  demonstrar_posse();

  std::cout << "\n--- Demonstração de Transferência de Posse ---\n";

  // Criamos um ponteiro inteligente.
  std::unique_ptr<Recurso> ptr_origem = std::make_unique<Recurso>("Importante");

  // A linha abaixo causaria um ERRO DE COMPILAÇÃO, pois unique_ptr não pode ser
  // copiado. std::unique_ptr<Recurso> ptr_copia = ptr_origem; // ERRO!

  // --- EXPLICAÇÃO DETALHADA DO std::move ---
  //
  // O que `std::move` faz?
  // Contrário ao que o nome sugere, `std::move` não move nada. Ele é
  // simplesmente um "cast" (uma conversão de tipo). Ele converte seu
  // argumento (uma variável normal, ou 'lvalue') em uma "referência rvalue".
  //
  // O que é uma "referência rvalue"?
  // É um tipo que representa um objeto temporário, que está prestes a ser
  // destruído. Ao fazer o cast, nós estamos prometendo ao compilador:
  // "Eu não me importo mais com o conteúdo de 'ptr_origem'. Você pode
  // roubar os recursos internos dele para usar em outro lugar."
  //
  // Como a "mágica" acontece?
  // A classe `unique_ptr` tem um "construtor de movimentação" (move
  // constructor)
  //
  // que é ativado por essa referência rvalue. Quando escrevemos a linha abaixo:
  // 1. `std::move(ptr_origem)` sinaliza que `ptr_origem` pode ser canibalizado.
  // 2. O construtor de `ptr_destino` vê esse sinal e ativa sua versão "move".
  // 3. Esse construtor ROUBA o ponteiro bruto de dentro de `ptr_origem` e o
  //    atribui a si mesmo.
  // 4. Em seguida, ele define o ponteiro interno de `ptr_origem` como
  // `nullptr`.
  //
  // Resumo: `std::move` permite a movimentação, mas é o construtor/operador
  // de atribuição da classe que efetivamente realiza a transferência.
  std::unique_ptr<Recurso> ptr_destino = std::move(ptr_origem);

  std::cout << "Posse transferida." << std::endl;

  // Agora, `ptr_destino` é o dono, e `ptr_origem` é nulo.
  ptr_destino->usar();

  if (ptr_origem == nullptr) {
    std::cout << "Ponteiro de origem agora é nulo." << std::endl;
  }

  return 0;
  // `ptr_destino` sai de escopo aqui, e o recurso "Importante" é liberado.
}
