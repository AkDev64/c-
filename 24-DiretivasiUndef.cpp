#include <iostream>
using namespace std;

 //Defining a macro
 #define MAX_VALUE 100

 int main()  {
    cout << MAX_VALUE << endl;

 //using undef to change MAX_VALUE
  #undef MAX_VALUE
  #define MAX_VALUE 200

    cout << MAX_VALUE;
    return 0;
 }

