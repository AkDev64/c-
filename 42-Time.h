// Esse programa tirado do livro do Deitel, demostra a importância de controlar
// (empacotar) o pré processamento para evitar que uma mesma classe seja
// definida duas vezes Declaração da classe Time. Funções-membro são definidas
// em Time.cpp

// impede múltiplas inclusões de arquivo de cabeçalho
#ifndef TIME_H
#define TIME_H

/*Boa prática de programação 9.2 - Deitel
utilize o nome do arquivo do cabeçalho em caixa alta com o ponto
substituído por um sublinhado nas diretivas de pré-processador #ifndef e #define
de um arquivo de cabeçalho.
*/

// definição da classe Time
class Time {
public:
  Time();                      // construtor
  void setTime(int, int, int); // configura hora, minuto e segundo
  void printUniversal(); // imprime a hora no formato de data/hora universal
  void printStandard();  // imprime a hora no formato-padrão de data/hora
private:
  int hour;   // 0 - 23 (formato de relógio de 24 horas)
  int minute; // 0 - 59
  int second; // 0 - 59
}; // fim da classe Time

#endif

/*
Quando construirmos programas maiores, outras definições e declarações também
serão colocadas em arquivos de cabeçalho. O em- pacotador de pré-processador
anterior impede que o código entre #ifndef (que quer dizer ‘se não definido’) e
#endif seja incluído se o nome TIME_H tiver sido definido. Se o cabeçalho não
foi incluído anteriormente em um arquivo, o nome TIME_H será definido pela
diretiva #define e as instruções de arquivo de cabeçalho serão incluídas. Se o
cabeçalho tiver sido incluído, TIME_H já estará definido e o arquivo de
cabeçalho não será novamente incluído. Tentativas de incluir um arquivo de
cabeçalho múltiplas vezes (inadvertidamente) em geral ocorrem em programas
grandes com muitos arquivos de cabeçalho que podem eles mesmos incluir outros*/
