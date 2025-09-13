# include <iostream>

int main(){
  int x{3}, y{6}, z{9};
  std::cout << "x=" << x << " y=" << y << " z=" << z << '\n'; 
  std::cout << "x + y: " << x+y << '\n';
  std::cout << "x * y: " << x*y << '\n';
  std::cout << "z % y: " << z%y << '\n';
  std::cout << "+x: " << +x << '\n';
  std::cout << "-y: " << -y << '\n';
  std::cout << "z / x: " << z/x << '\n';

}
