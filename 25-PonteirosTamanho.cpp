/* Size of Pointers

The size of pointer in a system is equal for every pointer no matter what type of data it is pointing to. It does not depend on the type, but on operating system and CPU architecture. The size of pointers in C++ is 

    8 bytes for a 64-bit System
    4 bytes for a 32-bit System

The logic is simple: pointers store the addresses of the memory and in a computer, the maximum width of a memory address is determined by the CPU architecture. For example, for a 64-bit CPU, the address will always be 64-bit wide. This can be verified using sizeof operator.
from: https://www.geeksforgeeks.org/cpp/cpp-pointers/
*/

#include <iostream>
using namespace std;

int main() {
    int *ptr1;
    char *ptr2;
    
    // Finding size using sizeof()
    cout << sizeof(ptr1) << " bytes" << endl;
    cout << sizeof(ptr2) << " bytes";
    
return 0;
}

