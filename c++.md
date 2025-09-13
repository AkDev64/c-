# Anotações de Leitura

## Livro: The C++ Programming Language, do Bjarne Stroustrup - criador da linguagem e do curso Udemy C++ Moderno do Marcos Oliveira

Lembrar de reler a introdução quando da conclusão do estudo.

## Tipos, Variaveis e Aritimética

### Tipos

|tipo  | Descrição | Exemplos | Intervalo |
|---|---|---|---|  
|bool  |Boleano  |true ou false  | true ou falso |
|char|Caracter|z, a, (um único caracter)| -128 a 127 |
|int|Inteiro|1, 2, 10, 1000| -2,147mm a + 2,147 mm |
|float | ponto flutuante com precisão de 32 bits | 3.14 2912847132.1 | 7 dig sigtnificativos |
|double|Ponto flutuante com o dobro de precisão|3.14, 299793.0| 16 dig. significativos |

O tamanho alocado em cada tipo é um multiplo do padrão básico char, sizeof(char)=1, sizeof(bool)=1, sizeof(int)=4, sizeof(double)=8

Os operadores aritiméticos são apropriados de acordo com o tipo estabelecido para o objeto, ou seja, cada tipo de dados tem seus operadores válidos:

## Operadores  aritiméticos

| Operadores | Exemplo |
| -------------- | --------------- |
|x+y | mais|
|+x |  mais unitário - redundante com y = x |
|x−y | menos |
|−x | menos unitário - opõe o valor de x, exemplo y = -x |
|x∗y | multiplicação |
|x/y | divisão |
|x%y | módulo |

## Operadores de comparação

| Oporadores | Exemplo |
| -------------- | --------------- |
|x==y  | é igual a? |
|x!=y | é difrente de? |
|x<y | é menor que?|
|x>y | é maior que? |
|x<=y | é menor ou igual a?|
|x>=y | é maior ou igual a?|

Esses são apenas alguns operadores de C++, sempre consultar lista completa.

### Variaveis

declaração: define o tipo para uma variável
definição: inicializa o valor que efetivamente será colocado na memória em tempo de execução

Exemplos de declaração de variáveis
int x, y
char a, b, c
bool teste
float z
double w

Exemplos de definição de variáveis

x = 0
y = 1
a = "l"
teste = false
z = 3.141592
w = z * z

formas de definção de variaveis

int x = 1;
int x(1);
int x{1}; // preferível por atribuir um valor 0 as variáveis aumentando previsibilidade (entender melhor)

obs: é possível declarar e definir em uma única sentença -> int var = 1
obs: também é possível dobrar a amplitude das tipologias numéricas declarando-as unsigned

## Funções

arquétipo:

tipo nomeDaFunção(){
declarações e comandos
retorno // se for o caso, ou seja, quando o tipo da função for diferente de void é necessário definir um retorno.
}

### Parâmetros

tipo nomeFunção(parametro1, ..., parametoN){}
