// Esse exemplo foi criado pelo Gemini para mostrar o problema do diamante em
// C++.
#include <iostream>

class Veiculo {
public:
  Veiculo() { std::cout << "Construtor de Veiculo chamado" << std::endl; }
  void acelerar() { std::cout << "Veiculo acelerando..." << std::endl; }
};

class Carro : public Veiculo {
public:
  Carro() { std::cout << "Construtor de Carro chamado" << std::endl; }
};

class Barco : public Veiculo {
public:
  Barco() { std::cout << "Construtor de Barco chamado" << std::endl; }
};

class Anfibio : public Carro, public Barco {
public:
  Anfibio() { std::cout << "Construtor de Anfibio chamado" << std::endl; }
};

int main() {
  Anfibio anfibio;
  // A linha abaixo causará um erro de compilação se for descomentada
  // anfibio.acelerar();
  return 0;
}

/*
  EXPLICAÇÃO DO PROBLEMA DO DIAMANTE:

  O "Problema do Diamante" ocorre devido à forma como a herança é estruturada,
  lembrando a forma de um diamante:

        Veiculo
        /     \
      Carro   Barco
        \     /
        Anfibio

  1. Herança Duplicada:
     - A classe `Anfibio` herda de `Carro` e `Barco`.
     - Ambas `Carro` e `Barco` herdam da classe base `Veiculo`.
     - Como resultado, `Anfibio` herda duas cópias de todos os membros
       (dados e métodos) de `Veiculo`, uma por cada "caminho" de herança.

  2. Ambiguidade:
     - No nosso exemplo, `Veiculo` tem o método `acelerar()`.
     - A classe `Anfibio` acaba tendo duas versões do método `acelerar()`.
     - Quando tentamos chamar `anfibio.acelerar()`, o compilador não sabe
       qual das duas versões executar (a que veio de `Carro` ou a que veio
       de `Barco`). Isso gera um erro de "ambiguidade".

  3. Construtores Duplicados:
     - Um sintoma do problema é que o construtor de `Veiculo` é chamado
       duas vezes quando um objeto `Anfibio` é criado, uma para a parte
       `Carro` e outra para a parte `Barco`.

  A solução para este problema em C++ é usar "herança virtual", que garante
  que apenas uma única cópia da classe base `Veiculo` seja incluída na
  classe final `Anfibio`.
*/