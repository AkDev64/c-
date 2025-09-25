#include<iostream> // presente em todo programa c++ para permitir entradas e saídas
//#include "24-cabecalho.h" // inclusão de arquivo do tipo .h cabecalho, veja que a sintaxe <> é diferente de "", <> para bibliotecas padrões e "" para biblioteca pessoais
// se comentarmos a linha de cima o programa não compilarar, pois a definição do namespace será feita no aqruivo 24-cabecalho.h

int main (int argc, char *argv[]) {
  cout << "Essa impressão na tela depende da diretiva include do arquivo 24-cabecalho.h";
return 0;
}

