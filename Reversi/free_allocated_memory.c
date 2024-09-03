#include "reversi.h"


/*---------------------------------------------
 * Nome: free_moves_memory
 *
 * Descrição: LIberta todas as jogadas possiveis da AI da memoria
 *
 * Retorno: nada
 * ---------------------------------------------*/

void free_moves_memory(Move* head){
    Move* temp;
    while (head){
        temp = head;
        head = head->next;
        free(temp);
    }
}




/*---------------------------------------------
 * Nome: free_boards
 *
 * Descrição: LIberta todos os tabuleiros guardados ao longo do jogo
 *
 * Retorno: nada
 * ---------------------------------------------*/
void free_boards(ALL_Boards** pGame_History){
    ALL_Boards* temp;
    while (*pGame_History){
        temp = *pGame_History;
        *pGame_History = (*pGame_History)->next;
        free(temp);
    }
}
