#include <stdio.h>
#include "tic_tac_toe.h"


void tabuleiro_preenchido(TAB *tab,int* ntab, char c, int jogador)
{
    if(ganhou_por_linhas(tab,c,ntab) == 1)
        printf("\n   Parabens Jogador %d, tabuleiro %d foi totalmente preenchido (vitoria por linhas)!",jogador,(*ntab)+1);
    else if(ganhou_por_colunas(tab,c,ntab) == 1)
        printf("\n   Parabens Jogador %d, tabuleiro %d foi totalmente preenchido (vitoria por colunas)!",jogador,(*ntab)+1);
    else if(ganhou_por_diagonal_principal(tab,c,ntab) == 1)
        printf("\n   Parabens Jogador %d, tabuleiro %d foi totalmente preenchido (vitoria por diaginal principal)!",jogador,(*ntab)+1);
    else if(ganhou_por_diagonal_secundaria(tab,c,ntab) == 1)
        printf("\n   Parabens Jogador %d, tabuleiro %d foi totalmente preenchido (vitoria por diaginal secundaria)!",jogador,(*ntab)+1);
    else if(empate_tabuleiro_mini(tab,ntab) == 1)
        printf("\n   Empate no tabuleiro %d!",(*ntab)+1);
}



int empate_tabuleiro_mini(TAB *tab, int* ntab)
{
    int i,j;

    for(i=0; i < 3; i++)
    {
        for(j=0; j < 3; j++)
        {
            if(tab[*ntab].m[i][j] == '-') ///caso haja ainda um - na matriz, sabemos que ainda falta preeencher 1 espaço
                return 0;
        }
    }

    tab[*ntab].preenchido = 3; ///os tabuleiros onde ocorreu empate ficam com preenchido = 3 para se diferenciar dos que
                              ///têm vitorias

    return 1;
}



int ganhou_por_linhas(TAB *tab,char c, int* ntab)
{
    int i;

    for(i=0; i < 3 ; i++)
    {
        if(tab[*ntab].m[i][0] == c && tab[*ntab].m[i][1] == c && tab[*ntab].m[i][2] == c)
        {
            bloquear_tabuleiro(tab,c,ntab);
            return 1;
        }
    }

    return 0;

}



int ganhou_por_colunas(TAB *tab,char c, int* ntab)
{
    int j;

    for(j=0; j < 3 ; j++)
    {
        if(tab[*ntab].m[0][j] == c && tab[*ntab].m[1][j] == c && tab[*ntab].m[2][j] == c)
        {
            bloquear_tabuleiro(tab,c,ntab);
            return 1;
        }
    }

    return 0;

}



int ganhou_por_diagonal_principal(TAB *tab,char c, int* ntab)
{
    if(tab[*ntab].m[0][0] == c && tab[*ntab].m[1][1] == c && tab[*ntab].m[2][2] == c)
    {
        bloquear_tabuleiro(tab,c,ntab);
        return 1;
    }

    return 0;
}



int ganhou_por_diagonal_secundaria(TAB *tab,char c, int* ntab)
{
    if(tab[*ntab].m[0][2] == c && tab[*ntab].m[1][1] == c && tab[*ntab].m[2][0] == c)
    {
        bloquear_tabuleiro(tab,c,ntab);
        return 1;
    }

    return 0;
}



void bloquear_tabuleiro(TAB *tab,char c, int* ntab) /**Em caso de vitoria, esta função preenche a matriz com x ou o e deixa o tabuleiro sinalizado a dizer que está preenchido*/
{
    for(int i = 0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            tab[*ntab].m[i][j] = c;
        }
    }

    ///distinguir quem venceu
    if(c == 'X')
        tab[*ntab].preenchido = 1;
    else
        tab[*ntab].preenchido = 2;
}



int grande_vencedor(TAB *tab)  /**Era fixe que esta função só executa se apartir de x jogadas qunatas não sei*/
{
    int i,j, count =0;

    for(i=0, j=0; i < 9; i+=3, j++)
    {
        if(tab[i].preenchido == 1 && tab[i+1].preenchido == 1 && tab[i+2].preenchido == 1) ///vitoria por linhas
        {
            printf("\n ---------------------------------------------------------\n");
            printf(" |      VENCEDOR: JOGADOR1 (venceu por linhas)   !       |");
            printf("\n ---------------------------------------------------------\n");
            return 0;
        }


        if(tab[i].preenchido == 2 && tab[i+1].preenchido == 2 && tab[i+2].preenchido == 2) ///vitoria por linhas
        {
            printf("\n ---------------------------------------------------------\n");
            printf(" |      VENCEDOR: JOGADOR2 (venceu por linhas)   !       |");
            printf("\n ---------------------------------------------------------\n");
            return 0;
        }


        if(tab[j].preenchido == 1 && tab[j+3].preenchido == 1 && tab[j+6].preenchido == 1) ///vitoria por colunas
        {
            printf("\n ---------------------------------------------------------\n");
            printf(" |      VENCEDOR: JOGADOR1 (venceu por colunas)  !       |");
            printf("\n ---------------------------------------------------------\n");
            return 0;
        }


        if(tab[j].preenchido == 2 && tab[j+3].preenchido == 2 && tab[j+6].preenchido == 2) ///vitoria por colunas
        {
            printf("\n ---------------------------------------------------------\n");
            printf(" |      VENCEDOR: JOGADOR2 (venceu por colunas)  !       |");
            printf("\n ---------------------------------------------------------\n");
            return 0;
        }
    }



    ///Vitórias por Diagonais
    if(tab[0].preenchido == 1 && tab[4].preenchido == 1 && tab[8].preenchido == 1) ///vitoria por diagonal principal
    {
        printf("\n ---------------------------------------------------------\n");
        printf(" | VENCEDOR: JOGADOR1 (venceu por diagonal principal)  ! |");
        printf("\n ---------------------------------------------------------\n");
        return 0;
    }


    if(tab[0].preenchido == 2 && tab[4].preenchido == 2 && tab[8].preenchido == 2) ///vitoria por diagonal principal
    {
        printf("\n ---------------------------------------------------------\n");
        printf(" | VENCEDOR: JOGADOR2 (venceu por diagonal principal)  ! |");
        printf("\n ---------------------------------------------------------\n");
        return 0;
    }



    if(tab[2].preenchido == 1 && tab[4].preenchido == 1 && tab[6].preenchido == 1) ///vitoria por diagonal secundaria
    {
        printf("\n ---------------------------------------------------------\n");
        printf(" | VENCEDOR: JOGADOR1 (venceu por diagonal secundaria) ! |");
        printf("\n ---------------------------------------------------------\n");
        return 0;
    }

    if(tab[2].preenchido == 2 && tab[4].preenchido == 2 && tab[6].preenchido == 2) ///vitoria por diagonal secundaria
    {
         printf("\n ---------------------------------------------------------\n");
        printf(" | VENCEDOR: JOGADOR2 (venceu por diagonal secundaria) ! |");
        printf("\n ---------------------------------------------------------\n");
        return 0;
    }




    /**Após fazer todas as verificações de vitoria, resta ver em caso de empate pois se não há vitorias, há empate
       então vamos percorrer o nosso array de structs e ver se ainda há algum a 0*/


    for(i=0; i < 9; i++)
    {
        if(tab[i].preenchido == 0)
            return 1;
        else
            count++;
    }

    if(count == 9)
    {

        printf("\n ---------------------------------------------------------\n");
        printf(" |                      EMPATE !                         | ");
        printf("\n ---------------------------------------------------------\n");
        return 0;
    }

    return 1;

}

