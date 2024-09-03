#ifndef REVERSI_H_INCLUDED
#define REVERSI_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Linha, coluna, nº de flips, pointer para o prox Move
typedef struct Move {
    int row, col;
    int flips;
    struct Move* next;
} Move;


typedef struct ALL_Boards {
    char board[8][8];
    struct ALL_Boards* next;
} ALL_Boards;



void print_board(FILE *file, char board[8][8], char player);
void read_args(int argc, char *argv[], char* pPlayer, char*pAI, int* pUndo, FILE** pWrite);
int invalid_args(char* argv[], int i);
char chose_player_symbol (int argc, char* argv[], int *pI);
int chose_output_file(int argc, char* argv[], int* pI);
FILE* initialize_file(char** argv, int write_in_file);
void all_ai_valid_moves(char board[8][8], char player, Move** head);
int count_flips(char board[8][8], int row, int col, char player, int flip_flag);
void make_move(char board[8][8], int row, int col, char player);
void free_moves_memory(Move* head);
void ai_move(char board[8][8], char AI);
void winner(char board[8][8], char player, char AI);
void initialize_board(char board[8][8]);
void output(FILE* Write, char board[8][8], char player);
void player_turn(char board[8][8], char player, ALL_Boards** pGame_History, int* pUndoPerformed, int undo);
int is_board_full(char board[8][8]);
int game_over(char board[8][8], char player, char AI);
void free_boards(ALL_Boards** pGame_History);
void add_board(char board[8][8], ALL_Boards** pGame_History);
int undo_move(char board[8][8], ALL_Boards** pGame_History);


#endif // REVERSI_H_INCLUDED
