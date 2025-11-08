#include <iostream>

namespace Rio  {
  std::string sigla = "RJ";
  std::string capital = "Rio de Janeiro";
  int população = 20000000;
}

namespace SaoPaulo  {
       std::string sigla = "SP";
       std::string capital = "São Paulo";
       int população = 30000000;
     }

  namespace Bahia  {
        std::string sigla = "BA";
        std::string capital = "Salvador";
        int população = 10000000;
     }

int main (int argc, char *argv[]) {
  std::cout << Rio::capital << '\n';
  std::cout << SaoPaulo::capital << '\n';
  std::cout << Bahia::capital << '\n';  
  return 0;
}
