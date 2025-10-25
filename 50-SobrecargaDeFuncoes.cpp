// Arquvio gerado pelo Gemini para explicar sobrecarga de funções em C++
#include <iostream>
#include <string>

// Explicação:
// Sobrecarga de Funções (Function Overloading) é um recurso do C++ que permite
// criar várias funções com o mesmo nome, desde que suas assinaturas de
// parâmetros sejam diferentes. A "assinatura" de uma função inclui o número,
// o tipo e a ordem dos seus parâmetros. O tipo de retorno não faz parte da
// assinatura para fins de sobrecarga.

// O compilador decide qual versão da função chamar com base nos argumentos
// que você passa durante a chamada da função.

// Versão 1: Aceita um inteiro (int)
void imprimir(int numero) {
  std::cout << "Imprimindo um inteiro: " << numero << std::endl;
}

// Versão 2: Aceita um número de ponto flutuante (double)
void imprimir(double numero) {
  std::cout << "Imprimindo um double: " << numero << std::endl;
}

// Versão 3: Aceita uma string
void imprimir(const std::string &texto) {
  std::cout << "Imprimindo uma string: \"" << texto << "\"" << std::endl;
}

// Exemplo de uma função que NÃO seria uma sobrecarga válida, pois apenas
// o tipo de retorno é diferente. Isso causaria um erro de compilação.
// int imprimir(int numero) {
//     std::cout << "Esta função não é uma sobrecarga válida." << std::endl;
//     return numero;
// }

int main() {
  std::cout << "--- Chamando as funções sobrecarregadas ---" << std::endl;

  imprimir(10);            // Chama a versão com int
  imprimir(3.14159);       // Chama a versão com double
  imprimir("Olá, Mundo!"); // Chama a versão com string

  return 0;
}
