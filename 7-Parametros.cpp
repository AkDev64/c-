# include <iostream>

/* essa foi a maneira que eu implementei, imprimindo em tela por meio da main, já o professor fez de outra forma que salvei na v2 desse progrograma 7-FuncoesV2.cpp */

int soma(int x, int y){ // havia tentado declarar os parâmetros com (int x{}, inty{}) e deu erro, imagino que não se definir valores inicias aos parâmetros por definicação, pesquisar mais oportunamente
    return x + y; 
  }

int main(){
  //int x{10}; // tanto faz, declarar e definir as variáveis, como passar valores hard coded por dentro dos parenteses da função soma, das duas formas deu certo
  //int y{20}; // havia tentado declarar em uma única linha int x = 10, int y = 20 e deu errado
  std::cout << "10 + 20 = " << soma(10,20);
return 0;
}
