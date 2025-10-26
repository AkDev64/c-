#include <iostream>
#include <string>

/*
  EXPLICAÇÃO: TEMPLATES DE FUNÇÃO

  Um template de função é uma "receita" ou um "molde" que o compilador usa
  para gerar funções para diferentes tipos de dados em tempo de compilação.
  Isso evita a duplicação de código e promove a programação genérica.

  A sintaxe `template <typename T>` (ou `template <class T>`) declara um
  parâmetro de tipo genérico 'T'. O compilador deduzirá o tipo real de 'T'
  com base nos argumentos passados para a função.
*/

// --- Template de Função 1: imprimir ---
// Uma única função genérica que pode imprimir qualquer tipo de dado
// que seja compatível com o operador '<<' do std::cout.
template <typename T> void imprimir(T valor) {
  std::cout << "Valor: " << valor << std::endl;
}

// --- Template de Função 2: Max ---
// Uma função genérica que retorna o maior de dois valores.
// Isso funciona para qualquer tipo 'T' que suporte o operador '>'.
template <typename T> T Max(T a, T b) { return (a > b) ? a : b; }

int main() {
  std::cout << "--- Testando o template imprimir() ---" << std::endl;
  // O compilador gera uma versão de imprimir() onde T = int
  imprimir(42);
  // O compilador gera uma versão de imprimir() onde T = double
  imprimir(3.14159);
  // O compilador gera uma versão de imprimir() onde T = std::string
  imprimir(std::string("Olá, Template!"));

  std::cout << "\n--- Testando o template Max() ---" << std::endl;
  // O compilador gera e chama Max<int>(a, b)
  std::cout << "Maior entre 10 e 20: " << Max(10, 20) << std::endl;

  // O compilador gera e chama Max<double>(a, b)
  std::cout << "Maior entre 5.5 e 2.2: " << Max(5.5, 2.2) << std::endl;

  // O compilador gera e chama Max<char>(a, b)
  std::cout << "Maior entre 'a' e 'z': " << Max('a', 'z') << std::endl;

  // A linha abaixo funcionaria para std::string também, pois string
  // suporta o operador > para comparação lexicográfica.
  // std::cout << "Maior entre \"apple\" e \"orange\": " <<
  // Max(std::string("apple"), std::string("orange")) << std::endl;

  return 0;
}
