#include <iostream>
#include <memory> // Header obrigatório para ponteiros inteligentes!
#include <string>

/*
  EXPLICAÇÃO: std::shared_ptr (Ponteiro Inteligente de Posse Compartilhada)

  ### O Problema: E se Precisarmos de Múltiplos Donos?
  `unique_ptr` é perfeito quando um objeto tem um único dono. Mas e se várias
  partes do seu código precisarem de acesso a um mesmo objeto, e qualquer uma
  delas pode ser a última a terminar de usá-lo? Quem seria o responsável por
  deletar a memória? É para isso que o `std::shared_ptr` existe.

  ### A Solução: Contagem de Referências (Reference Counting)
  `shared_ptr` implementa a semântica de **posse compartilhada**.

  - **Como funciona?** Ele mantém um "contador de referências" interno para o
    objeto no heap.
    1. Quando um `shared_ptr` é criado (com `std::make_shared`), o contador
       começa em 1.
    2. Toda vez que você **copia** um `shared_ptr` para outro, o contador é
       **incrementado**.
    3. Toda vez que um `shared_ptr` é destruído (sai de escopo, por exemplo),
       o contador é **decrementado**.
    4. O `delete` no objeto original só é chamado quando o contador chega a
  **zero**.

  Isso garante que o objeto permanece vivo enquanto houver pelo menos um
  `shared_ptr` apontando para ele.

  - **Custo:** `shared_ptr` é um pouco mais "pesado" que `unique_ptr` por causa
    da sobrecarga de gerenciar esse contador. A regra geral é:
    **use `unique_ptr` por padrão e mude para `shared_ptr` apenas quando
    precisar explicitamente de posse compartilhada.**
*/

// Usando a mesma classe de exemplo para vermos o ciclo de vida do objeto.
class Recurso {
private:
  std::string nome;

public:
  Recurso(std::string n) : nome(n) {
    std::cout << "Recurso '" << nome << "' ADQUIRIDO." << std::endl;
  }
  ~Recurso() { std::cout << "Recurso '" << nome << "' LIBERADO." << std::endl; }
};

int main() {
  std::cout << "--- Início do main ---" << std::endl;

  // --- 1. CRIAÇÃO ---
  // A forma preferida é `std::make_shared`. Ele aloca o objeto e o bloco
  // de controle (que contém o contador) em uma única operação, o que é mais
  // eficiente.
  std::shared_ptr<Recurso> ptr1 = std::make_shared<Recurso>("Compartilhado");

  // O método `use_count()` nos permite inspecionar o contador de referências.
  std::cout << "Contagem de referências: " << ptr1.use_count()
            << std::endl; // Deve ser 1

  // --- 2. COPIANDO (COMPARTILHANDO A POSSE) ---
  std::cout << "\n--- Criando um segundo shared_ptr por cópia ---" << std::endl;
  std::shared_ptr<Recurso> ptr2 =
      ptr1; // Copia ptr1. A posse agora é compartilhada.

  std::cout << "Contagem de referências: " << ptr1.use_count()
            << std::endl; // Deve ser 2
  std::cout << "Contagem (via ptr2): " << ptr2.use_count()
            << std::endl; // É o mesmo contador

  // --- 3. CICLO DE VIDA EM ESCOPO ---
  {
    std::cout << "\n--- Entrando em um novo escopo ---" << std::endl;
    std::shared_ptr<Recurso> ptr3 = ptr1;
    std::cout << "Contagem de referências: " << ptr1.use_count()
              << std::endl; // Deve ser 3
    std::cout << "--- Saindo do novo escopo ---" << std::endl;
    // `ptr3` sai de escopo AQUI. Seu destrutor é chamado, e o contador
    // de referências é decrementado. O objeto Recurso NÃO é destruído.
  }

  std::cout << "\n--- Após sair do escopo ---" << std::endl;
  std::cout << "Contagem de referências: " << ptr1.use_count()
            << std::endl; // Deve ser 2

  std::cout << "\n--- Fim do main ---" << std::endl;
  // `ptr1` e `ptr2` sairão de escopo aqui.
  // O destrutor do último shared_ptr a ser destruído verá que o contador
  // chegou a zero e, finalmente, chamará `delete` no objeto Recurso.
  return 0;
}
