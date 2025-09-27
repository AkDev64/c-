/*
 * Básico sobre ponteiros
 */

#include<iostream>

int main () {
  int variavel = {1000};
  int* ponteiro = &variavel; // variável do tipo ponteiro para inteiro (*int) aponta para o endereço da variável (&variavel)
                              // ou seja a variavel ponteiro tem o valor do endereço, não a aquilo que está guardado nele

  std::cout << "valor da variável: " << variavel << '\n';
  std::cout << "valor do ponteiro: " << ponteiro << '\n';
  std::cout << "valor apontado pelo ponteiro: " << *ponteiro << '\n';

  return 0;


}
