/*
 * Manipulando arquivos em C++
 * File Handling in C++
 * In C++, input and output are done in the form of a sequence of bytes called
 * streams. For example, cin and cout are the objects associated with the
 * standard input and output streams. These streams are represented by different
 * classes provided in the <iostream> library. Similarly, C++ also provides file
 * stream classes to perform input and output operations on files that are
 * defined inside <fstream> header file.
 */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  // 1) Abrindo arquivos, ou seja, carregando esse arquivo na memória
  // fstream str("nomeDoArquivo.ext, mode"); // str é um nome escolhido para
  // esse stream específico, ext também a critério do programador, mode:
  // conforme taabela abaixo

  /*
   * Mode	Description
  ios::in	File open for reading. If file does not exists,
  ios::out	File open for writing: the internal stream buffer supports
  output operations. ios::binary	Operations are performed in binary mode
  rather than text. ios::ate	The output position starts at the end of the
  file. ios::app	All output operations happen at the end of the file,
  appending to its existing contents. ios::trunc	Any contents that
  existed in the file before it is open are discarded.
  */

  // 1) abrindo um arquivo para leitura e escrita usando o operador ou |
  // fstream meustream("meuArquivo.myext", ios::in | ios::out); // If the file
  // opened in write mode does not exists, a new file is created. But if the
  // file opened in read mode doesn't exists, then no new file is created, and
  // an exception is thrown. alternativamente pode se usar ifstream e ofstream
  // equivalendo ios::in e ios::out respectivamente, com a seguinte sintaxe,
  // ifstream("nomeArquivo.ext") e ofstream("nomeArquivo.ext")

  // 2) Lendo e escrevendo nos arquivos

  // Abrindo e Escrendo no arquivo
  ofstream arquivo("meuArquivo.txt");
  arquivo << "Hello Pessoal da Terra" << endl;
  arquivo << "Hello World" << endl;
  cout << "abrindo o arquivo" << endl;

  // fechando o arquivo do modo leitura
  arquivo.close();

  // Lendo dados do arquivo
  ifstream arquivo2("meuArquivo.txt");
  string s; // trazendo uma string para a string
  arquivo2 >> s;
  cout << "Imprimindo a primeira string carregada na memória para a tela: " << s
       << endl;

  getline(arquivo2, s);
  cout << "Imprimindo o restante da 1a linha: " << s << endl;

  getline(arquivo2, s);
  cout << "Imprimindo uma linha inteira: " << s << endl;

  // 3) Fechando os arquivos

  arquivo.close();

  return 0;
}
