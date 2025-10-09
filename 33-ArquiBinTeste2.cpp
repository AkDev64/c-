#include <fstream>
#include <iostream>

int main() {
  // Escrevendo dados em um arquivo binário
  std::ofstream out("dados.bin", std::ios_base::binary);
  if (out.is_open()) {
    int numero = 100;
    double pi = 3.14159;
    out.write(reinterpret_cast<const char *>(&numero), sizeof(numero));
    out.write(reinterpret_cast<const char *>(&pi), sizeof(pi));
    out.close();
    std::cout << "Dados escritos com sucesso!" << std::endl;
  } else {
    std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
  }

  // Lendo dados de um arquivo binário
  std::ifstream in("dados.bin", std::ios_base::binary);
  if (in.is_open()) {
    int numeroLido;
    double piLido;
    in.read(reinterpret_cast<char *>(&numeroLido), sizeof(numeroLido));
    in.read(reinterpret_cast<char *>(&piLido), sizeof(piLido));
    in.close();
    std::cout << "Numero lido: " << numeroLido << std::endl;
    std::cout << "Pi lido: " << piLido << std::endl;
  } else {
    std::cerr << "Erro ao abrir o arquivo para leitura." << std::endl;
  }

  return 0;
}
