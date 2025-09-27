/*
 8. #pragma
The #pragma directive is a compiler-specific instructions. Special instructions to the compiler are provided using the #pragma directive. It may be used to alter compiler parameters, silence warnings behaviour, etc. Supported pragmas can vary between different compilers as they are compiler specific.

Syntax
#pragma directive

Commonly Used #pragma Flags
    #pragma once: used to include guard for header files.
    #pragma message: used to print custom messages at the time of compilation.
    #pragma warning: used to control warning behaviour (like enable or disable warnings).
    #pragma optimize: used to control optimization settings (manage optimization level).
    #pragma comment: used to include some additional information in the object file (or specify linker options).

from: https://www.geeksforgeeks.org/cpp/cpp-preprocessors-and-directive
*/

#include <iostream>
using namespace std;

#pragma once

// Defining PI to trigger a pragma message during
// compilation
#define PI 3.14

// to set aggressive optimization level
#pragma optimize("O3")

int main() {
#ifdef PI
#pragma message("SIM! PI está definido.")
#endif
  cout << "na função principal!\n";
    return 0;
}

// assim como em #message, pragma apresenta as mensagens em tempo de compilação, mans não a impede.
