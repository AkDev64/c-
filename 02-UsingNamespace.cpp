# include <iostream>
using namespace std; // essa diretiva declara os elementos da biblioteca std para todo o programa evitando a necessidade de incluir o namespace (std:: )em cada ocorrência.

para evitar digitar :: a cada utilização da biblioteca, pode se usar a declarativa namespaces. ex: use namespaces = std;


double square(double x){ // observar a declaração do tipo da variável dentro do parâmetro da função.
	return x*x; 
}

void print_square(double x){

	cout << "the square of " << x << "is:\n" << square(x) << "\n"; // cout pertence a bliblioteca std, mas não foi necessário o namespace std::. 

}

int main()
{
	print_square(1.234);
}
