#include <iostream>
using namespace std;

// Definign two macros

// marque e desmarque o comentário das duas linhas a seguir para entender o comportamento das diretivas
//#define DEBUG
//#define PI 3.14

int main() {

// Check if DEBUG is defined
#ifdef DEBUG
   cout << "Debug mode is ON" << endl;
#else
   cout << "Debug mode is OFF" << endl;
#endif

// Check if PI is defined
#ifndef PI
   cout << "PI is not defined" << endl;
#else
   cout << "PI is defined" << endl;
#endif

return 0;
}

