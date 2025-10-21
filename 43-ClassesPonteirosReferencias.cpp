// Demonstrando os operadores de acesso ao membro de classe com . e ->
// e o uso de ponteiros e referências para objetos da classe
#include <iostream>
using std::cout;
using std::endl;

// definição da classe Count
class Count {
public: // dados public são perigosos
  // configura o valor do membro de dados private x
  void setX(int value) { x = value; } // fim da função setX

  // imprime o valor do membro de dados private x
  void print() { cout << x << endl; } // fim da função print

private:
  int x;
}; // fim da classe Count

int main() {
  Count counter;                // cria objeto counter
  Count *counterPtr = &counter; // cria ponteiro para counter
  Count &counterRef = counter;  // criar referência para counter

  cout << "Set x to 1 and print using the object’s name: ";
  counter.setX(1); // configura membro de dados x como 1
  counter.print(); // chama função-membro print

  cout << "Set x to 2 and print using a reference to an object: ";
  counterRef.setX(2); // configura membro de dados x como 2
  counterRef.print(); // chama função-membro print
  std::cout << "checagem do objeto counter: ";
  counter.print();
  cout << "Set x to 3 and print using a pointer to an object: ";
  counterPtr->setX(3); // configura membro de dados x como 3
  counterPtr->print(); // chama função-membro print
  std::cout << "checagem do objeto counter: ";
  counter.print();
  return 0;
} // fim de main
