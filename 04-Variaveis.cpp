#include <iostream>

int main() {
  int x; // declara a variável de tipo inteiro
  x = 2147000; // define o valor que será guardado na memória no local alocado para x em tempo de execução 
  std::cout << "o valor de x é: " << x << '\n';
  char a;
  a = 'K';
  bool teste;
  teste = true;
  double y = 3.141592;
  std::cout << "o valor de a é: " << a << '\n';
  std::cout << "o valor de teste é: " << teste << '\n';
  std::cout << "o valor de y é: " << y << '\n';

}

/*
|tipo  | Descrição | Exemplos | Intervalo |
|---|---|---|---|  
|bool  |Boleano  |true ou false  | true ou falso |
|char|Caracter|z, a, (um único caracter)| -128 a 127 |
|int|Inteiro|1, 2, 10, 1000| -2,147mm a + 2,147 mm |
|float | ponto flutuante com precisão de 32 bits | 3.14 2912847132.1 | 7 dig sigtnificativos |
|double|Ponto flutuante com o dobro de precisão|3.14, 299793.0| 16 dig. significativos |

O tamanho alocado em cada tipo é um multiplo do padrão básico char,
sizeof(char)=1, sizeof(bool)=1, sizeof(int)=4, sizeof(double)=8 */



