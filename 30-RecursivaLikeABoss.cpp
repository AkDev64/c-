#include <iostream>
using namespace std;

int recursiva(int x){
return (x<=1) ? 1 : x * recursiva(x-1);

//if (x == 0 || x == 1) {
//  return 1;
//} else {
//  return x * recursiva(x-1);
//}
}

int main (int argc, char *argv[]) { 
  int y = stoi(argv[1]);
  cout << "o fatorial de " << y << " é: " << recursiva(y) << endl;
  return 0;
}

