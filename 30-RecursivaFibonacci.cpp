#include <iostream>
using namespace std;

int fibonacci(int x){
  return (x <= 1) ? 1 : fibonacci(x-1) + fibonacci(x-2);
}

int main (int argc, char *argv[]) {
cout << "Sequência de Fibonacci" << endl;
int y = stoi(argv[1]);
int i = 0;
while (i < y){
cout << " " << fibonacci(i);
i++;
}

return 0;
}
