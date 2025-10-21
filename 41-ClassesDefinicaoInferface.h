// Esse arquivo apresenta a a definição da interface pública de
// da classe sem revelar as implementações de funções-membro dela.

#include <string>
using std::string;

// Definição da classe
class minhaClasse {
public:
  minhaClasse();
  void setterClasse(int param1, string param2);
  int getAtr1();
  string getAtr2();
  bool getAtr3();

private:
  int atr1;
  string atr2;
  bool atr3;
};
