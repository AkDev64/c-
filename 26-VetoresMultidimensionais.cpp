#include<iostream>
#include<vector>
using namespace std;

int main(){
  // define vetor bidimensional

  vector<vector<int>> vtr = {{1,2,3}, {4,5,6}, {7,8,9}};

  //impressão desse vetor

  for (int i=0; i< vtr.size();i++){
    for (int j=0; j< vtr[i].size(); j++) {
      cout << "o elemento [" << i << "][" << j << "] é: " << vtr[i][j] << endl;
    }
  }

  return 0;
}
