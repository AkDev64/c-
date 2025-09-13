# include <iostream>

int soma( int x, int y){
  return x + y;
}

int main(){
  int x = 10, y = 20;
  std::cout << "x+y= " << soma (x,y);
  return 0;
}
