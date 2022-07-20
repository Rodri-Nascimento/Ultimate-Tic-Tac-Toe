#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.c"
#include "tic_tac_toe.h"
#include "ajuda.c"
#include "menu_e_random.c"
#include "imprimir_na_consola.c"
#include "jogabilidade.c"
#include "funcoes_importantes.c"
#include "vitorias.c"
#include "final_do_jogo.c"



int main(void)
{
    TAB *tabuleiro_principal;
    int opcao;
    tabuleiro_principal = malloc(sizeof(TAB) * 9);

    if(tabuleiro_principal == NULL)
    {
        printf("Erro na alocação!!");
        return 0;
    }
    else
    {

        ajuda();

        srand(time(NULL));

        printf("\n");
        opcao = menu();

        switch(opcao)
        {
            case 1:
                jogar(tabuleiro_principal,1);
                break;



            case 2:

                jogar(tabuleiro_principal,2);
                break;

            case 3:

                jogar(tabuleiro_principal,3);
                break;

        }

    }


    free(tabuleiro_principal);
    return 0;

}

