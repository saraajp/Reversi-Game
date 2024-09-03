#include "reversi.h"



/*---------------------------------------------
 * Nome: game_over
 *
 * Descrição: vê se existem jogadas possíveis para a AI e o humano. Se nenhum tiver jogadas válidas, sai e retorna 1
 *
 * Retorno: 0 ou 1 consoante se existem ou não jogadas válidas
 * ---------------------------------------------*/


int game_over(char board[8][8], char player, char AI){
    int i,j,player_no_valid_moves= 1, ai_no_valid_moves= 1;

    for (i= 0; i < 8; i++){
        for (j =0; j < 8; j++){

            //Iteramos pelo tabulleiro
            //Se acharmos uma posição que haja "." e jogadas possíveis do player ou ai o jogo NAO acaba e as flags resetam
            if (board[i][j] == '.' &&(count_flips(board, i, j, player, 0) > 0 ||count_flips(board, i, j, AI, 0) > 0)){
                player_no_valid_moves = 0;
                ai_no_valid_moves = 0;
                break;
            }
        }


        //Se entrar aqui é pq n encontramos nenhuma posição nas condiçoes em cima
        if (player_no_valid_moves== 0 && ai_no_valid_moves== 0){
            break;
        }


    }


    return (player_no_valid_moves && ai_no_valid_moves);
}





/*---------------------------------------------
 * Nome: is_board_full
 *
 * Descrição: vê se existem jogadas possíveis para a AI e o humano. Se nenhum tiver jogadas válidas, sai e retorna 1
 *
 * Retorno: 0 se o tabuleiro n estiver cheio / 1 se estiver cheio
 * ---------------------------------------------*/

int is_board_full(char board[8][8]){
    int i,j;

    //Iteramos as posiçoes do tabuleiro, se encontar-mos um espaço vazio salta
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if (board[i][j] == '.') return 0;
        }
    }
    return 1;
}







/*---------------------------------------------
 * Nome: winner
 *
 * Descrição: conta as peças de ambos jogadores e indica o
 *
 * Retorno: nada
 * ---------------------------------------------*/
void winner(char board[8][8], char player, char AI){
    int player_pieces= 0, AI_pieces = 0, i,j;

    //Itera pelo tabuleiro as contar peças de cada jogador
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == player) {
                player_pieces++;
            } else if (board[i][j] == AI) {
                AI_pieces++;
            }
        }
    }


    printf("\n\n\nResultado Final:\n");
    printf("Jogador (%c): %d peças\n", player, player_pieces);
    printf("AI (%c): %d peças\n", AI, AI_pieces);

    if (player_pieces > AI_pieces){
        printf("O jogador ganhou!!\n");
    } else if (AI_pieces > player_pieces){
        printf("A AI ganhou :(\n");
    } else {
        printf("Empate!\n");
    }
}
