#include <iostream>

// Explicação:
// Este exemplo demonstra o uso de objetos `const` e funções-membro `const`.
//
// - Uma função-membro `const` (com 'const' no final) promete não alterar
//   nenhum dado-membro do objeto.
//
// - Um objeto `const` é uma instância da classe que não pode ser modificada.
//
// - A regra principal: Em um objeto `const`, você SÓ PODE chamar
//   funções-membro que também são `const`.

class Cronometro {
private:
    int segundos;

public:
    // Construtor para inicializar o cronômetro
    Cronometro(int s = 0) : segundos(s) {}

    // --- Função-Membro NÃO-CONST ---
    // Esta função modifica o estado do objeto (altera 'segundos').
    // Por isso, ela NÃO pode ser 'const'.
    void incrementar() {
        segundos++;
    }

    // --- Função-Membro NÃO-CONST ---
    // Esta função também modifica o estado do objeto.
    void resetar() {
        segundos = 0;
    }

    // --- Função-Membro CONST ---
    // Esta função apenas "lê" o estado do objeto, sem modificá-lo.
    // O 'const' no final é uma promessa de que 'segundos' não será alterado.
    // É seguro chamar esta função tanto em objetos const quanto em não-const.
    int getSegundos() const {
        // Se tentássemos modificar 'segundos' aqui dentro, teríamos um erro de compilação.
        // segundos++; // ERRO!
        return segundos;
    }
};

int main() {
    std::cout << "--- Objeto Não-Constante ---" << std::endl;
    Cronometro c1; // Objeto normal, pode ser modificado.
    std::cout << "Valor inicial: " << c1.getSegundos() << std::endl;

    c1.incrementar(); // OK: c1 não é const, pode chamar uma função não-const.
    std::cout << "Depois de incrementar: " << c1.getSegundos() << std::endl;

    c1.resetar(); // OK: c1 não é const.
    std::cout << "Depois de resetar: " << c1.getSegundos() << std::endl;


    std::cout << "\n--- Objeto Constante ---" << std::endl;
    const Cronometro c2(120); // Objeto constante, NÃO pode ser modificado.

    // OK: c2 é const, e getSegundos() é uma função-membro const.
    std::cout << "Valor inicial do const: " << c2.getSegundos() << std::endl;

    // As linhas abaixo causariam um ERRO DE COMPILAÇÃO se fossem descomentadas.
    //
    // c2.incrementar(); // ERRO: 'c2' é const, não pode chamar uma função não-const.
    // c2.resetar();     // ERRO: 'c2' é const, não pode chamar uma função não-const.
    //
    // O compilador protege o objeto 'c2' de ser modificado.

    return 0;
}
