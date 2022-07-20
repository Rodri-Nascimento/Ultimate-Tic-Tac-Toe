#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"

/******Ler coordenadas  vindas do utilizador*******/

NO* lercoordenadas(char c, int l, TAB *tab, int* ntab, NO* lista, int* conta, int automatico, int modo_jogo)
{
    int x,y;
    char h,letra;

    printf("\n");

    if(automatico == 0) ///computador a jogar
    {
        do{

            x = intUniformRnd(0,2);
            y = intUniformRnd(0,2);

            if(verifica(x,y,tab,ntab,automatico) != 0)
                break;

        }while(1);

        printf("\n   O Jogador %d (automatico), inseriu o caracter %c nas coordenadas (%d,%d) do tabuleiro numero %d.",l,c,x,y, (*ntab)+1);
    }
    else
    {

        do{

            printf("\n   Jogador %d, insira as coordenadas (x,y) para colocar o caracter %c no tabuleiro numero %d: ",l,c, (*ntab)+1);
            scanf(" %d%c%d",&x,&h,&y);

            if(verifica(x,y,tab,ntab,automatico) != 0 && h == ',')
                break;
            else
            {
                ///verificac�o falhou, vamos ent�o limpar o buffer do teclado para se poder introduzir novas coordenas.
                fflush(stdin); ///limpar o buffer sen�o cria um ciclo infinito
            }

        }while(1);

    }

    tab[*ntab].m[x][y] = c; ///introdu��o do caracter nas coordendas especificadas

    lista = adicionar_no(lista,x,y,ntab,c,l,conta,modo_jogo); ///adiconar um no � lista ligada com as informa��es importantes


    tabuleiro_preenchido(tab,ntab,c,l); ///verifica se o tabuleiro j� ficou preenchido apos a jogada

    imprime_tabuleiro(tab);

    *ntab = proximo_tabuleiro(tab,x,y); /**Achar o proximo tabuleiro em que se pode jogar**/


    return lista;
}

///Verifica se as coordenadas introduzidas pelo utilizador ou pelo computador s�o v�lidas

int verifica(int x, int y, TAB *tab, int* ntab, int automatico) ///verifica se as coordenadas introduzidas s�o v�lidas
{


        if(x < 0 || x >= 3 || y < 0 || y >= 3)
        {
            if(automatico != 0)
                printf("\n   Coordenadas invalidas.\n");///caso seja o computador a jogar n�o faz sentido mostar esta mensagem
            return 0;
        }
        else
        {
            if(tab[*ntab].m[x][y] == 'X' || tab[*ntab].m[x][y] == 'O')
            {
                if(automatico != 0)
                    printf("\n   Esta posicao ja se encontra ocupada.\n");
                return 0;
            }

        }


        return 1;
}



///ap�s a introdu��o das coordenadas a seguinte fun��o calcula o pr�ximo tabuleiro onde se pode jogar

int proximo_tabuleiro(TAB *tab,int x, int y)
{
    int prox,i;

    prox = 3*x+y; ///calculo do proximo tabuleiro

    if(tab[prox].preenchido == 0) ///caso o tabuleiro obtido atrav�s das coordenadas do utilizador estiver cheio
    {
        return prox;
    }
    else
    {
        for(i=0; i < 9; i++) ///vai ao inicio encontra o proximo tabuleiro disponivel
        {
            if(tab[i].preenchido == 0)
                return i;
        }
    }

}

