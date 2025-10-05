# Diferença entre Struct e Class em c++

Structure vs Class

In C++, a structure works similarly to a class, but there are some key differences in between of them. The important difference is how implementation details are handled.

    By default, a structure does not provide its implementation details, allowing them to be accessed by anyone using the structure. In other hand, a class hides its implementation details by default, thus preventing the programmer from accessing them.

[Geekforgeek](https://www.geeksforgeeks.org/cpp/structure-vs-class-in-cpp)


Difference Between Structure and Class in C++
Last Updated : 01 Oct, 2025

In C++, a structure works the same way as a class, except for the difference that members of a class are private by default and members of a structure are public by default. 

For example, program 1 fails in compilation but program 2 works fine, 

Program 1

// C++ Program to demonstrate that

// Members of a class are private

// by default

#include <iostream>

​

using namespace std;

​

class Test {

    // x is private

    int x;

};

​

int main() {

    Test t;

  

    // compiler error because x

    // is private

    t.x = 20;

​

    return t.x;

}


 Output:

./cf03c8d1-d4a3-43ea-a058-fe5b5303167b.cpp: In function 'int main()':
./cf03c8d1-d4a3-43ea-a058-fe5b5303167b.cpp:10:9: error: 'int Test::x' is private
     int x;
         ^
./cf03c8d1-d4a3-43ea-a058-fe5b5303167b.cpp:18:7: error: within this context
     t.x = 20;
       ^
./cf03c8d1-d4a3-43ea-a058-fe5b5303167b.cpp:10:9: error: 'int Test::x' is private
     int x;
         ^
./cf03c8d1-d4a3-43ea-a058-fe5b5303167b.cpp:20:14: error: within this context
     return t.x;
              ^

Program 2:

// C++ Program to demonstrate that

// members of a structure are public

// by default

#include <iostream>

​

using namespace std;

​

struct Test {

    // x is public

    int x;

};

​

int main()

{

    Test t;

    t.x = 20;

​

    // works fine because x is public

    cout << t.x;

}


Output

20

There is no other difference as structures support all features of a class like member methods, inheritance and virtual functions. The following is a summary of differences

S. No.
	

Class
	

Structure

1
	

Members of a class are private by default.
	

Members of a structure are public by default.

2
	

It is declared using the class keyword.
	

It is declared using the struct keyword.

3
	

It is normally used for Object Oriented Programming.
	

It also allows almost all features of a class, but is normally used for the grouping of different datatypes.

To know about the Difference between C structures and C++ structures refer to this article.
