# include<iostream>
using namespace std;

bool entreLoop(int parametro){
  int contador = 1;
  while(contador <= parametro){
    cout << "volta " << contador << '\n';
    contador = contador +1;
  }
  return 0;
}

int main(){
  std::cout << "Digite um número inteiro para definir quantas voltas daremos: \n";
    int escolha = 0;
    std::cin >> escolha; // defina a quantidade de vezes que vamos rodar o loop
    
    if (escolha == 0) {
      std::cout << "saindo"; // nenhuma vez
      return 0; 
    } else {
      entreLoop(escolha);
    }
  return 0;
}

/*
 Uma outra forma de usar o while é com o controle 
 do {
   
 } while(condicao); // repare que nesse caso a primeira volta é incondicional, o teste ocorre só após a primeira volta
 */
