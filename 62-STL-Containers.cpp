#include <algorithm> // Para std::for_each ou outros algoritmos genéricos
#include <iostream>
#include <list>   // Para std::list
#include <map>    // Para std::map
#include <string> // Para std::string
#include <vector> // Para std::vector

/*
  EXPLICAÇÃO: VISÃO GERAL DOS CONTÊINERES DA STL

  A Standard Template Library (STL) do C++ oferece uma rica coleção de
  contêineres, cada um otimizado para diferentes cenários de uso.
  Entender suas características é crucial para escolher a ferramenta certa.

  ### 1. Contêineres de Sequência
  Os elementos são mantidos na ordem em que você os insere.

  *   `std::vector`: **(O padrão para a maioria dos casos)** Um array dinâmico.
      *   **Pró:** Acesso muito rápido a qualquer elemento pelo índice (ex:
  `vec[5]`). Adicionar/remover no **final** é rápido (tempo constante
  amortizado).
      *   **Contra:** Adicionar/remover no **início ou meio** é lento (tempo
  linear), pois exige deslocar todos os outros elementos.

  *   `std::list`: Uma lista duplamente encadeada.
      *   **Pró:** Adicionar/remover elementos em **qualquer posição** é muito
  rápido (tempo constante), desde que você tenha um iterador para o local.
      *   **Contra:** Não permite acesso direto por índice (`lista[5]` não
  funciona). Para encontrar um elemento, você precisa percorrer a lista (tempo
  linear).

  *   `std::deque` (pronuncia-se "deck"): Uma fila de duas pontas.
      *   **Pró:** Um meio-termo. Permite adicionar/remover rapidamente tanto no
                 **início quanto no final** (tempo constante).
      *   **Contra:** Um pouco mais complexo e pode ser ligeiramente mais lento
                   que o `vector` para acesso por índice.

  ### 2. Contêineres Associativos (Ordenados)
  Os elementos são ordenados automaticamente com base em seus valores (ou
  chaves). São ótimos para buscas rápidas.

  *   `std::map`: Um dicionário de pares **chave-valor**.
      *   **Uso:** Perfeito para tabelas de consulta. As chaves são únicas e os
                 elementos são mantidos **ordenados pela chave**.
      *   **Performance:** Busca, inserção e remoção são rápidas (tempo
  logarítmico, O(log n)).

  *   `std::set`: Uma coleção de elementos **únicos e ordenados**.
      *   **Uso:** Ótimo para verificar rapidamente se um item existe em uma
  coleção ou para manter uma lista de itens únicos sempre ordenada.

  ### 3. Contêineres Associativos (Não Ordenados)
  (`std::unordered_map`, `std::unordered_set`)
  Faz o mesmo que `map` e `set`, mas usam *hash tables* internamente.
  *   **Pró:** São em média **muito mais rápidos** para busca, inserção e
  remoção (tempo constante médio, O(1)).
  *   **Contra:** **Não mantêm os elementos ordenados**. A ordem dos elementos
               pode variar. São preferidos quando a ordem não é importante.
*/

int main() {
  std::cout << "--- Demonstração de std::vector ---" << std::endl;
  std::vector<int> numeros_vector;
  numeros_vector.push_back(10);
  numeros_vector.push_back(20);
  numeros_vector.push_back(30);
  std::cout << "Vector: ";
  for (int n : numeros_vector) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  std::cout << "Acessando por índice: " << numeros_vector[1]
            << std::endl; // Acesso rápido

  std::cout << "\n--- Demonstração de std::list ---" << std::endl;
  std::list<std::string> nomes_list;
  nomes_list.push_back("Alice");
  nomes_list.push_front("Bob"); // Inserção no início é rápida
  nomes_list.push_back("Charlie");
  std::cout << "List: ";
  // Listas não têm acesso por índice, precisam de iteradores para percorrer.
  for (const std::string &nome : nomes_list) {
    std::cout << nome << " ";
  }
  std::cout << std::endl;

  std::cout << "\n--- Demonstração de std::map ---" << std::endl;
  std::map<std::string, int> idades_map;
  idades_map["Alice"] = 30; // Inserção de chave-valor
  idades_map["Bob"] = 25;
  idades_map["Charlie"] = 35;
  std::cout << "Map (ordenado por chave):\n";
  // Map itera sobre pares (chave, valor)
  for (const auto &par : idades_map) {
    std::cout << par.first << ": " << par.second << std::endl;
  }
  std::cout << "Idade de Bob: " << idades_map["Bob"]
            << std::endl; // Acesso por chave

  return 0;
}
