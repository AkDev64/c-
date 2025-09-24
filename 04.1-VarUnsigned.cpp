# include <iostream>

int main() {
  int x = 2147483647; // valor máximo 2.147.483.647 alcançado pela variável int com valores negativos e positivos
  int unsigned y = 4294967295; // valor máximo da variável apenas positivos 
  std::cout << "x=" << x << '\n' <<"y=" << y;
}

// Esse exemplo mostrou a importânia de entender o limite de valores possíveis em cada tipo de variável, uma pesquisa rápida no google ou em algum manual de c++ deve ser realizado toda vez que houver dúvida sobre os limites de cada uma.

