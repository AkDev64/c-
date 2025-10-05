# Sobrecarga de funções em c++

Sobrecarga de funções em C++ é a capacidade de definir múltiplas funções com o mesmo nome no mesmo escopo, mas com diferentes listas de parâmetros (tipos, número ou ordem). Isso permite que uma única operação seja realizada com diferentes conjuntos de dados, melhorando a legibilidade do código, pois evita a criação de nomes de funções distintos para tarefas semelhantes. O compilador escolhe qual função sobrecarregada chamar com base na correspondência exata ou mais próxima dos argumentos fornecidos na chamada da função. 
Como funciona a sobrecarga?

    Parâmetros diferentes:
    Você pode ter duas funções com o mesmo nome, mas uma recebe um int e a outra um double. 

Número diferente de parâmetros:
Outra forma é ter uma função que recebe dois argumentos e outra que recebe três. 
Ordem diferente dos parâmetros:
Funções com o mesmo nome e tipos de parâmetros, mas em uma ordem diferente, também podem ser sobrecarregadas. 

Exemplo Prático
Imagine uma função print: 

    Uma versão print(std::string) que imprime um texto.
    Outra versão print(int) que imprime um número inteiro. 

Quando você chama print("Olá"), o compilador sabe que deve executar a função que recebe uma string. Se você chama print(123), ele executará a função que recebe um inteiro. 
Benefícios

    Facilita a leitura:
    Evita a necessidade de memorizar vários nomes de funções para operações similares. 

Polimorfismo estático:
É um exemplo de polimorfismo, onde o compilador "escolhe" a definição correta da função em tempo de compilação. 
Reutilização de código:
Permite reutilizar o mesmo nome de função para diferentes funcionalidades relacionadas. 

O que não pode ser sobrecarregado? 

    Tipos de retorno diferentes: Funções com o mesmo nome e mesmos parâmetros, mas com tipos de retorno diferentes, não podem ser sobrecarregadas. A sobrecarga se baseia na assinatura da função (nome e parâmetros), e não apenas no tipo de retorno.Sobrecarga de funções em C++ é a capacidade de definir múltiplas funções com o mesmo nome no mesmo escopo, mas com diferentes listas de parâmetros (tipos, número ou ordem). Isso permite que uma única operação seja realizada com diferentes conjuntos de dados, melhorando a legibilidade do código, pois evita a criação de nomes de funções distintos para tarefas semelhantes. O compilador escolhe qual função sobrecarregada chamar com base na correspondência exata ou mais próxima dos argumentos fornecidos na chamada da função. 
Como funciona a sobrecarga?

    Parâmetros diferentes:
    Você pode ter duas funções com o mesmo nome, mas uma recebe um int e a outra um double. 

Número diferente de parâmetros:
Outra forma é ter uma função que recebe dois argumentos e outra que recebe três. 
Ordem diferente dos parâmetros:
Funções com o mesmo nome e tipos de parâmetros, mas em uma ordem diferente, também podem ser sobrecarregadas. 

Exemplo Prático
Imagine uma função print: 

    Uma versão print(std::string) que imprime um texto.
    Outra versão print(int) que imprime um número inteiro. 

Quando você chama print("Olá"), o compilador sabe que deve executar a função que recebe uma string. Se você chama print(123), ele executará a função que recebe um inteiro. 
Benefícios

    Facilita a leitura:
    Evita a necessidade de memorizar vários nomes de funções para operações similares. 

Polimorfismo estático:
É um exemplo de polimorfismo, onde o compilador "escolhe" a definição correta da função em tempo de compilação. 
Reutilização de código:
Permite reutilizar o mesmo nome de função para diferentes funcionalidades relacionadas. 

O que não pode ser sobrecarregado? 

    Tipos de retorno diferentes: Funções com o mesmo nome e mesmos parâmetros, mas com tipos de retorno diferentes, não podem ser sobrecarregadas. A sobrecarga se baseia na assinatura da função (nome e parâmetros), e não apenas no tipo de retorno.

texto sugerido pelo GEMINI
