#include "reversi.h"





/*---------------------------------------------
 Nome: player_turn

 Descrição: Esta função gere a jogada do jogador humano. Recebe as coordenadas ou undo e executa

 Retorno: nada
 ---------------------------------------------*/

void player_turn(char board[8][8], char player, ALL_Boards** pGame_History, int* pU_Writen, int undo){
    int i, j, row, col, flips, player_no_valid_moves;
    char input[10]; //Usamos como buffer para ler o input

    player_no_valid_moves = 1;


    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            //Itera pelo tabuleiro até encontrar uma jogada que seja válida e sai
            if (board[i][j] == '.' && count_flips(board, i, j, player, 0) > 0) {
                player_no_valid_moves = 0;
                break;
            }
        }
        //Sai dos loops se encontrar uma jogada válida
        if (player_no_valid_moves==0){
            break;
        }
    }




    //Caso tenha iterado tudo sem encontrar nenhuma jogada válida
    if (player_no_valid_moves == 1){
        printf("\n\n\nSem movimentos válidos para %c.\n", player); // Rip bozo n há jogadas válidas


    } else{
        while (1){

            // Pedir as coordenadas
            printf("Coordenadas %c : ", player);
            fgets(input, sizeof(input), stdin); //Lê o input

            //Remove o \n
            if (input[strlen(input)-1]== '\n'){
                input[strlen(input)-1]= '\0';
            }

            //Caso se tenha escrito "u"
            if (strcmp(input, "u") == 0){

                // Undo é feito se: 1) undo=1 (-u nos args)
                //                 2) undo_move=1 (seja fazível)

                if (undo && undo_move(board, pGame_History) == 1){
                    printf("KILLA QUEEN BITE ZA DUSTO!!!  É a tua vez.\n");
                    *pU_Writen = 1; //Foi feito undo yipiii
                    return; // Sai



                } else if (undo == 0){

                    // Não se escreveu -u nos args
                    printf("Undo indisponível (não foi escrito -u nos argumentos)\n");

                } else{
                    printf("Este é o tab. inicial, não dá para fazer undo\n");
                }


            } else {

                //As coordenadas sao constituidas apenas por 2 numero
                if (sscanf(input, "%d %d", &row, &col) != 2){
                    printf("Coordenadas inválidas\n");
                    continue;
                }

                // Condição "barreira"
                if (row < 0 || row >= 8 || col < 0 || col >= 8){
                    printf("Só podem ser números de 0 a 7\n");

                } else {

                    //Nº de flips da jogada
                    flips = count_flips(board, row, col, player, 0);

                    //É válido se flips > 0
                    if (flips > 0){
                        add_board(board, pGame_History);//Adiciona um nodo para o tabuleio atual
                        make_move(board, row, col, player);
                        *pU_Writen = 0; //Reseta a flag ao realizar uma jogada válida
                        break;
                    } else {
                        //É inválido se flips = 0
                        printf("Movimento inválido\n");
                    }
                }
            }
        }
    }
}








/*---------------------------------------------
 Nome: ai_move

 Descrição: Esta função gere a jogada AI. COmeça por verificar todos os moves válidos e escolhe qual deles é o melhor

 Retorno: nada
 ---------------------------------------------*/

void ai_move(char board[8][8], char AI){
    Move* head;
    Move* best_move = NULL;
    Move* current; //pointer que precorre a linked list no ciclo for
    int max_flips = 0; //maximo nº de flips atual


    //funçao n retornar nada!!!
    //a funçao é corrida e agora temos todas as jogadas possiveis da AI
    all_ai_valid_moves(board, AI, &head);


    //entra neste if se n existirem jogadas possiveis
    if (head==NULL){
        free_moves_memory(head);
        return;
    }




    //por cada iteraçao da lista vai ver se o nº de flips é maior ou nao
    for (current = head; current != NULL; current = current->next){

        //o maior nº de flips é a melhor jogada
        if (current->flips > max_flips){
            max_flips = current->flips;
            best_move = current;
        }

        //se o número de flips a ser lido for igual substitui caso as coords do current seja menor
        else if (current->flips == max_flips){
            if (current->row < best_move->row || (current->row == best_move->row && current->col < best_move->col)){
                best_move = current;
            }
        }
    }


    if (best_move!=NULL){
        printf("AI (%c): %d %d",AI, best_move->row, best_move->col);
        make_move(board, best_move->row, best_move->col, AI);
    }

    while (head){
        current= head;
        head= head->next;
        free(current);

    }
}
