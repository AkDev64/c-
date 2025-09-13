# include <iostream>

/* Esse programa tem o objetivo de mostrar a utilização de uma função da biblioteca padrão do c++, nesse caso a toupper() que converte texto de minúsculo para maiusculo
 também foi útil para entender uma caracterítica dessa função que pode chamar apenas a representação númerica do ascii caso não seja bem trabalhada*/

int main(){
  char letra{'a'}; // define um variável com a letra em minúsculo
  char letraMaiuscula{}; // declara uma variável para armazenar a letra convertida para maiuscula 
  
  std::cout << "valor orinal da letra: " << letra << '\n';
  std::cout << "valor da letra convertida para maiuscula: " << toupper(letra) << '\n';
  letraMaiuscula = toupper(letra);
  std::cout << "valor da variável com a letra convertida: " <<  letraMaiuscula << '\n';
  return 0;
}

// observação: toupper funciona apenas para char, não funciona para string
