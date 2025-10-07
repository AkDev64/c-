/*
 * Erro de EOF
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("33-meuArquivo.txt");

  if (!file.is_open()) {
    cerr << "Erro: Não foi possível abrir o arquivo!" << endl;
    return 1;
  }
  string line;
  while (getline(file, line))
    cout << line << endl;

  // Checando se o arquivo chegou ao fim eof()
  if (file.eof())
    cout << "Atingiu o fim do arquivo." << endl;
  else
    cerr << "Erro: Não foi possível ler o arquivo!" << endl;

  file.close();
  return 0;
}
