#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Função para escrever a string em um arquivo de texto
void escreverTexto(const std::string &nomeArquivo, const std::string &texto) {
  // Abre o arquivo em modo de escrita (padrão para texto)
  std::ofstream arquivoSaida(nomeArquivo);

  if (!arquivoSaida) {
    std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << " para escrita."
              << std::endl;
    return;
  }

  // Escreve a string diretamente no arquivo, com uma quebra de linha no final
  arquivoSaida << texto << std::endl;

  arquivoSaida.close();
  std::cout << "Texto escrito com sucesso no arquivo de texto: " << nomeArquivo
            << std::endl;
}

// Função para ler a string de um arquivo de texto
std::string lerTexto(const std::string &nomeArquivo) {
  // Abre o arquivo em modo de leitura (padrão para texto)
  std::ifstream arquivoEntrada(nomeArquivo);

  if (!arquivoEntrada) {
    std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << " para leitura."
              << std::endl;
    return "";
  }

  std::string linha;
  // Lê a primeira linha do arquivo
  std::getline(arquivoEntrada, linha);

  arquivoEntrada.close();

  return linha;
}

int main() {
  const std::string nomeArquivo = "meu_arquivo.txt";
  const std::string textoOriginal =
      "Eu queria muito que meu arquivo binario fosse tão pequeno que valesse a "
      "pena todo esse trabalho de arquivo binário.";

  // Escreve o texto no arquivo de texto
  escreverTexto(nomeArquivo, textoOriginal);

  std::cout << "----------------------------------------" << std::endl;

  // Lê o texto de volta do arquivo de texto
  std::string textoLido = lerTexto(nomeArquivo);

  // Imprime o texto lido para verificar
  if (!textoLido.empty()) {
    std::cout << "Texto lido do arquivo de texto:" << std::endl;
    std::cout << textoLido << std::endl;
  }

  return 0;
}
