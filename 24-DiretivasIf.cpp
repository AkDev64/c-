/*
if constant_expr
  //Code to be executed if constant_expression is true
#elif another_constant_expr
  // Code to be excuted if another_constant_expression is true
#else
  //Code to be excuted if none of the above conditions are true
#endif
*/


#include <iostream>
using namespace std;

// marque e desmarque o comentário dessas próximas duas linhas e recompile para entender o comportamento das condicionais
//#define PI 3.14159
//#define SQUARE(x) (x * x)


int main() {

// Conditional compilation
#if defined(PI)
     cout << "PI is defined";
#elif defined(SQUARE)
     cout << "PI is not defined, SQUARE is defined";
#else
    cout << "Neither PI nor SQUARE is defined";
#endif
            
return 0;
}
