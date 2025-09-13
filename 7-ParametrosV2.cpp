# include <iostream>

/* Essa abordagem foi do professor, colocando a impressão na função soma e retonando 0 como resultado da função, achei a minha mais elegante. rs.
  Ps: para ser justo, ele fez para efeito ditático, em um segundo momento ele acaba alterando e fincando (ParametroV3.cpp) muito parecida com a versão que imaginei, bom sinal */

int soma(int x, int y){
  std::cout << "x + y = " << x + y;
  return 0;
}

int main() {
  int x = 10, y = 20; // dessa maneira apenas para mostrar que também funciona
  //int y = 20; eu havia tentado int x =10; int y = 20; não funcionou o tipo, nesse caso int, só poder ser explicito uma vez na linha
  soma(x,y); // mais uma vez, aqui poderi ser direto soma(10,20);
             //
  return 0;
}
