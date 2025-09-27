## Operador de Incremento (decremento funciona igual)

Em C++, os operadores ++ são operadores de incremento que aumentam o valor de um operando por um, podendo ser de prefixo ( ++variável ) ou de sufixo ( variável++ ). A diferença é a ordem em que a operação é realizada e o valor retornado pela expressão. O operador de prefixo retorna o valor já incrementado, enquanto o operador de sufixo retorna o valor original e, depois, incrementa-o. 

## Pré-Incremento (++variável)

    O valor da variável é incrementado em um.
    O valor já incrementado é o resultado da expressão. 

Exemplo:

```
int a = 5;
int b = ++a; // a agora é 6, e b recebe 6
```

## Pós-Incremento (variável++)

    O valor original da variável é usado como resultado da expressão.
    Após a utilização do valor original, a variável é incrementada em um. 

Exemplo:

```
int a = 5;
int b = a++; // b recebe 5, e a depois se torna 6
```

