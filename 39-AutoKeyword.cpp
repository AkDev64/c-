#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional> // Para std::function, para comparar com auto em lambdas

/*
  EXPLICAÇÃO: A PALAVRA-CHAVE `auto`

  A palavra-chave `auto` (introduzida no C++11) é um recurso de dedução de tipo.
  Ela instrui o compilador a inferir automaticamente o tipo de uma variável
  a partir do seu inicializador.

  ### Para qual finalidade (`Quando Usar`)?

  1.  **Reduzir a verbosidade e melhorar a legibilidade:**
      Especialmente com tipos complexos da STL (como iteradores, tipos de retorno
      de lambdas, etc.). O código fica mais limpo e fácil de ler.
      Exemplo: `auto it = mapa_complexo.begin();`

  2.  **Com Lambdas:**
      O tipo de uma lambda é único e anônimo, então `auto` é a maneira padrão
      (e muitas vezes a única prática) de armazenar uma lambda em uma variável.
      Exemplo: `auto minha_lambda = [](int x, int y) { return x + y; };`

  3.  **Garantir o tipo "correto":**
      `auto` deduzirá o tipo exato retornado por uma expressão, o que pode ser
      mais preciso do que tentar adivinhar um tipo base.

  ### Quando `NÃO Usar` (Com Cautela)?

  1.  **Quando a clareza é prejudicada:**
      Se o tipo não é óbvio a partir do inicializador, usar `auto` pode tornar
      o código mais difícil de entender para quem o lê.
      Exemplo: `auto y = obterValor();` (Qual o tipo de 'y' sem ver 'obterValor()'?) 

  2.  **Evitar conversões implícitas indesejadas:**
      `auto` deduz o tipo exato. Se você *espera* uma conversão implícita, 
      `auto` pode te surpreender.
      Exemplo: `int i = 10; double d = i;` (i é convertido para double).
               `auto d2 = i;` (d2 é um `int`, não um `double`!).

  3.  **Com tipos proxy:**
      Alguns contêineres (como `std::vector<bool>`) retornam "tipos proxy" 
      em vez do tipo real do elemento. `auto` deduzirá o tipo proxy, o que
      pode levar a bugs sutis.
*/

int main() {
    std::cout << "--- Demonstração da palavra-chave 'auto' ---\\n";

    // --- 1. Uso básico com tipos óbvios ---
    auto inteiro = 10;          // int
    auto flutuante = 3.14;      // double
    auto texto = "Olá, auto!";  // const char*
    auto booleano = true;       // bool

    std::cout << "inteiro: " << inteiro << " (tipo: " << typeid(inteiro).name() << "\\n";
    std::cout << "flutuante: " << flutuante << " (tipo: " << typeid(flutuante).name() << "\\n";
    std::cout << "texto: " << texto << " (tipo: " << typeid(texto).name() << "\\n";
    std::cout << "booleano: " << booleano << " (tipo: " << typeid(booleano).name() << "\\n";

    // --- 2. Com tipos complexos (STL) ---
    std::vector<std::string> nomes = {"Alice", "Bob", "Charlie"};
    // Sem auto: std::vector<std::string>::iterator it_vec = nomes.begin();
    auto it_vec = nomes.begin(); // Tipo deduzido: std::vector<std::string>::iterator
    std::cout << "\\nPrimeiro nome no vetor (via auto iterator): " << *it_vec << "\\n";

    std::map<int, std::string> mapa_idades = {{1, "Um"}, {2, "Dois"}};
    // Sem auto: std::map<int, std::string>::iterator it_map = mapa_idades.begin();
    auto it_map = mapa_idades.begin(); // Tipo deduzido: std::map<int, std::string>::iterator
    std::cout << "Primeiro par no mapa (via auto iterator): " << it_map->first << ", " << it_map->second << "\\n";

    // --- 3. Com Lambdas ---
    // O tipo da lambda é anônimo, então 'auto' é essencial aqui.
    auto somar = [](int a, int b) { return a + b; };
    std::cout << "Resultado da lambda somar(7, 3): " << somar(7, 3) << "\\n";

    // --- 4. Cuidado com a dedução de tipo (conversões implícitas) ---
    int valor_int = 5;
    double valor_double_explicito = valor_int; // int é convertido para double
    auto valor_double_auto = valor_int;        // auto deduz int, não double!

    std::cout << "\\nvalor_int: " << valor_int << " (tipo: " << typeid(valor_int).name() << "\\n";
    std::cout << "valor_double_explicito: " << valor_double_explicito << " (tipo: " << typeid(valor_double_explicito).name() << "\\n";
    std::cout << "valor_double_auto: " << valor_double_auto << " (tipo: " << typeid(valor_double_auto).name() << "\\n";
    // Note que valor_double_auto é int, não double, apesar do nome da variável.

    return 0;
}
