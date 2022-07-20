#include <stdio.h>
#include "tic_tac_toe.h"


void matriz_ajuda()
{
    int i,j;
    char matriz[3][3];


    for(i=0; i < 3; i++)
    {
        for(j=0; j < 3 ; j++)
            matriz[i][j] = ' ';

    }



    printf("\t 0   1   2\n\n");

    for(i=0; i < 3; i++)
    {
        for(j = 0; j <3 ; j++)
        {
            if(j==0)
                printf("\t");
            printf(" %c ",matriz[i][j]);

            if(j < 2)
                printf("|");


            if(j == 2)
                printf("   %d",i);
        }

        printf("\n");
        if(i < 2)
            printf("\t---+---+---\n");
    }

}



void ajuda()
{
    printf("\n --------------------------- Bem-vindo! ---------------------------\n");
    printf("\n Modo de Jogo:\n");
    printf("\n   Na sua vez, cada jogador coloca a sua peca num dos");
    printf("\n   9 mini-tabuleiros atraves da insercao de coordenadas \n   na forma (x,y).");
    printf("\n");
    printf("\n   Para inserir as coordenadas tenha em conta a\n   ordem dos tabuleiros e o seguinte modelo: ");
    printf("\n\n");

    printf("   Ordem dos tabuleiros: \n");
    printf("\n   1 >> 2 >> 3\n   4 >> 5 >> 6\n   7 >> 8 >> 9");
    printf("\n\n");
    printf("   Modelo:\n");

    matriz_ajuda();

    printf("\n ------------------------------------------------------------------\n");
}

