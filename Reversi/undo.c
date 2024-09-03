#include "reversi.h"




/*---------------------------------------------
 Nome: add_board

 Descrição: ESta função aloca espaço para ser possível adicionar mais um estado do tabuleiro

 Retorno: nada
 ---------------------------------------------*/
void add_board(char board[8][8], ALL_Boards** pGame_History) {
    //Alocamos espaço para acrescentar um novo nodo
    ALL_Boards* new_board = (ALL_Boards*)malloc(sizeof(ALL_Boards));


    if (new_board==NULL) {
        printf("Erro ao alocar memória para o estado do tabuleiro.\n");
        exit(EXIT_FAILURE);
    }

    //Copia o tabuleiro atual e poẽ na linked list
    memcpy(new_board->board, board, sizeof(new_board->board));

    //O novo nodo agora aponta para o anterior
    new_board->next = *pGame_History;

    //Atualiza o pointer para o inicio da lista
    *pGame_History = new_board;

}



/*---------------------------------------------
 Nome: undo_move                             *

 Descrição: ESta função começa por verificar se as linked lists estão vazias e retira o nodo que contem o tabuleiro mais recente

 Retorno: nada
 ---------------------------------------------*/
int undo_move(char board[8][8], ALL_Boards** pGame_History) {

    // Verifica se a lista está vazia
    //Caso n seja possível fazer undo, sai
    if (*pGame_History == NULL) {
        return 0;
    }

    //(POP): Remove o estado atual

    ALL_Boards* temp = *pGame_History;
    *pGame_History = (*pGame_History)->next;

    //O estado do tabuleiro passa para o estado do nó removido
    memcpy(board, temp->board, sizeof(temp->board));


    free(temp);

    return 1;
}


