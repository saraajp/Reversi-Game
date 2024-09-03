#include "reversi.h"


int main(int argc, char *argv[]){
    char player, AI;
    int undo, u_writen= 0;  //Flag para indicar se o "u" foi escrito
    FILE *Write;
    char board[8][8];
    ALL_Boards* game_history= NULL;

    read_args(argc, argv, &player, &AI, &undo, &Write);
    initialize_board(board);//Inicializa o tabuleiro default


    while(1){
        // Vez do jogador
        output(Write, board, player);//Print do tabuleiro
        player_turn(board, player, &game_history, &u_writen, undo);


        // Verifica se o undo foi realizado
        if (u_writen==0){
            // Vez da AI
            output(Write, board, AI);//Print do tabuleiro
            ai_move(board, AI);

        }

        //Verificar end game
        //is_board_full -> tab. cheio
        //game_over -> n há moves validos de ambos
        if (is_board_full(board)==1 || game_over(board, player, AI)==1){
            printf("\n\n\nFim do jogo!\n");
            winner(board, player, AI);
            break;
        }
    }


    //Fechar o output file
    if (Write != stdout){
        fclose(Write);
    }

    //Free doa tabuleiros guardados
    free_boards(&game_history);

    return 0;
}
