/* A diretiva #error é usada para imprimir uma mensagem customizada de erro para o tempo de compilação.
 * A diretiva #warning é similar, mas não se limita a casos de erro.
 */

#include <iostream>
using namespace std;

// not defining it to trigger the warning
// //#define PI 3.14

#ifndef PI
#error "PI is not defined!"
#endif

int main() {
  cout << "Aparece erro na compilação, mas compilar com o warning apresentado na compilação";
return 0;
}
