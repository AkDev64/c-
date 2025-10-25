#include <iostream>
#include <vector>
#include <algorithm> // Para std::transform, std::remove_if, std::for_each
#include <numeric>   // Para std::iota (preencher vetor facilmente)
#include <string>

/*
  EXPLICAÇÃO: ALGORITMOS DA STL E FUNÇÕES LAMBDA

  ### 1. Algoritmos Mais Avançados
  A STL oferece uma vasta gama de algoritmos genéricos que operam em intervalos
  definidos por iteradores.

  *   `std::transform`: Aplica uma função (ou lambda) a cada elemento de um
                       intervalo e armazena o resultado em outro intervalo
                       (que pode ser o mesmo).
      Sintaxe: `std::transform(inicio_origem, fim_origem, inicio_destino, operacao);`

  *   `std::remove_if`: Remove elementos de um intervalo que satisfazem uma
                       determinada condição (definida por uma função ou lambda).
      IMPORTANTE: `remove_if` não redimensiona o contêiner. Ele move os elementos
      que NÃO devem ser removidos para o início do intervalo e retorna um iterador
      para o "novo final lógico". Você precisa usar o método `erase` do contêiner
      para realmente remover os elementos e redimensioná-lo.
      Sintaxe: `auto novo_fim = std::remove_if(inicio, fim, condicao);`
               `container.erase(novo_fim, fim);`

  ### 2. Funções Lambda (O Poder da Personalização)
  Lambdas são funções anônimas (sem nome) que podem ser definidas e usadas
  diretamente no local. Elas são perfeitas para passar pequenas operações
  personalizadas para algoritmos da STL.

  *   **Sintaxe Básica:** `[capturas](parâmetros) -> tipo_retorno { corpo_da_função }`
      - `[capturas]`: Permite que a lambda "capture" variáveis do escopo onde ela
                      foi definida.
          - `[]`: Não captura nada.
          - `[=]`: Captura todas as variáveis acessíveis por valor.
          - `[&]`: Captura todas as variáveis acessíveis por referência.
          - `[var]`: Captura a variável `var` por valor.
          - `[&var]`: Captura a variável `var` por referência.
      - `(parâmetros)`: Os parâmetros que a lambda recebe.
      - `-> tipo_retorno`: O tipo de retorno da lambda (opcional se o compilador
                           puder deduzir).
      - `{ corpo_da_função }`: O código que a lambda executa.
*/

// Função auxiliar para imprimir o vetor
void imprimirVector(const std::string& titulo, const std::vector<int>& vec) {
    std::cout << titulo;
    for (int valor : vec) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numeros(10);
    // Preenche o vetor com 0, 1, 2, ..., 9
    std::iota(numeros.begin(), numeros.end(), 0);
    imprimirVector("Vetor original: ", numeros);

    // --- Demonstração de std::transform com Lambdas ---
    std::cout << "\n--- std::transform ---" << std::endl;

    // Exemplo 1: Dobrar cada elemento
    std::vector<int> dobrados(numeros.size()); // Vetor para armazenar o resultado
    std::transform(numeros.begin(), numeros.end(), dobrados.begin(),
                   [](int n) { return n * 2; }); // Lambda simples para dobrar
    imprimirVector("Vetor dobrado: ", dobrados);

    // Exemplo 2: Elevar ao quadrado (no mesmo vetor)
    std::transform(numeros.begin(), numeros.end(), numeros.begin(),
                   [](int n) { return n * n; }); // Lambda para elevar ao quadrado
    imprimirVector("Vetor ao quadrado: ", numeros);

    // --- Demonstração de std::remove_if com Lambdas e Capturas ---
    std::cout << "\n--- std::remove_if ---" << std::endl;

    std::vector<int> dados = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    imprimirVector("Dados originais: ", dados);

    // Exemplo 1: Remover números ímpares
    // A lambda retorna 'true' para números ímpares, que serão "removidos"
    auto novo_fim_impar = std::remove_if(dados.begin(), dados.end(),
                                         [](int n) { return n % 2 != 0; });
    dados.erase(novo_fim_impar, dados.end()); // Redimensiona o vetor
    imprimirVector("Dados (após remover ímpares): ", dados);

    // Exemplo 2: Remover números maiores que um limite (com captura)
    int limite = 5;
    std::vector<int> mais_dados = {1, 7, 3, 9, 5, 2, 8, 4, 6, 10};
    imprimirVector("Mais dados originais: ", mais_dados);

    // Captura 'limite' por valor ([=limite] ou [limite])
    auto novo_fim_limite = std::remove_if(mais_dados.begin(), mais_dados.end(),
                                          [limite](int n) { return n > limite; });
    mais_dados.erase(novo_fim_limite, mais_dados.end());
    imprimirVector("Mais dados (após remover > 5): ", mais_dados);

    // Exemplo 3: Captura por referência (para modificar uma variável externa)
    int contador_removidos = 0;
    std::vector<int> numeros_para_contar = {1, 2, 3, 4, 5, 6};
    imprimirVector("Números para contar: ", numeros_para_contar);

    auto novo_fim_contar = std::remove_if(numeros_para_contar.begin(), numeros_para_contar.end(),
                                          [&contador_removidos](int n) {
                                              if (n % 2 == 0) { // Se for par, "remove" e conta
                                                  contador_removidos++;
                                                  return true;
                                              }
                                              return false;
                                          });
    numeros_para_contar.erase(novo_fim_contar, numeros_para_contar.end());
    imprimirVector("Números (após remover pares): ", numeros_para_contar);
    std::cout << "Total de pares removidos: " << contador_removidos << std::endl;


    return 0;
}
