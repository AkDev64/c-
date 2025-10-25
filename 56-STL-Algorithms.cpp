// esse arquivo foi criado pelo gemini para explicar os algoritmos da STL em
// C++, especialmente no contexto de contêineres e iteradores.
#include <algorithm> // Header essencial para os algoritmos da STL!
#include <iostream>
#include <string>
#include <vector>

/*
  EXPLICAÇÃO: A "Santíssima Trindade" da STL

  1. Contêineres (ex: std::vector): Armazenam os dados.
  2. Iteradores (ex: vector::begin()): Fornecem o acesso aos dados.
  3. Algoritmos (ex: std::sort): Operam nos dados através dos iteradores.

  A genialidade está em como os algoritmos são genéricos. Eles não sabem
  o que é um 'vector'. Eles apenas sabem como operar em uma sequência
  definida por um par de iteradores (um início e um fim). Isso significa
  que podemos usar os mesmos algoritmos em diferentes tipos de contêineres.
*/

// Função auxiliar para imprimir o vetor, para não repetir código.
void imprimirVector(const std::string &titulo, const std::vector<int> &vec) {
  std::cout << titulo;
  for (int valor : vec) {
    std::cout << valor << " ";
  }
  std::cout << std::endl;
}

int main() {
  // 1. Nosso contêiner com alguns dados de exemplo.
  std::vector<int> numeros = {40, 10, 50, 20, 50, 30};
  imprimirVector("Vetor original: ", numeros);

  // --- 2. Usando o algoritmo std::sort ---
  // O algoritmo 'sort' recebe dois iteradores:
  // - O início da sequência a ser ordenada (numeros.begin())
  // - O fim da sequência a ser ordenada (numeros.end())
  std::sort(numeros.begin(), numeros.end());
  imprimirVector("Vetor ordenado: ", numeros);

  // --- 3. Usando o algoritmo std::find ---
  std::cout << "\n--- Buscando elementos ---" << std::endl;
  int valor_a_buscar = 20;
  // 'find' também recebe um início, um fim, e o valor a ser buscado.
  // Ele retorna um iterador para o primeiro elemento encontrado.
  // Se não encontrar, retorna o iterador 'end()'.
  auto it_encontrado =
      std::find(numeros.begin(), numeros.end(), valor_a_buscar);

  if (it_encontrado != numeros.end()) {
    std::cout << "Valor " << valor_a_buscar << " encontrado no vetor!"
              << std::endl;
  } else {
    std::cout << "Valor " << valor_a_buscar << " NÃO encontrado." << std::endl;
  }

  // --- 4. Usando o algoritmo std::count ---
  std::cout << "\n--- Contando ocorrências ---" << std::endl;
  int valor_a_contar = 50;
  // 'count' recebe um início, um fim, e o valor a ser contado.
  // Ele retorna o número de vezes que o valor aparece na sequência.
  int ocorrencias = std::count(numeros.begin(), numeros.end(), valor_a_contar);
  std::cout << "O valor " << valor_a_contar << " aparece " << ocorrencias
            << " vezes." << std::endl;

  return 0;
}
