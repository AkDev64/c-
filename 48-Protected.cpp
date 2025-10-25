/*
  EXPLICAÇÃO SOBRE PROTECTED:

  Analogia dos membros de uma classe como cômodos de uma casa:

  - `public`: A sala de estar. Qualquer um (o `main`, outra classe, etc.) pode
  entrar e interagir.
  - `private`: Seu diário pessoal, trancado em uma gaveta. Apenas você (a
  própria classe) pode acessar. Nem mesmo seus filhos (classes derivadas) podem
  ler.
  - `protected`: A caixa de ferramentas da família na garagem. Apenas você (a
  classe) e seus filhos (as classes derivadas) podem usar as ferramentas. Um
  estranho da rua (o `main`, outra classe) não pode entrar e pegar um martelo.

  Em resumo: `protected` é como `private`, mas dá acesso também às classes que
  herdam dela.
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

class Veiculo {
public:
  // Construtor que inicializa o membro protegido.
  Veiculo(std::string tipo) : tipo_veiculo(tipo) {}

  virtual ~Veiculo() {
    std::cout << "(Destrutor do Veiculo chamado para " << tipo_veiculo << ")"
              << std::endl;
  }

  // A função virtual pura continua a mesma.
  virtual void exibirDados() = 0; // funções virtuais sempre tem esse = 0 ? sim

  // --- MUDANÇA 1: Usando 'protected' ---
protected:
  // Este membro agora é acessível para Veiculo e suas classes derivadas (Carro,
  // Moto).
  std::string tipo_veiculo;
};

class Carro : public Veiculo, public MeioTransporte, public Ativo {
public:
  // --- MUDANÇA 2: Chamando o construtor da classe base ---
  Carro(std::string pmodelo, int pfabricacao)
      // Passa o tipo para o construtor de Veiculo
      : Veiculo("Automovel") {
    modelo = pmodelo;
    fabricacao = pfabricacao;
  }

  void exibirDados() override {
    // --- MUDANÇA 3: Acessando o membro 'protected' diretamente ---
    std::cout << "Tipo: " << tipo_veiculo << " | Carro: " << modelo
              << " | Ano: " << fabricacao << std::endl;
  }

private:
  std::string modelo;
  int fabricacao;
};

class Moto : public Veiculo, public MeioTransporte, public Ativo {
public:
  // Chamando o construtor da classe base
  Moto(int pcilindradas) : Veiculo("Motocicleta") {
    cilindradas = pcilindradas;
  }

  void exibirDados() override {
    // Acessando o membro 'protected' diretamente
    std::cout << "Tipo: " << tipo_veiculo << " | Moto: " << cilindradas << "cc"
              << std::endl;
  }

private:
  int cilindradas;
};

int main(int argc, char *argv[]) {
  Veiculo *lista[3];

  std::cout << "--- Criando objetos ---" << std::endl;
  lista[0] = new Carro("Fusca", 1980);
  lista[1] = new Moto(600);
  lista[2] = new Carro("Opala", 1988);
  std::cout << std::endl;

  std::cout << "--- Exibindo dados de forma polimorfica ---" << std::endl;
  for (int i = 0; i < 3; i++) {
    lista[i]->exibirDados();
  }
  std::cout << std::endl;

  std::cout << "--- Liberando memoria ---" << std::endl;
  for (int i = 0; i < 3; i++) {
    delete lista[i];
  }

  return 0;
}
