# include <iostream>

int main() {

int x = 1;
int y(2);
int z{3}; // preferível por atribuir um valor 0 as variáveis aumentando previsibilidade (entender melhor)

std::cout << "os valores x, y e z são:" << x << '\n' << y << '\n' << z;

}
