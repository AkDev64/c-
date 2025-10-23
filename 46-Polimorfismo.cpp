/*
 *   Com polimorfismo, você simplesmente diz: veiculo->exibirDados();. O C++ se
 encarrega de chamar a versão correta da função (Carro::exibirDados ou
 Moto::exibirDados) em tempo de execução.

  Para isso acontecer, precisamos de 3 ingredientes:
   1. Uma hierarquia de classes (que já temos: Carro é um Veiculo).
   2. Uma função na classe base declarada como `virtual`.
   3. Usar ponteiros ou referências para a classe base.

  Plano de Modificação para o Código

  Para aplicar isso no seu novo arquivo, vou fazer o seguinte:

   1. Adicionar uma nova classe `Moto`, que também herda de Veiculo, para termos
 tipos diferentes de veículos.
   2. Adicionar uma função `virtual void exibirDados()` na classe Veiculo. Isso
 "liga" o polimorfismo para essa função.
   3. Sobrescrever (`override`) a função exibirDados() nas classes Carro e Moto
 para que cada uma mostre suas informações específicas.
   4. Adicionar um Destrutor Virtual na classe Veiculo (virtual ~Veiculo() {}).
 Isso é essencial para garantir que a memória seja liberada corretamente quando
 usamos polimorfismo com new e delete.
   5. Alterar a `main()` para:
       * Criar um array de ponteiros da classe base: Veiculo* lista[3];.
       * Instanciar Carros e Motos com new.
       * Percorrer a lista chamando o método exibirDados() de forma polimórfica.
       * Liberar a memória no final com delete.

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

  // Adicionando uma função virtual para ser sobrescrita
  virtual void exibirDados() {
    std::cout << "Dados de um veiculo generico." << std::endl;
  }

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

Essa é a pergunta -
    chave para entender polimorfismo em C++.É uma excelente dúvida !

    A resposta curta é : sem ponteiros,
    o polimorfismo não funciona em C++ por causa de um fenômeno chamado
    "Fatiamento do Objeto"(Object Slicing)
        .

    Vamos detalhar.

    O Problema : O que acontece SEM ponteiros
    ?

    Imagine que,
    em vez de um array de ponteiros,
    você criasse um array de objetos Veiculo :

    1 // O JEITO ERRADO (NÃO POLIMÓRFICO)
    2 Veiculo
    lista[3]; // Um array que reserva espaço para 3 objetos do tipo Veiculo.

O compilador aloca na memória um espaço fixo para 3 objetos
    Veiculo.Um Veiculo só tem um membro : std::string veiculo.

                                          Agora,
    o que acontece se você tenta fazer isso ?

                                            1 Carro meuCarro("Fusca", 1980);
2 lista[0] = meuCarro; // Tenta colocar um Carro num espaço de Veiculo

Um objeto Carro é maior que um objeto Veiculo,
    pois ele tem também modelo e fabricacao.Ele não "cabe" no espaço de Veiculo
        .

    O C++ "resolve" isso fatiando o objeto
    : ele copia apenas a parte do Carro
          que também é um Veiculo e joga fora o resto(modelo, fabricacao, etc.)
        .

      Resultado : Dentro do array lista,
    você não tem mais um Carro
        .Você tem um objeto que é apenas e somente um `Veiculo`
        .Toda a informação extra foi perdida
        .

    Quando você chama lista[0]
        .exibirDados(),
    o compilador só enxerga um Veiculo,
    então ele chama Veiculo::exibirDados()
        .A ligação com o Carro original foi cortada.

    A Solução : Por que ponteiros e new funcionam
    ?

    Agora,
    vamos ver o jeito certo :

    1 // O JEITO CERTO (POLIMÓRFICO)
    2 Veiculo
        *lista[3]; // Um array que reserva espaço para 3 ENDEREÇOS DE MEMÓRIA.

A grande diferença é que este array não armazena os objetos em si.Ele
    armazena ponteiros,
    que são apenas "endereços" para onde os objetos estão na memória.

    1. `new Carro(...)`: Quando você faz isso,
    você está dizendo
    : "Crie um objeto Carro completo, com todas as suas partes, em algum
      lugar livre da memória(a 'heap') e me dê o endereço dele."

      2. `lista[0] = ...`
    : Você pega esse endereço e o armazena no array de ponteiros.

      O objeto `Carro` original continua intacto na memória,
         com todas as suas partes
             .O ponteiro Veiculo *na lista simplesmente "aponta" para ele
             .

         Quando você chama lista[0]
             ->exibirDados(),
         o C++ faz o seguinte : 1. Pega o ponteiro no lista[0]
             .2. Segue o endereço até o objeto original na memória
             .3. Vê que o objeto naquele endereço é,
         na verdade, um Carro.4. Como exibirDados() é virtual,
         ele diz : "Ah, o tipo real deste objeto é Carro, então vou chamar a "
                   "versão Carro::exibirDados()."

                   -- -

                   Resumo em uma Analogia

                       *Array de Objetos(`Veiculo lista[3]`)
    : Uma caixa de sapatos
          .Você só pode guardar coisas que caibam em uma caixa de sapatos
          .Se tentar guardar uma bota de cano alto(objeto Carro),
         você tem que cortar o cano fora(fatiamento)
             .*Array de Ponteiros(`Veiculo * lista[3]`)
    : Uma agenda de contatos.Você não guarda as pessoas na agenda,
         só o endereço delas
             .Um endereço pode apontar para uma casa
         pequena(objeto Veiculo) ou para um prédio enorme(objeto Carro)
             .O endereço ocupa o mesmo espaço na agenda,
         mas te leva ao lugar certo,
         com seu tamanho original.

         Em resumo : usamos ponteiros(e new) para evitar o
                     "fatiamento" e garantir que o programa saiba o tipo real
                     do objeto em tempo de execução,
         permitindo que as funções virtuais façam sua mágica.
