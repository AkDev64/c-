#include <iostream>
#include <string>
// a palavra-chave final proíbe que outras classes
// herdem da classe Player.
class Player final {
public:
  Player(unsigned int iHealth, const std::string &iName,
         const std::string &iClass)
      : health(iHealth), name(iName), playerClass(iClass) {}

  // Métodos declarados e definidos no corpo da classe
  unsigned int getHealth() const { return health; }
  const std::string &getClass() const { return playerClass; }
  const std::string &getName() const { return name; }
  // Método definido fora da classe
  void greeting() const;

private:
  unsigned int health{1};
  std::string name;
  std::string playerClass;
};
void Player::greeting() const { std::cout << "Oi, pessoal!" << std::endl; }
int main() {
  Player merlin{10, "Merlin", "mago"};
  std::cout << "O nome do personagem é: " << merlin.getName()
            << ". A sua classe é " << merlin.getClass() << ", e ele possui "
            << merlin.getHealth() << " pontos de vida." << std::endl;
  // A linha a seguir está em erro, pois "name" é um atributo privado de Player
  //  std::cout << "O nome do personagem é: " << merlin.name << std::endl;
}
