#include <iostream>
#include <string>

/*
  EXPLICAÇÃO: TEMPLATES DE CLASSE

  Assim como templates de função criam funções genéricas, templates de classe
  criam classes genéricas.

  Usamos `template <typename T>` antes da classe para torná-la um molde.
  A classe pode então usar 'T' como um tipo para seus membros, parâmetros
  de método ou tipos de retorno.

  Para usar a classe, você deve fornecer o tipo real que 'T' representará,
  usando a sintaxe de colchetes angulares: NomeDaClasse<TipoReal>.

  Isto é a base para todos os contêineres da STL, como `std::vector<int>`
  ou `std::map<std::string, int>`.
*/

// --- Template de Classe: Caixa ---
// Uma classe genérica que pode "guardar" um valor de qualquer tipo.
template <typename T>
class Caixa {
private:
    // O tipo do nosso membro de dado é 'T', o tipo genérico.
    T valor;

public:
    // O construtor recebe um valor do tipo 'T'.
    Caixa(T v) : valor(v) {}

    // O método retorna um valor do tipo 'T'.
    T getValor() const {
        return valor;
    }
};

int main() {
    std::cout << "--- Testando o template de classe Caixa<T> ---" << std::endl;

    // --- Instância 1: Caixa<int> ---
    // O compilador gera uma classe 'Caixa' onde todo 'T' é substituído por 'int'.
    Caixa<int> caixaDeInt(123);
    std::cout << "Valor na caixa de int: " << caixaDeInt.getValor() << std::endl;

    // --- Instância 2: Caixa<double> ---
    // O compilador gera outra classe 'Caixa' onde todo 'T' é substituído por 'double'.
    Caixa<double> caixaDeDouble(98.6);
    std::cout << "Valor na caixa de double: " << caixaDeDouble.getValor() << std::endl;

    // --- Instância 3: Caixa<std::string> ---
    // E mais uma, agora para std::string.
    Caixa<std::string> caixaDeString("C++ Moderno");
    std::cout << "Valor na caixa de string: \"" << caixaDeString.getValor() << "\"" << std::endl;

    // A linha abaixo não compilaria, pois os tipos são diferentes.
    // Caixa<int> outraCaixa = caixaDeString; // ERRO!

    return 0;
}
