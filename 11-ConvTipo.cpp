#include <iostream>

// Conversão implicita

int main(){
double valor = 3.14;
int numero = 'a'; // observe que será convertido a para seu número interiro correspondente em ascii

std::cout << "\n Conversão Implicita \n";
std::cout << "valor: " << valor << " número: " << numero << '\n';
std::cout << "valor + número: " << valor + numero << " porque foi convertido, nesse caso implicitamente \n";

std::cout << "\n Conversão Explicita \n";
int i, j;
double d = 9.87;

i = int(d); // notação funcional
j = (int)d; // notação cast
std::cout << "Para i e j foram atribuidos o valor origianl de d, ou seja: " << d << '\n';
std::cout << "o valor de i é: " << i << " e o valor de j também é: " << j << " porque ambos foram convertido para o tipo int explictamente, mas de forma de ferente. \n";
std::cout << "o objetivo é obeservar a diferença entre esses dois tipos de conversão que pode ser encontrada no código do programa \n";

// Conversão com operadores de tipos
// Operadores
// static_cast -> converter tipos númericos
// dynamic_cast -> " " tipos ponteiros de classes
// cost_cast -> " " contates <-> variáveis
// sintaxe nome_cast<novo tipo>(variavel)

std::cout << "\n Conversão Com Operadores Cast \n";
double e = 3.14;
int k = static_cast<int>(e);
std::cout << "formato doble: " << e << " foi convertido para int com static_cast resultando em " << k << '\n';

return 0;
}
