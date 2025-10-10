#include <iostream>

int main( int argc , char **argv ){
  for( int i = 30; i < 40 ; i++ ){
    for( int k = 0 ; k < 6; k++ ){
      std::cout << "\e[" << i << ";" << k << "m CORRR" << "\e[m ";
    }
  }
  return 0;
}

