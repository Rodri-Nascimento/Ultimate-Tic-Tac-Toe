#include <stdio.h>
#include "tic_tac_toe.h"



void inicializar_tabuleiro(TAB *tab) ///meter o tabuleiro preenchido inicialmente com o caracter '-'
{
    int i,j,k;

    for(k=0; k < 9; k++)
    {
        tab[k].preenchido = 0;

        for(i=0; i < 3; i++)
        {
            for(j=0; j < 3; j++)
                tab[k].m[i][j] = '-';
        }
    }

}




void imprime_mini_tabuleiro(TAB *tab, int k, int i)
{
    int j;

    for(j=0; j < 3; j++)
    {
        printf(" %c",tab[k].m[i][j]);

    }

}




void imprime_tabuleiro(TAB *tab)
{
    int i;

    printf("\n\n");

    for(i=0; i < 3; i++)
    {
        printf("\t");
        imprime_mini_tabuleiro(tab,0,i);
        printf("  | ");
        imprime_mini_tabuleiro(tab,1,i);
        printf("  | ");
        imprime_mini_tabuleiro(tab,2,i);
        printf("\n");

    }

    printf("     -----------+---------+-----------\n");

    for(i = 0; i < 3; i++)
    {
        printf("\t");
        imprime_mini_tabuleiro(tab,3,i);
        printf("  | ");
        imprime_mini_tabuleiro(tab,4,i);
        printf("  | ");
        imprime_mini_tabuleiro(tab,5,i);
        printf("\n");

    }

    printf("     -----------+---------+-----------\n");

    for(i=0; i < 3; i++)
    {
        printf("\t");
        imprime_mini_tabuleiro(tab,6,i);
        printf("  | ");
        imprime_mini_tabuleiro(tab,7,i);
        printf("  | ");
        imprime_mini_tabuleiro(tab,8,i);
        printf("\n");
    }

    printf("\n\n");

}

