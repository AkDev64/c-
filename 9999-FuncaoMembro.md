# Funções Virtuais e Polimorfismo em C++

Funções virtuais são o mecanismo que o C++ utiliza para implementar o **polimorfismo em tempo de execução**. Isso permite tratar objetos de diferentes classes derivadas de forma uniforme, através de um ponteiro ou referência da classe base.

O exemplo prático no arquivo `46-Polimorfismo.cpp` ilustra perfeitamente este conceito.

---

### Os 3 Ingredientes do Polimorfismo

Para que o polimorfismo funcione, três condições precisam ser atendidas:

1.  **Hierarquia de Classes (Herança):** É necessário ter uma classe base e uma ou mais classes que herdam dela.
    *   *No exemplo:* `Carro` e `Moto` herdam de `Veiculo`.

2.  **Função Virtual na Classe Base:** A função que terá o comportamento polimórfico deve ser declarada com a palavra-chave `virtual` na classe base.
    ```cpp
    // Na classe Veiculo
    class Veiculo {
    public:
        virtual void exibirDados() { /*...*/ }
        // ...
    };
    ```
    A palavra-chave `virtual` instrui o compilador a gerar o código necessário para decidir em tempo de execução qual é a versão correta da função a ser chamada (a da classe base ou a de alguma classe derivada).

3.  **Uso de Ponteiros ou Referências da Classe Base:** Para invocar o comportamento polimórfico, os objetos das classes derivadas devem ser acessados através de ponteiros ou referências da classe base.
    ```cpp
    // Na função main
    Veiculo* lista[3]; // Um array de ponteiros para Veiculo
    lista[0] = new Carro("Fusca", 1980); // Ponteiro de Veiculo aponta para um objeto Carro
    lista[1] = new Moto(600);            // Ponteiro de Veiculo aponta para um objeto Moto
    ```

---

### A Mágica em Ação

O poder do polimorfismo se torna evidente quando chamamos o método virtual através do ponteiro da classe base:

```cpp
for (int i = 0; i < 3; i++) {
    // A mesma chamada de função...
    lista[i]->exibirDados();
    // ...resulta em comportamentos diferentes!
}
```

Mesmo que cada item do array `lista` seja do tipo `Veiculo*`, o C++ verifica o tipo *real* do objeto para o qual o ponteiro aponta em tempo de execução e chama a implementação correspondente de `exibirDados()`:
*   Se `lista[i]` aponta para um `Carro`, `Carro::exibirDados()` é chamada.
*   Se `lista[i]` aponta para uma `Moto`, `Moto::exibirDados()` é chamada.

---

### A Importância do Destrutor Virtual

Quando trabalhamos com alocação dinâmica (`new`) e polimorfismo, é crucial que o destrutor da classe base seja `virtual`.

```cpp
class Veiculo {
public:
    virtual ~Veiculo() { /* ... */ }
    // ...
};
```

Isso garante que, ao executar `delete lista[i]`, o destrutor da classe derivada (`~Carro()` ou `~Moto()`) seja chamado primeiro, seguido pelo destrutor da classe base (`~Veiculo()`). Sem o `virtual`, apenas o destrutor da classe base (`~Veiculo()`) seria chamado, o que poderia causar vazamento de recursos (memory leak) alocados pela classe derivada.

---

### Por que usar Ponteiros? O "Fatiamento do Objeto"

O uso de ponteiros (ou referências) é obrigatório para o polimorfismo para evitar um problema chamado **Object Slicing** (Fatiamento do Objeto). Se você tentasse armazenar os objetos `Carro` e `Moto` diretamente em um array de `Veiculo`, toda a informação extra que não pertence a `Veiculo` (como `modelo` em `Carro` ou `cilindradas` em `Moto`) seria "fatiada" e perdida. O ponteiro apenas armazena o endereço, mantendo o objeto original intacto na memória.
