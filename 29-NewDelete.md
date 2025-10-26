# New and delete Operators in C++ For Dynamic Memory
Last Updated : 30 Jul, 2025

In C++, stack memory is automatically allocated for variables at compile time and has a fixed size. For greater control and flexibility, dynamic memory allocation on the heap is used, allowing manual allocation with new and deallocation with delete.

It allows the program to request memory from the heap at runtime using the new operator and release it using the delete operator. This is useful when the size of required memory isn’t known at compile time, such as for variable-sized arrays or dynamic data structures like linked lists and trees.

    The new operator in C++ allocates memory from the Free Store (a portion of the heap). If enough memory is available, it initializes the memory with a default value based on its type and returns the address of the allocated memory

Example:

```
#include <iostream>

#include <memory>

using namespace std;


int main() {


    // Declared a pointer to store

    // the address of the allocated memory

    int *nptr;

    

    // Allocate and initialize memory

    nptr = new int(6);


    // Print the value

    cout << *nptr << endl;


    // Print the address of memory

    // block

    cout << nptr;

    return 0;

}


Output

6
0xb52dc20
```

Allocate Block of Memory (Array)

A new operator is also used to dynamically allocate a block (an array) of memory of given data type as shown below:

new data_type[n];

This statement dynamically allocates memory for n elements of given data_type. Arrays can also be initialized during allocation.

Example:

```
#include <iostream>

#include <memory>

using namespace std;


int main() {


    // Declared a pointer to store

    // the address of the allocated memory

    int *nptr;

    

    // Allocate and initialize array of

    // integer with 5 elements

    nptr = new int[5]{1, 2, 3, 4, 5};


    // Print array

    for (int i = 0; i < 5; i++)

        cout << nptr[i] << " ";

    return 0;

}

```

Output

1 2 3 4 5 

What if enough memory is not available during runtime?

If enough memory is not available in the heap to allocate, the new request indicates failure by throwing an exception of type std::bad_alloc, unless "nothrow" is used with the new operator, in which case it returns a nullptr pointer. Therefore, it may be a good idea to check for the pointer variable produced by the new before using its program. 

```
int *p = new (nothrow) int;
if (!p) {
    cout << "Memory allocation failed\n";
}

```
delete Operator

In C++, delete operator is used to release dynamically allocated memory. It deallocates memory that was previously allocated with new.
Syntax

delete ptr;

where, ptr is the pointer to the dynamically allocated memory.

To free the dynamically allocated array pointed by pointer variable, use the following form of delete:

delete[] arr;

Example:

```
#include <iostream>

using namespace std;


int main() {

    int *ptr = NULL;


    // Request memory for integer variable

    // using new operator

    ptr = new int(10);

    if (!ptr) {

        cout << "allocation of memory failed";

        exit(0);

    }


    cout << "Value of *p: " << *ptr << endl;


    // Free the value once it is used

    delete ptr;

    

    // Allocate an array

    ptr = new int[3];

    ptr[2] = 11;

    ptr[1] = 22;

    ptr[0] = 33;

    cout << "Array: ";

    for (int i = 0; i < 3; i++)

        cout << ptr[i] << " ";


    // Deallocate when done

    delete[] ptr;

    

    return 0;

}

```


Output

Value of *p: 10
Array: 33 22 11 

Errors Associated with Dynamic Memory

As powerful as dynamic memory allocation is it is also prone to one of the worst errors in C++. Major ones are:
Memory Leaks

Memory leak is a situation where the memory allocated for a particular task remains allocated even after it is no longer needed. Moreover, if the address to the memory is lost, then it will remain allocated till the program runs.

Solution: Use smart pointers whenever possible. They automatically deallocate when goes out of scope.
Dangling Pointers

Dangling pointers are created when the memory pointed by the pointer is accessed after it is deallocated, leading to undefined behaviour (crashes, garbage data, etc.).

Solution: Initialize pointers with nullptr and assign nullptr again when deallocated.
Double Deletion

When delete is called on the same memory twice, leading to crash or corrupted program.

Solution: assign nullptr to the memory pointer when deallocated.
Mixing new/delete with malloc()/free()

C++ supports the C style dynamic memory allocation using malloc(), calloc(), free(), etc. But these functions are not compatible. It means that we cannot allocate memory using new and delete it using free(). Same for malloc() and delete.
Placement new

Placement new is a variant of new operator. Normal new operator both allocates memory and constructs an object in that memory. On the other hand, the placement new separates these actions. It allows the programmer to pass a pre-allocated memory block and construct an object in that specific memory.

---

## Explicação Conceitual: Stack vs. Heap

Para entender `new` e `delete`, o conceito mais importante é a diferença entre as duas principais áreas de memória que um programa C++ utiliza: a **Stack** (Pilha) e a **Heap** (Monte).

### 1. A Stack (Memória Automática)

*   **O que é?** É a memória padrão para suas variáveis locais e parâmetros de função. É onde as coisas "vão por padrão".
    ```cpp
    void minhaFuncao() {
        int x = 10; // 'x' é criado na Stack.
        MinhaClasse obj; // 'obj' também é criado na Stack.
    }
    ```
*   **Como funciona?** O gerenciamento da memória é **automático** e muito rápido. Quando uma variável sai de escopo (por exemplo, a função termina), sua memória é instantaneamente e automaticamente liberada.
*   **Limitação Principal:** O tamanho de tudo que vai na Stack deve ser conhecido em tempo de compilação. Isso a torna inadequada para dados cujo tamanho só é conhecido durante a execução do programa (como um array cujo tamanho é definido pelo usuário).

### 2. A Heap (Memória Dinâmica ou "Free Store")

*   **O que é?** É uma grande reserva de memória que está disponível para ser usada pelo programa de forma flexível durante sua execução.
*   **Como funciona?** O gerenciamento da memória é **manual**. Você, o programador, é responsável por:
    1.  **Pedir** um pedaço da memória quando precisar.
    2.  **Devolver** esse pedaço quando não for mais necessário.
*   **Vantagem Principal:** Permite alocar blocos de memória de tamanho dinâmico (decidido em tempo de execução) e permite que esses dados "sobrevivam" fora do escopo em que foram criados.

### `new` e `delete`: As Ferramentas para Gerenciar a Heap

*   `new`: É o operador que você usa para **pedir** (alocar) memória da Heap. Ele prepara o espaço solicitado, chama o construtor do objeto (se for um objeto de classe) e retorna um **ponteiro** contendo o endereço da memória alocada.

*   `delete`: É o operador que você usa para **devolver** (desalocar) a memória para a Heap, tornando-a disponível para uso futuro.

> **A Regra de Ouro:** Para cada `new` bem-sucedido, deve haver uma chamada `delete` correspondente. Esquecer de chamar `delete` causa um **vazamento de memória (memory leak)** — a memória fica "presa" e não pode ser reutilizada até o programa terminar.

### `new[]` e `delete[]`: A Versão para Arrays

Quando você aloca um array (um bloco de múltiplos elementos) dinamicamente, você deve usar as versões de array dos operadores.

*   `new T[N]`: Aloca memória para `N` objetos do tipo `T` e retorna um ponteiro para o primeiro elemento.
*   `delete[]`: Libera um bloco de memória alocado com `new[]`. O `[]` é crucial, pois garante que o destrutor seja chamado para *cada um* dos `N` objetos no array antes de liberar a memória.

**Exemplo Prático (do arquivo `29-NewDelete.cpp`):**

```cpp
int n;
std::cin >> n;
int* ptr = new int[n]; // Pede espaço para 'n' inteiros na HEAP.
// ... usa o array ...
delete[] ptr; // Devolve o bloco inteiro de 'n' inteiros para a HEAP.
```

### Práticas de Segurança

*   **Vazamento de Memória:** Acontece ao esquecer `delete`.
*   **Ponteiro Pendurado (Dangling Pointer):** Ocorre quando você acessa um ponteiro *depois* de a memória ter sido liberada com `delete`. O ponteiro aponta para "lixo".
    *   **Solução:** Após `delete ptr;`, é uma boa prática fazer `ptr = nullptr;`. Isso anula o ponteiro e previne seu uso acidental.

```