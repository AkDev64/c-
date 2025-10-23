/*
  EXPLICAÇÃO SOBRE CLASSES ABSTRATAS:

  Agora, a classe `Veiculo` é oficialmente uma classe abstrata.

  Qual o efeito prático?

  Se você compilar e rodar o `47-ClassesAbstratas.cpp`, a saída será
  exatamente a mesma do programa anterior. A mudança não está no que o
  programa faz, mas nas regras que o compilador impõe.

  Para ver o efeito real, tente adicionar a seguinte linha no `main`:
  Veiculo* v = new Veiculo();

  Se você tentar compilar o código com essa linha, o compilador vai gerar um
  ERRO. A mensagem de erro vai dizer algo como "não é possível instanciar
  uma classe abstrata `Veiculo`" porque ela contém "funções virtuais puras".

  Esse erro é a prova de que nosso "contrato" está funcionando. O compilador
  agora proíbe a criação de um `Veiculo` genérico.

  Essa é a essência de uma classe abstrata: ela serve como um molde que não
  pode ser instanciado, apenas herdado e especializado.
*/

#include <iostream>
#include <string>

// As classes base permanecem as mesmas
class MeioTransporte {
public:
  void setMeioTransporte(std::string pMeioTranporte) {
    meioTransporte = pMeioTranporte;
  }
  std::string getMeioTransporte() { return meioTransporte; }

private:
  std::string meioTransporte;
};

class Ativo {
public:
  void setAtivo(int pativo) { ativo = pativo; }
  int getAtivo() { return ativo; }

private:
  int ativo;
};

// --- MUDANÇA 1: Modificando a classe Veiculo ---
class Veiculo {
public:
  // Adicionando um destrutor virtual. Essencial para o polimorfismo!
  virtual ~Veiculo() {
    std::cout << "(Destrutor do Veiculo chamado)" << std::endl;
  }

  void setVeiculo(std::string pveiculo) { veiculo = pveiculo; }
  std::string getVeiculo() { return veiculo; }

  // Adicionando uma função virtual PURA para ser sobrescrita
  // Isso torna a classe Veiculo abstrata.
  virtual void exibirDados() = 0;

private:
  std::string veiculo;
};

// A classe Carro agora sobrescreve a função virtual
class Carro : public Veiculo, public MeioTransporte, public Ativo {
public:
  Carro(std::string pmodelo, int pfabricacao) {
    modelo = pmodelo;
    fabricacao = pfabricacao;
  }

  // --- MUDANÇA 2: Sobrescrevendo a função da classe base ---
  // A palavra "override" garante que estamos de fato sobrescrevendo
  // uma função virtual da classe base. É uma boa prática.
  void exibirDados() override {
    std::cout << "Carro: " << modelo << " | Ano: " << fabricacao << std::endl;
  }

  std::string getModelo() { return modelo; }
  int getFabricacao() { return fabricacao; }

private:
  std::string modelo;
  int fabricacao;
};

// --- MUDANÇA 3: Adicionando uma nova classe para demonstrar o polimorfismo ---
class Moto : public Veiculo, public MeioTransporte, public Ativo {
public:
  Moto(int pcilindradas) { cilindradas = pcilindradas; }

  void exibirDados() override {
    std::cout << "Moto: " << cilindradas << "cc" << std::endl;
  }

private:
  int cilindradas;
};

// --- MUDANÇA 4: A função main agora demonstra o polimorfismo ---
int main(int argc, char *argv[]) {
  // Criamos um array de PONTEIROS da classe base
  Veiculo *lista[3];

  std::cout << "--- Criando objetos ---" << std::endl;
  // Instanciamos objetos das classes derivadas com 'new'
  lista[0] = new Carro("Fusca", 1980);
  lista[1] = new Moto(600);
  lista[2] = new Carro("Opala", 1988);
  std::cout << std::endl;

  std::cout << "--- Exibindo dados de forma polimorfica ---" << std::endl;
  // Chamamos a mesma função para todos, mas o comportamento é diferente!
  for (int i = 0; i < 3; i++) {
    lista[i]->exibirDados(); // A mágica do polimorfismo acontece aqui
  }
  std::cout << std::endl;

  std::cout << "--- Liberando memoria ---" << std::endl;
  // É crucial liberar a memória que foi alocada com 'new'
  for (int i = 0; i < 3; i++) {
    delete lista[i];
  }

  return 0;
}
