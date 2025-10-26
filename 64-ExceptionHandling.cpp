#include <iostream>
#include <string>
#include <stdexcept> // Para std::runtime_error

/*
  EXPLICAÇÃO: TRATAMENTO DE EXCEÇÕES (EXCEPTION HANDLING)

  ### O Problema: Erros em Tempo de Execução
  Programas podem encontrar situações inesperadas (erros) durante a execução.
  Métodos tradicionais de tratamento de erros (como retornar códigos de erro) 
  podem ser complicados, fáceis de ignorar e não funcionam bem em construtores
  ou em cadeias longas de chamadas de função.

  ### A Solução: Exceções
  Exceções são um mecanismo do C++ para sinalizar e lidar com erros ou eventos
  incomuns de forma estruturada.

  Os três pilares do tratamento de exceções são:

  1.  `throw`: Usado para **lançar** (sinalizar) uma exceção. Quando uma exceção
               é lançada, o fluxo normal do programa é interrompido, e o controle
               é transferido para o bloco `catch` mais próximo que possa lidar
               com essa exceção.
      Exemplo: `throw std::runtime_error("Mensagem de erro!");`

  2.  `try` block: Um bloco de código onde você espera que uma exceção possa ser
                   lançada. O código dentro do `try` é monitorado para exceções.
      Exemplo:
      ```cpp
      try {
          // Código que pode lançar uma exceção
      }
      ```

  3.  `catch` block: Um bloco de código que "captura" (lida com) uma exceção
                     lançada dentro de um `try` associado. Você pode ter múltiplos
                     `catch` para diferentes tipos de exceção.
      Exemplo:
      ```cpp
      catch (const std::runtime_error& e) {
          // Lida com exceções do tipo runtime_error
      }
      catch (const std::exception& e) {
          // Lida com qualquer outra exceção padrão (polimorfismo)
      }
      catch (...) {
          // Lida com QUALQUER exceção (catch-all), use com cautela.
      }
      ```

  ### Desempilhamento da Pilha (Stack Unwinding)
  Quando uma exceção é lançada, o C++ "desempilha" a pilha de chamadas de função.
  Isso significa que ele destrói todos os objetos locais em cada função que está
  sendo encerrada, garantindo que os destrutores sejam chamados. Este processo
  é crucial para o RAII (Resource Acquisition Is Initialization) e para evitar
  vazamentos de recursos, mesmo em caso de erro.
*/

// Uma classe simples para demonstrar o desempilhamento da pilha.
class RecursoLocal {
private:
    std::string nome;
public:
    RecursoLocal(std::string n) : nome(n) {
        std::cout << "Recurso '" << nome << "' criado.\n";
    }
    ~RecursoLocal() {
        std::cout << "Recurso '" << nome << "' destruído.\n";
    }
};

// Função que pode lançar uma exceção.
double dividir(int numerador, int denominador) {
    // Cria um recurso local para demonstrar o desempilhamento.
    RecursoLocal r("temporario_dividir");
    std::cout << "Tentando dividir " << numerador << " por " << denominador << "...\n";

    if (denominador == 0) {
        // Lança uma exceção se o denominador for zero.
        throw std::runtime_error("Erro: Divisão por zero não permitida!");
    }
    return static_cast<double>(numerador) / denominador;
}

int main() {
    std::cout << "--- Início do main ---\n";

    // --- Caso 1: Divisão bem-sucedida ---
    try {
        RecursoLocal r_main_ok("main_ok"); // Recurso local no try block
        double resultado = dividir(10, 2);
        std::cout << "Resultado da divisão: " << resultado << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Capturada exceção de runtime: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Capturada exceção genérica: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------\n";

    // --- Caso 2: Divisão por zero (lança exceção) ---
    try {
        RecursoLocal r_main_erro("main_erro"); // Recurso local no try block
        double resultado = dividir(10, 0); // Isso lançará uma exceção
        std::cout << "Resultado da divisão: " << resultado << std::endl; // Esta linha não será executada
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Capturada exceção de runtime: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Capturada exceção genérica: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------\n";

    std::cout << "--- Fim do main ---\n";
    return 0;
}
