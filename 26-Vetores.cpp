/*
 A vector represents a dynamic sized array in the 
 Standard Template Library(STL) that automatically 
 grows when elements are added beyond current capacity.

 A programmer does not have to worry about maintaining 
 the capacity and allocating extra space initially.
 Certain insertions and removals can become slightly 
 costly in terms of time as it internally resizes 
 itself beyond certain predefined limits. If time 
 taken for these operations is super critical, 
 then use of plain arrays in C++ should be preferred.

 Vectors support bound checking by using v.at(i) 
 for accessing an element at index i in a vector v. 

from: https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/
*/

#include <iostream>
#include <vector> // necessário para usar vetores da biblioteca STL (Standard Template Library)
using namespace std;

int main () {
 
// incializando um vetor do tipo inteiro vazio
vector<int> vetor1;

// incializando um vetor com tamanho estabelecido e atribuindo valores para ele
vector<int> vetor2(5, 10); // significa um vetor de tamanho cinco com dez atribuido em cada valor, ou seja igual a vetor2 = {10,10,10,10,10}

// imprimindo os valores de vetor2
for (int x : vetor2){
  cout << x << " ";
}

// inicializando um vetor descrevendo seus valores
vector<int> vetor3 = {11, 22, 33, 44, 55};

cout << endl; // apenas para criar uma linha vazia na tela para melhor visualização

// imprimindo os valores do vetor3
for (int x: vetor3){
  cout << x << " ";
}

  return 0;
}

