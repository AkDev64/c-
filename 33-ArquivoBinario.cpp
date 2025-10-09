#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Função para escrever a string em um arquivo binário
void escreverBinario(const std::string& nomeArquivo, const std::string& texto) {
    // Abre o arquivo em modo de escrita binária
    std::ofstream arquivoSaida(nomeArquivo, std::ios::binary);

    if (!arquivoSaida) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << " para escrita." << std::endl;
        return;
    }

    // 1. Escreve o tamanho da string primeiro, para saber quanto ler depois
    size_t tamanho = texto.length();
    arquivoSaida.write(reinterpret_cast<const char*>(&tamanho), sizeof(tamanho));

    // 2. Escreve os dados da string (o texto em si)
    arquivoSaida.write(texto.c_str(), tamanho);

    arquivoSaida.close();
    std::cout << "Texto escrito com sucesso no arquivo binário: " << nomeArquivo << std::endl;
}

// Função para ler a string de um arquivo binário
std::string lerBinario(const std::string& nomeArquivo) {
    // Abre o arquivo em modo de leitura binária
    std::ifstream arquivoEntrada(nomeArquivo, std::ios::binary);

    if (!arquivoEntrada) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << " para leitura." << std::endl;
        return "";
    }

    // 1. Lê o tamanho da string que foi salvo no início do arquivo
    size_t tamanho = 0;
    arquivoEntrada.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));

    // Se o tamanho for 0 ou muito grande, pode haver um erro
    if (tamanho == 0) {
        std::cout << "Arquivo vazio ou formato inválido." << std::endl;
        return "";
    }
    
    // 2. Cria um buffer (vetor de char) para ler os dados do arquivo
    std::vector<char> buffer(tamanho);
    arquivoEntrada.read(buffer.data(), tamanho);

    arquivoEntrada.close();

    // Converte o buffer de volta para uma string
    return std::string(buffer.begin(), buffer.end());
}

int main() {
    const std::string nomeArquivo = "meu_arquivo.bin";
    const std::string textoOriginal = "Eu queria muito que meu arquivo binario fosse tão pequeno que valesse a pena todo esse trabalho de arquivo binário.";

    // Escreve o texto no arquivo binário
    escreverBinario(nomeArquivo, textoOriginal);

    std::cout << "----------------------------------------" << std::endl;

    // Lê o texto de volta do arquivo binário
    std::string textoLido = lerBinario(nomeArquivo);

    // Imprime o texto lido para verificar
    if (!textoLido.empty()) {
        std::cout << "Texto lido do arquivo binário:" << std::endl;
        std::cout << textoLido << std::endl;
    }

    return 0;
}
