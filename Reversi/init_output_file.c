#include "reversi.h"



/*---------------------------------------------
 * Nome: chose_output_file
 *
 * Descrição: Esta função recebe parametros do utilizador e é executada quando é detetado -f. Esta função analisa a posição dos argumentos em que é lido o -f e espera encontrar na posição seguinte um nome para o ficheiro de input/output.
 *
 * Retorno: o pointer para as posições do char* argv[]
 * ---------------------------------------------*/

int chose_output_file(int argc, char* argv[], int* pI){

     //Condição "barreira", vê se o indice da posição seguinte não é um indice válido de argv
    if (*pI + 1 >= argc) {
        printf("Parametro Inválido (Faltou pôr um ficheiro de output)\n");
        exit(EXIT_FAILURE);
    }

    //VÊ se o parametro a seguir é válido ou não
    if (invalid_args(argv, *pI) == 1) {
        printf("Parametro Inválido\n");
        exit(EXIT_FAILURE);
    }

    *pI = *pI + 1;

    return *pI;
}






/*---------------------------------------------
 * Nome: initialize_file
 *
 * Descrição: Esta função recebe parametros do utilizador e se vai ser possível ou não abrir o ficheiro para escrita
 *
 * Retorno: Retorno: pointer para o ficheiro a escrever
 * ---------------------------------------------*/

FILE* initialize_file(char** argv, int write_in_file){
    FILE* pFile = stdout;

    if (write_in_file != 0) {
        pFile = fopen(argv[write_in_file], "w");
    }

    if (pFile == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return stdout;
    }

    return pFile;
}
