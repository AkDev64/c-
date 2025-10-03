/*
Strings can be joined using the + operator or the append() function.
The + operator creates a new string, while append() modifies the existing string in place.
Time complexity for concatenation is O(n+m), where n is the size of string and m is the size of the string to be concatenated.
*/

#include<iostream>
using namespace std;

int main(){

// definição do Programa
cout << "*** Concatenação de Strings ***" << endl;

// Declaração de duas strings para serem concatenadas.
string str1 = "C++ ";
string str2 = "Moderno";

// Concatenar usando operador + 
string strResultante = str1 + str2;
cout << "Resultado das strings concatenadas com o operador +: " << strResultante << endl;

// Concantenar usando append()
string strResultante2 = str1; // primeiro definie a string resultante igual a primeira a ser concaenada 
strResultante2.append(str2);
cout << "Resultado das strings concanetadas com o método append(): " << strResultante2 << endl;

  return 0;
}
