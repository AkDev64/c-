// Esse arquivo apresenta a interface pública de
// da classe sem revelar as implementações de funções-membro dela.

#include <string>
using std::string;

// Definição da classe
class minhaClasse {
public:
  minhaClasse() { // construtor
    atr1 = 0;     // eu havia digitado int atr1 = 0; o que era um erro, pois
              // inicializava uma variável, ao invés de inicializar o atributo
              // da classe.
    atr2 = "";    // idem
    atr3 = false; // idem
  }

  void setterClasse(int param1, string param2) {
    atr1 = param1;
    atr2 = param2;
    atr3 = true;
  }

  int getAtr1() { return atr1; }

  string getAtr2() { return atr2; }

  bool getAtr3() { return atr3; }

private:
  int atr1;
  string atr2;
  bool atr3;
};
