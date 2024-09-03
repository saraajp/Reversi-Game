#include "reversi.h"
#include <stdio.h>



/*---------------------------------------------
 Nome: print_board

 Descrição: faz print do tabuleiro atual e assina-la com um 'P' as jogadas possíveis

 Retorno: nada
 ---------------------------------------------*/

void print_board(FILE *file, char board[8][8], char player){
    int i,j;
    printf("\n\n\n");

    //Precorre as linhas e colunas do tabuleio
    for(i= -1; i< 8; i++){
        if(i== -1){
            fprintf(file,"  0 1 2 3 4 5 6 7\n");

        }else{
            for(j= -1; j< 8; j++){
                if(j== -1){
                    fprintf(file,"%d ",i);

                } else {

                    //Faz print dos "."s ou X/O
                    if (board[i][j]== '.' && count_flips(board, i, j, player, 0) > 0) {
                        fprintf(file,"P "); //Poe no tabuleiro um "P" por cada jogada válida
                    } else {
                        fprintf(file,"%c ",board[i][j]);
                    }

                }
            }
            fprintf(file,"\n");
        }
    }
    fflush(file);
}






/*---------------------------------------------
 Nome: initialize_board

 Descrição: inicializa o tabuleira default (aquele apenas com as 4 peças)

 Retorno: nada
 ---------------------------------------------*/
void initialize_board(char board[8][8]){
    int i, j;

    // Inicializar o tabuleiro (pontos '.')
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            board[i][j] = '.';
        }
    }

    // Inicializar o tabuleiro (peças centrais)
    board[3][3] = 'O';
    board[3][4] = 'X';
    board[4][3] = 'X';
    board[4][4] = 'O';
}






/*---------------------------------------------
 Nome: initialize_board

 Descrição: consoante os agrs inseridos, faz print ou nao do tabuleiro num ficheiro de output e faz sempre no stdout

 Retorno: nada
 ---------------------------------------------*/
void output(FILE* Write, char board[8][8], char player){

    //Print do tabuleiro default num ficheiro, se pedido
    if (Write != stdout){
        print_board(Write, board, player);
        fprintf(Write,"\n\n\n");
    }

    //Print do tabuleiro default no stdout
    print_board(stdout, board, player);

}
