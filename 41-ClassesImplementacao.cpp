// ALTERADO: O conteúdo deste arquivo foi reescrito.
// O propósito de um arquivo de implementação (.cpp) é definir as funções
// que foram declaradas em um arquivo de cabeçalho (.h), e não recriar a classe.

// ALTERADO: Incluindo o cabeçalho correto que contém a DEFINIÇÃO da classe.
#include "41-ClassesDefinicaoInferface.h"
#include <string>

// Usar "using std::string" é uma boa prática para evitar poluir o escopo
// global, mas como o cabeçalho já tem, não seria estritamente necessário aqui.
using std::string;

// ALTERADO: Implementação do construtor usando o operador de escopo
// "minhaClasse::" e a lista de inicialização, que é a forma mais correta e
// eficiente em C++.
minhaClasse::minhaClasse() : atr1(0), atr2(""), atr3(false) {
  // O corpo do construtor agora pode ficar vazio.
}

// ALTERADO: Implementação do setter usando o operador de escopo.
void minhaClasse::setterClasse(int param1, string param2) {
  atr1 = param1;
  atr2 = param2;
  atr3 = true;
}

// ALTERADO: Implementação dos getters usando o operador de escopo.
int minhaClasse::getAtr1() { return atr1; }

string minhaClasse::getAtr2() { return atr2; }

bool minhaClasse::getAtr3() { return atr3; }
