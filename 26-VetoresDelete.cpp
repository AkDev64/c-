/*
 * Deleção de elementos de vetor
 * três métodos
 * Sumário esconder
 *
 * Método #1 – pop_back()
 * Método #2 – erase(it)
 * Método #3 – erase(begIt, endIt)
 * Remoção/adição no meio de um vetor
 * Método #4 – remove(begIt, endIt, value)
 * Método #5 – remove_if(begIt, endIt, predicate)
 * Método #6 (bônus) – clear()
 */

#include<iostream>
#include<vector>
using namespace std;

void imprime(vector<int> v){
  cout << endl;
  for (int i : v){
    cout << v[i] << " ";
  }
}


int main () {
 // definindo um vetor
 vector<int> vtr= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << "vetor original: ";
  imprime(vtr); // imprime o vetor original

 // Método #1 – pop_back()
 // deletando elemento último elemento
  vtr.pop_back();
  cout << endl << "vetor após apagar o último elemento com o método pop_back: ";
  imprime(vtr);


 // deletando elemento último elemento novamente
  vtr.pop_back();
  cout << endl << "vetor após apagar o último elemento com o método pop_back: ";
  imprime(vtr);

  // Método #2 – erase e end()
  // Apagando o último item
  vtr.erase(vtr.end()-1);
  cout << endl << "imprimindo vetor após apagar o último elemento com os métodos erase e end: ";
  imprime(vtr);

/*
// Apagando o segundo item com erase e iterator ----> ATENÇÃO ----> esse bloco funciona, mas faz os blocos abaixo dele não funcionarem. O iterador não deve ser usado dessa maneira. Resolvi deixar no código pois foi didático perceber isso.
  std::vector<int>::const_iterator final = vtr.end();
  vtr.erase(final-3); 
  cout << endl << "imprimindo vetor após apagar o antepenúltimo elemento com os métodos erase e iterator: " << endl;
  for ( int i=1; i < vtr.size(); i++){
  cout << vtr[i] << " ";
 }
// imprime(vtr); // não funciona por causa do iterador.
// obs: nota do site [cppmoderno](https://cppmoderno.com) Note que no exemplo acima eu armazenei o retorno do método end() aplicado ao final em um iterador chamado endIt. Todavia, isso não é recomendável quando se está removendo (ou adicionando) elementos a um vetor, pois durante essas operações o vetor pode ser redimensionado para expandir a sua memória que lhe é dedicada, ou para reduzí-la (caso tenham sido removidos elementos do vetor). Assim sendo, um iterador como endIt que aponta para um endereço de memória de antes do redimensionamento do vetor, pode se tornar inválido após o redimensionamento. Isso nos leva ao quadro de boas práticas de programação a seguir.
*/
 

// Apagando os elementos centrais, exceto as pontos do vetor com os métodos begin e end
vtr.erase(vtr.begin()+1,vtr.end()-1);
imprime(vtr);
  return 0; 
}
