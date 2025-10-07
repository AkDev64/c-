#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
 * @brief Converte uma string em um vetor de palavras.
 * 
 * Esta função recebe uma string como entrada e a divide em palavras,
 * usando o espaço como delimitador. Cada palavra é então adicionada a um
 * std::vector<std::string>.
 * 
 * @param str A string de entrada a ser processada.
 * @return std::vector<std::string> Um vetor onde cada elemento é uma palavra da string original.
 */
std::vector<std::string> stringToArray(const std::string& str) {
    // Cria um stringstream a partir da string de entrada.
    // Isso nos permite tratar a string como um fluxo (stream) de dados.
    std::stringstream ss(str);
    
    std::string palavra;
    std::vector<std::string> resultado;
    
    // Extrai cada palavra do stringstream. O operador '>>' automaticamente
    // lê até encontrar um espaço em branco (espaço, tab, nova linha, etc.).
    while (ss >> palavra) {
        // Adiciona a palavra extraída ao final do vetor.
        resultado.push_back(palavra);
    }
    
    return resultado;
}

int main() {
    // Define a string de exemplo.
    std::string minhaString = "Esta é uma string de exemplo para conversão";
    
    // Chama a função para converter a string em um vetor de palavras.
    std::vector<std::string> arrayDePalavras = stringToArray(minhaString);
    
    // Imprime a string original.
    std::cout << "String Original: \"" << minhaString << "\"" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    // Itera sobre o vetor e imprime cada palavra com seu respectivo índice.
    std::cout << "Array de Palavras resultante:" << std::endl;
    for (size_t i = 0; i < arrayDePalavras.size(); ++i) {
        std::cout << "  [" << i << "]: \"" << arrayDePalavras[i] << "\"" << std::endl;
    }
    
    return 0;
}
