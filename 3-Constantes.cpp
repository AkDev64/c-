#include<iostream>
/*
 Há duas formas de declarar uma constante em c++
 const int nomeDaDesejavelConstante = 10;
 constexpr int  = 10 ConstanteNaoPodeMudarDeJeitoNenhum = 10;
 vamos ver a diferença de comportamento abaixo
*/


constexpr double squares(double x){
  return x * x;
}


int main(){
  const int constante = 17; //declaração #de tipo constante
  int variavel = 17; //declaração de tipo variavel
  // apesar de possuirem o mesmo valor armazenado, constante e varivel tem comportamento diferentes para o compilador
  constexpr double max1 = 1.4*squares(constante); // igual raiz quadrada da constante 17 passada para a constante max1
  // constexpr double max2 = 1.4*squares(variavel); // ERRO - não se pode atribuir a constexpr max2 um valor que poderá ser variável, para evitar erros e melhorar performance
  // se a linha de cima não estiver comentada, o programa não compila: error: the value of ‘variavel’ is not usable in a constant expression
  const double max3 = 1.4*squares(variavel); // nesse caso dá certo, porque tipo const pode ser mudado, apesar de não ser o objetivo prioritário da sua definição

  std::cout << "max1: " << max1 << '\n';
  std::cout << "max2 nem pode ser compilada, basta descomentar o código para tentar. \n";
  std::cout << "max3: " << max3;
  // não imprimir max2, porque é para mostrar que não funciona

  return 0;
}
