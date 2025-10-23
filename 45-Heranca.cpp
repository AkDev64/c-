#include <iostream>
#include <string>

class MeioTranporte {
public:
  void setMeioTransporte(std::string pMeioTranporte) {
    meioTranporte = pMeioTranporte;
  }

  std::string getMeioTransporte() { return meioTranporte; }

private:
  std::string meioTranporte;
};

class Veiculo {
public:
  void setVeiculo(std::string pveiculo) { veiculo = pveiculo; }

  std::string getVeiculo() { return veiculo; }

private:
  std::string veiculo;
};

class Ativo {
public:
  void setAtivo(int pativo) { ativo = pativo; }

  int getAtivo() { return ativo; }

private:
  int ativo;
};

class Carro : public Veiculo, public MeioTranporte, public Ativo {
public:
  Carro() : modelo(""), fabricacao(0) {} // Construtor padrão

  Carro(std::string pmodelo, // não pode ter tipo e dever ter o mesmo nome do
                             // construtor padrão
        int pfabricacao) {   // Construtor com parâmetros
    modelo = pmodelo;
    fabricacao = pfabricacao;
  }

  void setModelo(std::string pmodelo) {
    // setter para modelo
    modelo = pmodelo;
  }

  void setFabricacao(int pfabricacao) {
    // setter fabricacao
    fabricacao = pfabricacao;
  }

  std::string getModelo() { return modelo; }

  int getFabricacao() { return fabricacao; }

private:
  std::string modelo;
  int fabricacao;
};

int main(int argc, char *argv[]) {
  int i = 0;
  const int max = 3;
  Carro lista[max]; // declara um array com 3 objetos da classe carro
  for (i = 0; i < max; i++) {
    // considerando as opões abaixo, preferi usar array por ser um caso simples
    // e que eu sabia quantos queria
    // Explicações no fim do arquivo
    lista[i] = Carro(); //.carroCtor("a definir", 0);
  }

  // mostrar que os três objetos criados estão acessíveis
  std::cout << "Carros criados: " << '\n';
  std::cout << "Total de carros: " << max << '\n';
  std::cout << "Acessando os carros criados: " << '\n';
  std::cout << "Carro 1: " << lista[0].getModelo() << '\n';
  std::cout << "Carro 2: " << lista[1].getModelo() << '\n';
  std::cout << "Carro 3: " << lista[2].getModelo() << '\n';
  std::cout << '\n';

  // definindo duas variaveis auxiliares para entrada de dados
  std::string _modelo;
  int _fabricacao;

  // definir os modelos e ano de fabricação de cada carro
  std::cout << "Agora, vamos definir os modelos dos carros: " << '\n';
  std::cout << "---Especifique o primeiro carro---" << '\n';
  std::cout << "Modelo: ";
  std::cin >> _modelo;
  lista[0].setModelo(_modelo);
  std::cout << "Ano de fabricação: ";
  std::cin >> _fabricacao;
  lista[0].setFabricacao(_fabricacao);
  std::cout << "---Especifique o segundo carro---" << '\n';
  std::cout << "Modelo: ";
  std::cin >> _modelo;
  lista[1].setModelo(_modelo);
  std::cout << "Ano de fabricação: ";
  std::cin >> _fabricacao;
  lista[1].setFabricacao(_fabricacao);
  std::cout << "---Especifique o terceiro carro---" << '\n';
  std::cout << "Modelo: ";
  std::cin >> _modelo;
  lista[2].setModelo(_modelo);
  std::cout << "Ano de fabricação: ";
  std::cin >> _fabricacao;
  lista[2].setFabricacao(_fabricacao);
  std::cout << '\n';

  // agora vamos mostrar os dados dos carros
  std::cout << "Agora, os dados dos carros são: " << '\n';
  std::cout << "Carro 1: " << lista[0].getModelo() << " - "
            << lista[0].getFabricacao() << '\n';
  std::cout << "Carro 2: " << lista[1].getModelo() << " - "
            << lista[1].getFabricacao() << '\n';
  std::cout << "Carro 3: " << lista[2].getModelo() << " - "
            << lista[2].getFabricacao() << '\n';

  // agora vamos inserir as características de cada carro herdadas das classes
  // Veiculo, MeioTransporte e Ativo
  lista[0].setVeiculo("Carro");
  lista[0].setMeioTransporte("Terrestre");
  lista[0].setAtivo(1);
  lista[1].setVeiculo("Onibus");
  lista[1].setMeioTransporte("Terrestre");
  lista[1].setAtivo(2);
  lista[2].setVeiculo("Caminhão");
  lista[2].setMeioTransporte("Terrestre");
  lista[2].setAtivo(3);

  // agora vamos mostrar os dados dos carros incluindo as características
  // herdadas
  std::cout << "Agora, os dados dos carros são: " << '\n';
  std::cout << "Carro 1: " << lista[0].getModelo() << " - "
            << lista[0].getFabricacao() << " - " << lista[0].getVeiculo()
            << " - " << lista[0].getMeioTransporte() << " - "
            << lista[0].getAtivo() << '\n';
  std::cout << "Carro 2: " << lista[1].getModelo() << " - "
            << lista[1].getFabricacao() << " - " << lista[1].getVeiculo()
            << " - " << lista[1].getMeioTransporte() << " - "
            << lista[1].getAtivo() << '\n';
  std::cout << "Carro 3: " << lista[2].getModelo() << " - "
            << lista[2].getFabricacao() << " - " << lista[2].getVeiculo()
            << " - " << lista[2].getMeioTransporte() << " - "
            << lista[2].getAtivo() << '\n';

  return 0;
}
/*

     * Para criar os objetos dinâmicamente em tempo de execução pode seu usar
     * Vectors, Maps ou Arrays Ambas as abordagens vectos e maps permitem que
     * você crie múltiplos objetos dentro de um loop e os acesse posteriormente
     * usando um identificador numérico que corresponde ao iterador do loop. A
     * escolha entre std::vector e std::map depende de como você pretende
     * acessar e gerenciar esses objetos. Para acesso sequencial ou por índice
     * simples, std::vector é geralmente mais eficiente. Para acesso por uma
     * chave específica (que pode não ser sequencial), std::map é mais adequado.
     * Já arrays Se o número de objetos for fixo e conhecido em tempo de
     * compilação, std::array (ou C-style array) pode ser usado. No entanto,
     * para a maioria dos casos onde o número de objetos pode variar ou é
     * determinado em tempo de execução, std::vector é a escolha mais flexível e
     * idiomática em C++.

 * Sim, você pode fazer a mesma coisa com um array de objetos, mas com uma
 diferença fundamental: arrays (sejam C-style arrays ou `std::array`) têm um
 tamanho fixo que deve ser conhecido em tempo de compilação.

  Isso significa que você precisa decidir quantos objetos você quer criar antes
 de o programa rodar o loop, e não pode adicionar mais objetos ao array depois
 que ele foi declarado.


  Limitações dos Arrays (C-style e `std::array`):
   * Tamanho Fixo: O número de objetos deve ser conhecido em tempo de
 compilação. Você não pode adicionar ou remover objetos dinamicamente.
   * Construtor Padrão: Ao declarar um array de objetos, o construtor padrão
 (sem argumentos) da sua classe é chamado para cada elemento. Se sua classe não
 tiver um construtor padrão, você terá que inicializar os elementos
 explicitamente na declaração (o que é inviável para um loop) ou garantir que um
 construtor padrão exista.

  Conclusão:
  Se o número de objetos for fixo e conhecido em tempo de compilação, std::array
 (ou C-style array) pode ser usado. No entanto, para a maioria dos casos onde o
 número de objetos pode variar ou é determinado em tempo de execução,
 std::vector é a escolha mais flexível e idiomática em C++.
*/
