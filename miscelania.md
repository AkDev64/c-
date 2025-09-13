# Esse arquivo tem anotações gerais sobre a linguagem c++

Essas anotações serão primeiramente salvas na órdem que forem surgindo.

## Sugestões do Autor para o programador

"Sugestions for Programmers gramming techniques:
[1] Use constructors to establish invariants (§2.4.3.2, §13.4, §17.2.1).
[2] Use constructor/destructor pairs to simplify resource management (RAII; §5.2, §13.3).
[3] Avoid ‘‘naked’’ new and delete (§3.2.1.2, §11.2.1).
[4] Use containers and algorithms rather than built-in arrays and ad hoc code (§4.4, §4.5, §7.4, Chapter 32).
[5] Prefer standard-library facilities to locally developed code (§1.2.4).
[6] Use exceptions, rather than error codes, to report errors that cannot be handled locally (§2.4.3, §13.1).
[7] Use move semantics to avoid copying large objects (§3.3.2, §17.5.2).
[8] Use unique_ptr to reference objects of polymorphic type (§5.2.1).
[9] Use shared_ptr to reference shared objects, that is, objects without a single owner that is responsible for their destruction (§5.2.1).
[10] Use templates to maintain static type safety (eliminate casts) and avoid unnecessary use of class hierarchies (§27.2). It might also be a good idea to review the advice for C and Java programmers (§1.3.3, §1.3.4).

## Usando namespaces

Para evitar digitar :: a cada utilização da biblioteca, pode se usar a declarativa namespaces. ex: use namespaces = std;

## Return de uma função, obrigatório? quando?

entender quando return é obrigatório em uma função.

## Aspas simples e Aspas Duplas

'\n' pode porque trata-se de apenas um caracter dentro das Aspas.

"aqui não pode ser aspas simples" por se tratar de uma string com muitos caracteres.

## Help do compilador

$ g++ -hierarchies

## blibliotecas

As bibliotecas (arquivos .h) geralmente estão localizdas na pasta /usr/include/

comando linux cpp mostra as bibliotecas que são compiladas junto com os códigos do projeto

```
cpp -x c++ -v
```

comando linux ldd mostar as bibliontecas de um programa e um executavel em c++

```
ldd <nome do executável>
```

### Passagem de variável com parâmetro de função

entender melhor:

Quando passamos uma variável com parâmetro para uma função, as alterações feitas na variável, dentro do escopo da função altera apenas a cópia da variável nesse escopo específico, quando retornamos para o ponto da chamada, ou seja, fora do escopo da função, a variável original passada permanece inalterada. Já com arrays isso não é verdade, se passado como parâmetro e alterado dentro do escopo da função chamada, quando do retorno para o ponto de chamada, o array passado estará alterado pelo comandos realizdos dentro da função executada. Parece que a passagem do array como parâmetro indica um ponteiro para o endereço de memória original dele enquanto numa variável é feita uma cópia dela com escopo interno da função.
