#include <iostream>
using namespace std;

// Defining macros
#define PI 3.14159
#define quadrado(x) (x * x)

int main() {
    double raio = 0;
    cout << "Ditige o tamanho do raio: ";
    cin >> raio;
    
    // Macro name PI and findSquare will be substituted
    // by preprocessor
    double area = PI * quadrado(raio);

    cout << "A área do circulo com raio " << raio << " é " << area;
    return 0;
}
