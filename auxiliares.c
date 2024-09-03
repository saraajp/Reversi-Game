#include "reversi.h"







/*---------------------------------------------
 Nome: all_ai_valid_moves

 Descrição: Esta função coloca todas as jogadas possíveis da AI numa linked list

 Retorno: nada
 ---------------------------------------------*/

void all_ai_valid_moves(char board[8][8], char player, Move** head){
    int i, j,flips;

    *head = NULL;

    //Testar todas a jogadas possíveis:
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            //Se a cordenada estiver vazia, flips= quantas peças seriam viradas
            if (board[i][j] == '.'){
                flips = count_flips(board, i, j, player, 0);

                //Se flips >0 --> jogada válida, alocamos uma nova estrutura
                //(as estruturas (todas as possiveis jogadas) estão ligadas entre si)
                if (flips > 0){
                    Move* new_move = (Move*)malloc(sizeof(Move));
                    new_move->row = i;
                    new_move->col = j;
                    new_move->flips = flips;
                    new_move->next = *head;
                    *head = new_move;
                }
            }
        }
    }
}








/*---------------------------------------------
 Nome: count_flips

 Descrição: Esta função testa todas as direções possiveis de uma ddada jogada com o objetivo de calcular quantos flips são originados

 Retorno: nº de flips resultntes de uma jogada
 ---------------------------------------------*/

int count_flips(char board[8][8], int row, int col, char player, int flip_flag ){
    //8 elementos de tamanho 2 (8 possiveis direçoes, coordenadas de 2)
    int directions[8][2] = {{-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}};

    int d, r,c,count,total_flips = 0;

    //----CICLO PARA CADA DIREÇAO----
    //r e c sao atualizados por cada uma das 8 direçoes
    for (d= 0; d < 8; d++){

        r = row + directions[d][0]; //ex: [0][0] = -1, é o X de {-1,-1}
        c = col + directions[d][1]; ////ex: [0][1] = -1, é o Y de {-1,-1}
        count = 0;                  //reset a 0

        //itera dentro dos limites do tabuleiro + sempre que o simbolo seja o do adversario
        while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] != player && board[r][c] != '.'){
            r += directions[d][0];
            c += directions[d][1];

            //incrementamos "uma casa" na mesma direçao atual e INCREMENTA a contagem de os flips que faz
            count++;
        }


        //caso seja detetado o simbolo do jogador (da jogada atual)
        if (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == player){

            total_flips += count;           //somamos +1 para somar tambem o simbolo "barreira"


            //se for = 1 , a jogada sera depois executada (vira)
            //se for = 0, o tabuleiro nao é atualizados (n vira)
            if ( flip_flag == 1 ) {
                r = row + directions[d][0];
                c = col + directions[d][1];

                //Executa o nº de peças a virar e altera o simbolo
                while (count > 0) {
                    board[r][c] = player;
                    r += directions[d][0];
                    c += directions[d][1];
                    count--;
                }
            }
        }
    }

    //nº de flips resultntes da jogada
    return total_flips;
}






/*---------------------------------------------
 Nome: make_move

 Descrição: efetua a jogada (dá)

 Retorno: nada
 ---------------------------------------------*/

void make_move(char board[8][8], int row, int col, char player){
    int flips;

    //entra se a posiçao estiver vazia
    if (board[row][col] == '.'){
        flips = count_flips(board, row, col, player, 1);

        //é valida de flips>0
        if (flips > 0){
            board[row][col] = player;
        }else{
            printf("Movimento inválido\n");
            exit(EXIT_FAILURE);
        }


    }else{
        printf("Movimento inválido\n");
        exit(EXIT_FAILURE);
    }
}
