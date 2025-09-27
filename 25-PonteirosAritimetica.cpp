/*
Pointer Arithmetic

[Pointer arithmetic](https://www.geeksforgeeks.org/cpp/cpp-pointer-arithmetic/) refers to the operations that C++ allows on the pointers. They include:

    Incrementing and Decrementing
    Addition of Integer
    Subtraction of Integer
    Subtraction of Two Pointers of the Same Type
    Comparison of Pointers and NULL
 */

#include<iostream>
using namespace std;

int main () {
  // inicializando variavel e ponteiro apontando para ela
  int variavel {99};
  int* ponteiro = &variavel;
  cout << "variavel: " << variavel << endl;
  cout << "ponteiro que aponta para ela: " << ponteiro << endl;

  // incrmentando o ponteiro
  ponteiro++; //++ponteiro também funcionaria
  cout << "ponteiro após incremento: " << ponteiro << endl;

  // decrementando o ponteiro
  ponteiro--;
  cout << "ponteiro após decremento: " << ponteiro << endl;

  // adição ponteiro + 5 equivale endereço deslocado em 5 blocos, cada um do tamanho estabelecido pela arquitetura da cpp
  cout << "o tamanho do ponteiro é " << sizeof(ponteiro) << endl;
  cout << "duas casas para cima o endereço é : " << ponteiro + 2 << endl; // mostra o endereço do ponteiro desolcado dois blocos de memoria
  cout << "dez casas para cima o endereço é  : " << ponteiro + 10 << endl; // idem, 10 blocos de memoria

  // Subtração de dois ponteiro
/*
 4. Subtraction of Two Pointers of the Same Datatype
The Subtraction of two pointers can be done only when
both pointers are of the same data type. The subtraction
of two pointers gives the number of elements present
between the two memory addresses so it is primarily 
valid if the two pointers belong to the same array.
For Example, in an array arr[10], ptr1 point points to the element at index 2 and ptr2 points to the element at index 4, then the difference between two pointers will give you the number of elements between them.
 */
  int arr[5] = {0, 1, 2, 3, 4,};
  int* ptr1 = &arr[4];
  int* ptr2 = &arr[0];
  cout << ptr1 - ptr2 << '\n';
  return 0;
}


