/*
  Revisão: Ponteiros vs. Referências
  Explicação solicitada pelo Adriano em 27/10/2025.

  ### Referências (`&`)

  - **O que é?** Uma referência é um **apelido** (um alias) para uma variável que já existe. Não é uma nova variável, é apenas um outro nome para a mesma área de memória.
  - **Analogia:** Pense em "Robert" e "Bob". São dois nomes diferentes para a mesma pessoa. Se você fala com Bob, está falando com Robert.
  - **Regras principais:**
    1.  **Deve ser inicializada:** Você precisa dizer para qual variável ela será um apelido no momento em que a cria.
    2.  **Nunca é nula:** Ela sempre se refere a um objeto válido.
    3.  **Não pode ser redirecionada:** Uma vez que uma referência é o apelido de `varA`, ela será sempre o apelido de `varA`.

  ### Ponteiros (`*`)

  - **O que é?** Um ponteiro é uma **variável que armazena um endereço de memória**. Ele "aponta" para onde outra variável está.
  - **Analogia:** Pense em um papel onde você anota o endereço da casa de alguém. O papel em si não é a casa, mas ele te diz onde encontrá-la.
  - **Regras principais:**
    1.  **Pode ser nulo (`nullptr`):** Pode não apontar para lugar nenhum.
    2.  **Pode ser redirecionado:** Pode passar a apontar para outra variável.
    3.  **Requer desreferência:** Para acessar o valor no endereço apontado, você usa o operador `*`.

  ### Quando usar um ou outro?

  - **Use Referências (`&`) quando:**
    - Você quer passar um objeto para uma função sem o custo de uma cópia (pass-by-reference) e tem certeza de que o objeto existe.
    - Regra geral: Prefira referências a ponteiros sempre que possível, pois são mais seguras e a sintaxe é mais limpa.

  - **Use Ponteiros (`*`) quando:**
    - A "ausência de um objeto" é uma opção válida (use `nullptr`).
    - Você precisa mudar para o que o ponteiro aponta.
    - Você está gerenciando memória dinamicamente no heap (`new`/`delete`).
*/

#include <iostream>

// Função que recebe um parâmetro por referência.
// A modificação afeta a variável original.
void incrementa(int& valor) {
    valor++; // Modifica diretamente o objeto original
}

// Função que recebe um parâmetro por ponteiro.
// A modificação também afeta a variável original.
void defineParaZero(int* ptr) {
    if (ptr != nullptr) { // Sempre verifique se o ponteiro não é nulo!
        *ptr = 0;
    }
}

int main() {
    // --- Exemplo com Referências ---
    std::cout << "--- Trabalhando com Referências ---" << std::endl;
    int numero = 10;
    int& refNumero = numero; // 'refNumero' é um apelido para 'numero'

    std::cout << "Valor original (numero): " << numero << std::endl;
    std::cout << "Valor via referência (refNumero): " << refNumero << std::endl;

    refNumero = 20; // Modificando a referência...
    std::cout << "Valor original após modificar a referência: " << numero << std::endl;

    // Chamando função com passagem por referência
    incrementa(numero);
    std::cout << "Valor após chamar incrementa(numero): " << numero << std::endl;

    // Erro de compilação: Referência deve ser inicializada
    // int& refSemInicializacao;

    // --- Exemplo com Ponteiros ---
    std::cout << "
--- Trabalhando com Ponteiros ---" << std::endl;
    int outraVariavel = 50;
    int* ptr = &outraVariavel; // 'ptr' armazena o endereço de 'outraVariavel'

    std::cout << "Endereço de 'outraVariavel': " << &outraVariavel << std::endl;
    std::cout << "Valor de 'ptr' (o endereço que ele guarda): " << ptr << std::endl;
    std::cout << "Valor apontado por 'ptr' (*ptr): " << *ptr << std::endl;

    *ptr = 60; // Modificando o valor no endereço apontado
    std::cout << "Valor de 'outraVariavel' após modificar via ponteiro: " << outraVariavel << std::endl;

    // Ponteiros podem ser redirecionados
    int maisUmaVariavel = 100;
    ptr = &maisUmaVariavel;
    std::cout << "Ponteiro agora aponta para o valor: " << *ptr << std::endl;

    // Ponteiros podem ser nulos
    ptr = nullptr;
    std::cout << "Valor do ponteiro após ser definido como nullptr: " << ptr << std::endl;

    // Chamando função com passagem por ponteiro
    defineParaZero(&maisUmaVariavel);
    std::cout << "Valor de 'maisUmaVariavel' após chamar defineParaZero: " << maisUmaVariavel << std::endl;


    return 0;
}

/*
  Definição Verbal Concisa (para fixação):

  - Uma REFERÊNCIA é um APELIDO. Ela se torna outro nome para a mesma variável.
    A sintaxe é mais limpa e ela não pode ser nula.

  - Um PONTEIRO é uma variável que guarda um ENDEREÇO. Ele aponta para onde
    outra variável está. A sintaxe exige o uso de '*' e '->', e ele pode ser nulo.

  A diferença fundamental: a referência **É** o objeto, enquanto o ponteiro
  **APONTA PARA** o objeto.
*/