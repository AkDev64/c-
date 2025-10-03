#include<iostream>
using namespace std;

int main(){

cout << "*** Métodos de alteração de Strings ***" << endl;

// definição de uma string 
string str = "Minha String não Criativa";
cout << "String original: " << str << endl;

// adcionando caracter ao final da String
str.push_back('?');
cout << "String após push_back de ?: " << str << endl;

// excluindo ao final da string com pop_back
str.pop_back();
cout << "String após pop_back de ?: " << str << endl;

// excluindo parte da string com erase()
str.erase(13,5);
cout << "String após exclusão de caracteres com erase(): " << str << endl;

// inclusão de caracteres na string com inserg()
str.insert(13, "é ");
cout << "String após inclusão de caracteres com insert(): ':" << str << endl;

// última inclusão para arrematar ;) 
str.push_back('!');
cout << "String final após um push_back para arrematar: " << str << endl;

return 0;
}
