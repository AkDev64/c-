# Casos de Uso Práticos para `std::unique_ptr`

Entender o mecanismo de `std::unique_ptr` e `std::move` é o primeiro passo. O passo seguinte, e mais importante, é entender "por que" e "onde" usar esse recurso.

`unique_ptr` é a ferramenta ideal para qualquer situação onde você precisa alocar memória dinamicamente (com `new`) e deseja estabelecer uma política de **propriedade única, clara e segura** sobre essa memória. A limpeza (chamada ao `delete`) se torna automática, prevenindo vazamentos de memória.

Abaixo estão os dois cenários práticos mais comuns.

---

### Cenário 1: Funções "Fábrica" (Factory Functions)

Uma função "fábrica" é uma função cujo trabalho é criar e retornar objetos. Frequentemente, o tipo exato do objeto criado varia, então a função retorna um ponteiro para uma classe base comum. O desafio é transferir a posse do objeto recém-criado para quem chamou a função.

#### O Jeito Antigo (Perigoso, com ponteiros brutos)

```cpp
// A função retorna um ponteiro bruto.
Veiculo* criarVeiculo(Tipo tipo) {
    if (tipo == CARRO) {
        return new Carro(); // O chamador agora é responsável por este 'new'.
    }
    if (tipo == MOTO) {
        return new Moto(); // O chamador também é responsável por este.
    }
    return nullptr;
}

// Código que usa a fábrica:
void usarVeiculos() {
    Veiculo* meu_veiculo = criarVeiculo(CARRO);
    // ... usa o veículo ...

    // PROBLEMA: E se eu esquecer a linha abaixo? Ou se uma exceção ocorrer?
    // Resultado: Vazamento de memória (memory leak).
    delete meu_veiculo;
}
```

#### O Jeito Moderno (Seguro, com `std::unique_ptr`)

`unique_ptr` torna a transferência de posse explícita e segura. A função retorna o `unique_ptr`, e quem o recebe se torna o novo e único dono. A limpeza é garantida.

```cpp
// A função retorna um unique_ptr, transferindo a posse.
std::unique_ptr<Veiculo> criarVeiculo(Tipo tipo) {
    if (tipo == CARRO) {
        return std::make_unique<Carro>();
    }
    if (tipo == MOTO) {
        return std::make_unique<Moto>();
    }
    return nullptr;
}

// Código que usa a fábrica:
void usarVeiculos() {
    std::unique_ptr<Veiculo> meu_veiculo = criarVeiculo(CARRO);
    // ... usa o veículo ...

    // NENHUM 'delete' é necessário!
    // A memória é liberada automaticamente quando 'meu_veiculo' sai de escopo.
}
```

---

### Cenário 2: Polimorfismo em Contêineres da STL

Este é talvez o uso mais frequente de `unique_ptr`. Para ter uma coleção de objetos polimórficos (ex: `Carros` e `Motos` em uma lista de `Veiculos`), precisamos armazenar ponteiros. `unique_ptr` é a forma segura de fazer isso.

#### O Jeito Antigo (Perigoso, com ponteiros brutos)

```cpp
std::vector<Veiculo*> veiculos;
veiculos.push_back(new Carro());
veiculos.push_back(new Moto());

// ... usa o vetor ...

// PROBLEMA: No final, é obrigatório percorrer o vetor e deletar cada
// ponteiro manualmente. É um processo tedioso e muito propenso a erros.
for (Veiculo* v : veiculos) {
    delete v;
}
veiculos.clear();
```

#### O Jeito Moderno (Seguro, com `std::unique_ptr`)

O contêiner se torna o "dono" de todos os objetos. Quando o contêiner é destruído, ele garante que todos os objetos que ele possui também sejam destruídos.

```cpp
// Um vetor que GERENCIA a posse dos Veiculos.
std::vector<std::unique_ptr<Veiculo>> veiculos;

// Adicionamos novos ponteiros. A posse é transferida para o vetor.
// A partir do C++14, `push_back` tem uma sobrecarga que usa `std::move` implicitamente.
veiculos.push_back(std::make_unique<Carro>());
veiculos.push_back(std::make_unique<Moto>());

// ... usa o vetor ...

// NADA a fazer no final!
// Quando o vetor 'veiculos' sai de escopo, ele chama o destrutor de cada
// unique_ptr, que por sua vez chama 'delete' em cada Carro e Moto.
```

Em resumo, `unique_ptr` é a ferramenta padrão sempre que um objeto ou recurso precisa ter um **único dono** e seu tempo de vida deve ser gerenciado automaticamente.
