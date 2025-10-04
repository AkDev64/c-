/*
 * Esse programa trata de alocação dinâmica de memória com New e Delete
 * Essa metodologia foi praticamente susbstituída em c++ moderno por
 * RAII (Resource Acquisition Is Initialization):** Este é talv    ez o conceito mais importante do C++ moderno. Entenda-o profunda    mente. Use `std::unique_ptr`, `std::shared_ptr`, `std::lock_guar    d` para gerenciar memória e outros recursos. Abandone o `new` e     `delete` manuais sempre que possível. Recomendação do Gemini
 */

#include<iostream>
using namespace std;

int main (int argc, char *argv[]) {
  
/* criando dois arrays, um com alocação dinâmica de memória com new e outro sem essa alocação
   A diferença fundamental é que int array[10]; declara um array de tamanho fixo na stack, enquanto int* array = new int[10]; aloca dinamicamente um array em um ponteiro na heap, permitindo um tamanho de array que pode ser decidido em tempo de execução, mas exigindo a liberação manual da memória com delete[] para evitar vazamentos. 
int array[10]; (Array na Stack)
    Alocação:
    A memória para o array é alocada automaticamente na pilha (stack) quando a variável é declarada. 
Tamanho:
O tamanho do array deve ser conhecido em tempo de compilação e não pode ser alterado durante a execução do programa. 
Gerenciamento de Memória:
A memória é liberada automaticamente quando a variável sai do escopo. Não é necessário usar delete. 
*/
  
  // primeiro o array
  // int arr1[3] = {1, 2, 3}; // tamanho fixo, precisa ser conhecido em tempo de alocação. Memória alocada na STACK
  int m = 0;
  cout << "Digite a quantidade de elementos para o array que deveria ser estático: "; // 
  cin >> m;
  int arr1[m];
  cout << "Endereço do array na memória: " << arr1 << endl;
  cout << "valor de cada elemento do array: " << endl;
  for (int i=0; i<sizeof(arr1)/sizeof(arr1[0]); i++){
    cout << "elemento: " << i << " do array é: " << arr1[i] << endl;
  }

  // segundo array
  int n = 0;
  cout << "Digite a quantidade de elementos para o array dinâmico: ";
  cin >> n;
  int* ptr = new int[n]; // alocação dinâmica, pode ser alterado em tempo de execução. Memória alocada na HEAP
  cout << "Endereço do array na memória: " << &ptr << endl; 
  cout << "valor de cada elemento do array: " << endl;
  for (int i=0; i<n; i++){
    cout << "elemento: " << i << " do array é: " << ptr[i] << endl;
  }

  delete[] ptr; // liberando a memória alocada dinâmicamente para ptr
  ptr = NULL; // fazendo que o ponteiro ptr não aponte mais para o endereço que havia recebido
  return 0;
}
