// Arquivo criado pelo Gemini para explicar o conceito de Sobrecarga de
// Operadores em C++.
#include <iostream> // Inclui a biblioteca para entrada e saída de dados (como std::cout).

// A classe Ponto encapsula o conceito de um ponto com coordenadas 2D.
class Ponto {
public:
  // Membros de dados públicos para armazenar as coordenadas x e y.
  int x, y;

  // --- Construtor da Classe ---
  // Este construtor inicializa um objeto Ponto.
  // 'Ponto(int x = 0, int y = 0)' usa parâmetros padrão, permitindo criar um
  // Ponto de formas flexíveis: Ponto(), Ponto(5), Ponto(5, 10).
  // ': x(x), y(y)' é a lista de inicialização de membros. É a forma preferida e
  // mais eficiente de atribuir os valores dos parâmetros (o 'x' e 'y' de dentro
  // dos parênteses) para as variáveis-membro da classe (o 'x' e 'y' antes dos
  // parênteses).
  // '{'}' é o corpo do construtor, que está vazio pois toda a inicialização já
  // foi feita.
  Ponto(int x = 0, int y = 0) : x(x), y(y) {}

  // --- SOBRECARGA DO OPERADOR '+' COMO UMA FUNÇÃO-MEMBRO ---
  // Esta função define como o operador '+' deve se comportar com objetos Ponto.
  // A assinatura 'Ponto operator+(const Ponto& outro) const' significa:
  // - 'Ponto': O tipo de retorno. A soma de dois pontos resulta em um novo
  // Ponto.
  // - 'operator+': É a sintaxe especial para declarar a sobrecarga do operador
  // '+'.
  // - 'const Ponto& outro': É o parâmetro da função, representa o objeto à
  // DIREITA do '+'.
  //   'const' garante que o objeto 'outro' não será modificado.
  //   '&' (referência) evita uma cópia desnecessária do objeto, melhorando a
  //   performance.
  // - 'const' (no final): Garante que esta função não modifica o objeto à
  // ESQUERDA do '+',
  //   ou seja, o objeto que está chamando a função (referenciado pelo ponteiro
  //   'this').
  Ponto operator+(const Ponto &outro) const {
    // 'this->x' e 'this->y' são as coordenadas do objeto à esquerda do '+'.
    // 'outro.x' e 'outro.y' são as coordenadas do objeto à direita do '+'.
    // 'return Ponto(...)': Cria e retorna um NOVO objeto Ponto temporário,
    // cujo valor é a soma das coordenadas dos outros dois.
    return Ponto(this->x + outro.x, this->y + outro.y);
  }
};

// --- SOBRECARGA DO OPERADOR '<<' COMO UMA FUNÇÃO GLOBAL (NÃO-MEMBRO) ---
// Esta função define como um objeto Ponto deve ser enviado para um stream de
// saída (como std::cout). Precisa ser uma função global porque o objeto à
// esquerda do '<<' é o 'std::cout' (tipo ostream), e não o nosso objeto Ponto.
// A assinatura 'std::ostream& operator<<(std::ostream& os, const Ponto& p)'
// significa:
// - 'std::ostream&': O tipo de retorno. Retornamos uma referência ao stream
// para permitir
//   o "encadeamento" de saídas (ex: std::cout << p1 << " e " << p2;).
// - 'operator<<': Sintaxe para sobrecarregar o operador de inserção '<<'.
// - 'std::ostream& os': O primeiro parâmetro é uma referência ao stream de
// saída (o próprio std::cout).
// - 'const Ponto& p': O segundo parâmetro é o objeto Ponto que queremos
// imprimir.
std::ostream &operator<<(std::ostream &os, const Ponto &p) {
  // 'os << ...': Modifica o stream de saída para incluir a representação
  // textual do Ponto.
  os << "(" << p.x << ", " << p.y << ")";
  // 'return os;': Retorna o stream modificado para permitir o encadeamento.
  return os;
}

// --- Função Principal ---
int main() {
  // Declara e inicializa dois objetos da classe Ponto usando o construtor.
  Ponto p1(2, 5);
  Ponto p2(8, 3);

  // Usa o operador '<<' sobrecarregado para imprimir p1.
  // O compilador transforma isso em uma chamada: operator<<(std::cout, p1);
  std::cout << "Ponto 1: " << p1 << std::endl;
  std::cout << "Ponto 2: " << p2 << std::endl;

  // Usa o operador '+' sobrecarregado para somar os dois pontos.
  // O compilador transforma isso em uma chamada à função-membro: p3 =
  // p1.operator+(p2);
  Ponto p3 = p1 + p2;

  // Imprime o resultado da soma, novamente usando o '<<' sobrecarregado.
  std::cout << "Soma (p1 + p2): " << p3 << std::endl;

  // Retorna 0 para indicar que o programa terminou com sucesso.
  return 0;
}
