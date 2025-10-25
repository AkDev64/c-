#include <iostream>
#include <string>
#include <vector> // Precisamos incluir o header para std::vector

/*
  EXPLICAÇÃO: CLASSES CONTÊINER E ITERADORAS

  Este é um dos conceitos mais importantes da Standard Template Library (STL) do
  C++.

  1. Classe Contêiner:
     - É uma classe cujo propósito é "conter" uma coleção de outros objetos.
     - O `std::vector` é um dos contêineres mais comuns. Ele funciona como um
       array que pode crescer e diminuir de tamanho dinamicamente.
     - Outros exemplos de contêineres são `std::list`, `std::map`, `std::set`,
  etc.

  2. Classe Iteradora (Iterator):
     - É um objeto que "aponta" para um elemento específico dentro de um
  contêiner. Pense nele como um marcador de página ou um dedo apontando para um
  item em uma lista.
     - Iteradores nos dão uma maneira padronizada e poderosa de percorrer
       (ou "iterar sobre") os elementos de QUALQUER tipo de contêiner.
     - As operações mais comuns com um iterador (vamos chamá-lo de 'it') são:
       - `*it`: Acessa o valor do elemento para o qual o iterador aponta.
       - `++it`: Move o iterador para que ele aponte para o próximo elemento.
       - `it != container.end()`: Compara o iterador com um iterador especial
         que aponta para "depois do último elemento", para saber quando parar o
  loop.
       - `container.begin()`: É uma função do contêiner que nos dá um iterador
         apontando para o PRIMEIRO elemento.
*/

int main() {
  // --- 1. CRIANDO E POPULANDO UM CONTÊINER ---
  // Vamos criar um contêiner do tipo 'vector' que guardará objetos 'string'.
  std::vector<std::string> nomes;

  // Usamos o método 'push_back' para adicionar elementos ao final do vector.
  nomes.push_back("Link");
  nomes.push_back("Zelda");
  nomes.push_back("Ganon");
  nomes.push_back("Navi");

  // --- 2. USANDO ITERADORES PARA PERCORRER O CONTÊINER (O JEITO CLÁSSICO) ---
  std::cout << "--- Percorrendo com iterador clássico ---" << std::endl;

  // 'std::vector<std::string>::iterator' é o tipo de dado do iterador.
  // 'nomes.begin()' nos dá um iterador para o começo do vetor.
  // 'nomes.end()' nos dá um iterador para a posição APÓS o último elemento.
  // O loop continua enquanto nosso iterador 'it' não chegar ao final.
  for (std::vector<std::string>::iterator it = nomes.begin(); it != nomes.end();
       ++it) {
    // '*it' acessa o valor (a string) para o qual o iterador aponta.
    std::cout << *it << std::endl;
  }

  // --- 3. USANDO O RANGE-BASED FOR LOOP (O JEITO MODERNO) ---
  std::cout << "\n--- Percorrendo com range-based for (mais fácil!) ---"
            << std::endl;

  // Este tipo de loop, introduzido no C++11, é muito mais simples e menos
  // propenso a erros. Ele usa iteradores por baixo dos panos!
  // "Para cada 'nome' dentro da coleção 'nomes'..."
  for (const std::string &nome : nomes) {
    std::cout << nome << std::endl;
  }

  return 0;
}
