/*
 * Errors in File Handling Many different types of errors can occur in file
 * handling such as file not found, disk full, etc. Our programs should expect
 * common errors and should be able to handle them properly. Following are some
 * common errors that can occur during file handling:
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  fstream file("arquivoInexistente.txt", ios::in);

  // Falha na abertura do arquivo

  // Check if the file is opened
  if (!file.is_open()) {
    cerr << "Erro: Não consigo ler o arquivo!" << endl;
  }

  file.close();

  // Falha de leitura e escrita
  // Another common error is failure to read or write data for reasons such as
  // incorrect mode, etc. In this case, we can validate operations after each
  // read/write attempt. For example, reading using getline() can be validated
  // as shows:

  fstream file2(
      "33-arquivoTeste.txt", // apague esse arquivo do diretório para testes
      ios::out);             // se estiver no modo ios::in e o arquivo for
                             // inexistente, aparecerá dois erros, de abertura e
                 // leitura por oturo lado, se estiver no modo ios::out
                 // aparecerái apenas o erro de erro de leitura

  if (!file2.is_open()) {
    cerr << "Erro: Não foi possível abrir o arquivo!" << endl;
  }
  string line;

  // Checking if getline() read successfully or not
  if (!getline(file2, line))
    cerr << "Erro: Não foi possível ler o arquivo!" << endl;

  file2.close();

  return 0;
}
