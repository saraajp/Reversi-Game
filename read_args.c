#include "reversi.h"



/*---------------------------------------------
 Nome: read_args

 Descrição: Esta função recebe, analisa e processa os parametros de entrada introduzidos pelo utilizador

 Retorno: nada
 ---------------------------------------------*/
void read_args(int argc, char *argv[], char* pPlayer, char*pAI,int* pUndo, FILE** pWrite){
    int i;

    *pPlayer= '\n';
    *pAI='\n';
    *pUndo= 0;
    *pWrite= stdout;

    int write_in_file = 0;

    for (i = 1; i < argc; i++){

        if (invalid_args(argv, i - 1) == 0){
            printf("Parametro inválido\n");
            exit(EXIT_FAILURE);
        }

        if (strcmp(argv[i], "-u") == 0){
            if (*pUndo != 0){
                printf("-u mais q uma vez é haram\n");
                exit(EXIT_FAILURE);
            }

            *pUndo = 1;
        }

        if (strcmp(argv[i], "-p") == 0){
            if (*pPlayer != '\n'){
                printf("-p mais q uma vez é haram\n");
                exit(EXIT_FAILURE);
            }

            *pPlayer = chose_player_symbol(argc, argv, &i);

            //a AI fica com o simbolo que sobra
            if(*pPlayer=='X'){
                *pAI='O';
            }else{
                *pAI='X';
            }

        }

        if (strcmp(argv[i], "-f") == 0) {
            if (write_in_file != 0) {
                printf("-f mais q uma vez é haram\n");
                exit(EXIT_FAILURE);
            }

            write_in_file = chose_output_file(argc, argv, &i);
        }
    }

    *pWrite = initialize_file(argv, write_in_file);
}






/*---------------------------------------------
 * Nome: invalid_args
 *
 * Descrição: Esta função recebe verifica se os parametros de entrada são válidos ou não
 *
 * Retorno: retorna 1 se for inválido, retorna 0 se for válido
 * ---------------------------------------------*/

int invalid_args(char* argv[], int i){
    if ((strcmp(argv[i + 1], "-f") == 0) || (strcmp(argv[i + 1], "-p") == 0) || (strcmp(argv[i + 1], "-u") == 0)){
        return 1;
    }

    return 0;
}





/*---------------------------------------------
 * Nome: chose_player_symbol
 *
 * Descrição: ESta função atribui ao jogador humano a sua respetiva peça escolhida
 *
 * Retorno: char corrspondente à peça
 * ---------------------------------------------*/

char chose_player_symbol(int argc, char* argv[], int *i){
    char X='X', O='O';

    if (*i + 1 >= argc) {
        printf("Caralho queres segmentation faults?\n");
        exit(EXIT_FAILURE);
    }

    *i = *i + 1;

    if (strcmp(argv[*i], "X") == 0) {
        return X;
    }

    if (strcmp(argv[*i], "O") == 0) {
        return O;
    }

    printf("Só se pode escolher X ou O com simbolos\n");
    exit(EXIT_FAILURE);
}
