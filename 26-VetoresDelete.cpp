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
    cout << i << " "; // essa linha foi corrigida por IA após varias tentativas de entender o problema, abaixo a explicação perfeita do gemini

/* The runtime error in 26-VetoresDelete.cpp is caused by a bug 
  in the imprime function.

  Here is the problematic code block:

   1 void imprime(vector<int> v){
   2   cout << endl;
   3   for (int i : v){
   4     cout << v[i] << " ";
   5   }
   6 }

  In C++, a range-based for loop like for (int i : v) 
  iterates through the elements of the container. This means 
  the variable i holds the actual values from the vector (0, 
  1, 2, etc.), not their index positions. The code then 
  incorrectly uses this value i as an index to access v[i].

  This works coincidentally at the beginning because the 
  vector's values (0, 1, 2...) happen to be the same as its 
  valid indices. However, after you call 
  vtr.erase(vtr.begin()+1,vtr.end()-1), the vector vtr 
  contains only {0, 7}.

  When imprime is called on this modified vector:
   1. The first element, 0, is assigned to i. v[0] is accessed, 
      which prints 0.
   2. The second element, 7, is assigned to i. The code then 
      tries to access v[7]. Since the vector only has two 
      elements (at indices 0 and 1), trying to access the 
      element at index 7 is an out-of-bounds memory access, 
      which causes the runtime error.
*/
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


// Apagando o segundo item com erase e iterator ----> ATENÇÃO ----> esse bloco funciona, mas faz os blocos abaixo dele não funcionarem. O iterador não deve ser usado dessa maneira. Resolvi deixar no código pois foi didático perceber isso.
  std::vector<int>::const_iterator final = vtr.end();
  vtr.erase(final-3); 
  cout << endl << "imprimindo vetor após apagar o antepenúltimo elemento com os métodos erase e iterator: " ;
  imprime(vtr); // não funciona por causa do iterador.
// obs: nota do site [cppmoderno](https://cppmoderno.com) Note que no exemplo acima eu armazenei o retorno do método end() aplicado ao final em um iterador chamado endIt. Todavia, isso não é recomendável quando se está removendo (ou adicionando) elementos a um vetor, pois durante essas operações o vetor pode ser redimensionado para expandir a sua memória que lhe é dedicada, ou para reduzí-la (caso tenham sido removidos elementos do vetor). Assim sendo, um iterador como endIt que aponta para um endereço de memória de antes do redimensionamento do vetor, pode se tornar inválido após o redimensionamento. Isso nos leva ao quadro de boas práticas de programação a seguir.

// Apagando os elementos centrais, exceto as pontos do vetor com os métodos begin e end
  cout << endl << "imprimindo vetor após apagar todos elementos exceto o primeiro e o último com o método erase e (begin,end): " ;
  vtr.erase(vtr.begin()+1,vtr.end()-1);
  imprime(vtr);

  return 0; 
}
