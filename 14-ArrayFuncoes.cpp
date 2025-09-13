#include <iostream>
#include "14-AlteraArray.h"
#include "14-ImprimeArray.h"


int main(){
// definindo um array e imprimindo os valores iniciais dele
  int meuarray[] = {1,2,3,4,5};
  std::cout << "valores iniciais do array \n"; 
  imprimeArray(meuarray);

// alteando o valor do array por meio de uma função e reimprimindo para ver as alterações
  alteraArray(meuarray);
  std::cout << "valores alterados do array \n"; 
  imprimeArray(meuarray);

return 0;
}
