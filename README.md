# Reversi-Game (Não totalmento acabado!)

1) O jogo já está práticamente acabado, no entando, ainda existem um bugszinhos :p
2) Não está optimizado ao máximo, é algo que ainda pode melhorar
(Quero descançar antes das aulas começarem 😭 )

---------------------------------------------------------------------------------------

Argumentos de entrada:
1) -p X   ou   -p O  ---> permite escolher que peças queres ser
2) -u                ---> para poderes fazer "undo" das tuas jogadas
3) -f outputfile.txt ---> caso queiras guardar as jogadas, poes o nome do ficheiro de texto

Exemplo:  ./reversi.out -p X -f 123.txt -u

---------------------------------------------------------------------------------------

Inserir as coordenadas:
As coordenadas devem ser escritas no formato linha coluna e separados por um espaço.
As coordenadas sao de 0 a 7.

Exemplo: 

(Tabuleiro default)
  0 1 2 3 4 5 6 7
0 . . . . . . . .
1 . . . . . . . .
2 . . . . . . . .
3 . . . O X . . .
4 . . . X O . . .
5 . . . . . . . .
6 . . . . . . . .
7 . . . . . . . .

Jogador (X): 2 3


  0 1 2 3 4 5 6 7
0 . . . . . . . .
1 . . . . . . . .
2 . . . X . . . .
3 . . . O X . . .
4 . . . X O . . .
5 . . . . . . . .
6 . . . . . . . .
7 . . . . . . . .


---------------------------------------------------------------------------------------

Como funciona o undo:
Quando te pedem as coordenadas, em vez de as inserires, escreves a letra "u".
Sempre que escreveres "u" volta para a tua jogada anterior.
Podes fazer isso as vezes que quiseres.


---------------------------------------------------------------------------------------
Como jogar: https://brainking.com/pt/GameRules?tp=10

O jogador humano joga contra uma "AI" (não é realmente uma AI, só um algoritmo que calcula
as jogadas que dão mais pontos).
O objetivo é ter o máximo numero das suas peças no computador.
O jogo acaba quando ambos jogadores ficam sem movimentos válidos ou o tabuleiro enche. 
---------------------------------------------------------------------------------------
