Quando construtores e destrutores são chamados
Os construtores e destrutores são chamados implicitamente pelo compilador. A ordem em que essas chamadas de função ocorrem
depende da ordem em que a execução entra e sai dos escopos em que os objetos são instanciados. Geralmente, as chamadas de destru-
tor são feitas na ordem inversa das chamadas de construtor correspondentes, mas, como veremos nas figuras 9.11–9.13, as classes de
armazenamento de objetos podem alterar a ordem em que destrutores são chamados.
Os construtores são chamados para objetos definidos no escopo global antes de qualquer outra função (incluindo main) nesse arquivo
começar a execução (embora a ordem de execução de construtores de objeto global entre arquivos não seja garantida). Os destrutores
correspondentes serão chamados quando main terminar. A função exit força um programa a terminar imediatamente e não executa os
destrutores de objetos automáticos. A função é freqüentemente utilizada para terminar um programa quando um erro é detectado na
entrada ou quando não é possível abrir um arquivo a ser processado pelo programa. A função abort trabalha de maneira semelhante
à função exit, mas força o programa a terminar imediatamente, sem permitir que os destrutores de quaisquer objetos sejam chamados. A
função abort é normalmente utilizada para indicar uma terminação anormal do programa. (Ver o Capítulo 24, “Outros tópicos”, para
obter informações adicionais sobre as funções exit e abort.)
O construtor de um objeto local automático é chamado quando a execução alcança o ponto em que o objeto é definido — o des-
trutor correspondente é chamado quando a execução deixa o escopo do objeto (isto é, quando o bloco em que esse objeto é definido
tiver terminado a execução). Os construtores e destrutores para objetos automáticos são chamados toda vez que a execução entra e sai
do escopo do objeto. Os destrutores não serão chamados para objetos automáticos se o programa terminar com uma chamada à função
exit ou à função abort.
O construtor de um objeto local static é chamado uma única vez, logo que a execução alcança o ponto em que o objeto foi definido
— o destrutor correspondente é chamado quando main termina ou quando o programa chama a função exit. Os objetos globais e static
são destruídos na ordem inversa de sua criação. Os destrutores não são chamados para os objetos static se o programa terminar com
uma chamada à função abort.
