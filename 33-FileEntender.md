// Esse arquivo foi feito com base em um exemplo do site geekforgeeks mas eu não consegui entender bem o seu comportamento de primeira. Voltar depois nesse porgrama após ter entendido melhor os conceitos de escrita em arquivos binários

# include <cstddef>
# include <cstring>
# include <fstream>
# include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string str = "Um arquivo binario é diferente de um arquivo texto";

  // Abrindo um arquivo para editar
  ofstream arquivo("33-Meuarquivo.bin", ios::binary);

  // Checando se o arquivo está aberto
  if (!arquivo) {
    cerr << "Não foi possível abrir o arquivo";
    return 1;
  }

  // Escrevendo o tamanho do arquivo
  size_t strTamanho = str.length();
  arquivo.write(reinterpret_cast<const char *>(&strTamanho),
                sizeof(strTamanho));

  // Escrevendo a string no arquivo binario
  arquivo.write(str.c_str(), strTamanho);

  // Fechando o arquivo
  arquivo.close();

  return 0;
}
