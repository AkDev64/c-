#include<iostream>
using namespace std;

int main(){

cout << "*** Substring ***" << endl; 

// declarando uma string
  string str = "Uma String Nada Elegante";
  cout << "String Original: " << str << endl;

// extraindo a substring Nada
  string subStr1 = str.substr(0,11);
  cout << "1a extração com substr()" << subStr1 << endl;
  
  string subStr2 = str.substr(16,8);
  cout << "2a extração com substr(): " << subStr2 << endl;

// imprimindo tudo junto
cout << "tudo junto: " << subStr1 <<  subStr2 << endl;

  return 0;
}
