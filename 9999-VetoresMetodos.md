# Métodos aplicáveis em Vetores

A classe vector em C++ fornece diversos métodos para manipular coleções dinâmicas de elementos, incluindo métodos para adicionar elementos como push_back(), emplace_back(), insert(), e emplace(); métodos para acessar elementos como at(), operator[], front() e back(); métodos para remover elementos como pop_back(), erase(), clear(), e swap(); métodos para gerenciar o espaço do vetor como reserve() e resize(); e métodos para obter informações sobre o vetor, como size(), capacity(), empty() e data(). 
Métodos de Adição de Elementos

    push_back(value): Adiciona um elemento ao final do vetor. 

emplace_back(args...): Constrói um elemento diretamente no final do vetor. 
insert(position, value): Insere um elemento na posição especificada. 
emplace(position, args...): Constrói um elemento diretamente na posição especificada. 
assign(): Apaga os elementos existentes e copia os novos elementos especificados para o vetor. 

Métodos de Acesso a Elementos 

    operator: Retorna uma referência ao elemento na posição index.
    at(index): Retorna uma referência ao elemento na posição index, com verificação de limites (gera exceção se fora do limite).
    front(): Retorna uma referência ao primeiro elemento do vetor.
    back(): Retorna uma referência ao último elemento do vetor. 

Métodos de Remoção de Elementos 

    pop_back(): Remove o último elemento do vetor.
    erase(position): Remove o elemento na posição especificada.
    erase(first, last): Remove um intervalo de elementos do vetor.
    clear(): Remove todos os elementos do vetor.
    swap(other_vector): Troca os elementos de dois vetores. 

Métodos de Gerenciamento e Informações 

    size(): Retorna o número de elementos no vetor.
    empty(): Retorna true se o vetor estiver vazio, false caso contrário.
    reserve(n): Solicita que o vetor tenha um tamanho mínimo de capacidade.
    resize(n): Altera o tamanho do vetor.
    capacity(): Retorna a capacidade atual do vetor.
    data(): Retorna um ponteiro para o início do array interno de elementos.
