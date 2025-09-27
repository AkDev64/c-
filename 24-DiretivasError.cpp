/* A diretiva #error é usada para imprimir uma mensagem customizada de erro para o tempo de compilação.
 * A diretiva #warning é similar, mas não se limita a casos de erro.
 */

#include <iostream>
using namespace std;

// não definindo PI aqui
//#define PI 3.14159 // quando essa linha está comentada, o compilador apresenta erro ao compilar como definido em #error abaixo

int main() {

#if defined(PI)
     cout << "PI foi definido" << endl;
#else
#error "PI não foi definido" // impede a compilação caso a PI não seja definido acima.
#endif

return 0;
}

// diferentemente de #message, #error impede a compilação, enquanto #message apenas apresenta a mensagem na fase de compilação
// para ver isso, bastar trocar #error por #message acima e perceber a diferença no resultado da compilação
//
