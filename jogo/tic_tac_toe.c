#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tic_tac_toe.h"


int jogar(TAB *tab, int modo)
{
    int jogador,aux = 0,aux2=0, aux3=0, numero_tab, w = 1, contador = 0, novo_modo;
    int x_prov, y_prov;
    int *ntab, *conta, *pmodo;
    NO* lista = NULL;
    NO* auxi;
    FILE *f = NULL;

    pmodo = &modo;
    conta = &contador;
    ntab = &numero_tab;

    jogador = rand()%2+1; /*** jogador vai variar entre 1 e 2 ***/

    inicializar_tabuleiro(tab); /**Colocar a matriz com - em todos os lugares**/


    if(modo == 3)
    {
        f = fopen("jogo.bin","rb"); ///só abre ficheiro se o utilzador quiser recuperar o jogo
        if(f == NULL) ///verificar se o ficheiro existe
        {
            printf("\n\n   Nao existe nenhum ficheiro de jogo anterior.\n");

            do{
                printf("\n   modo 1 ---> Jogo entre Jogador x Computador");
                printf("\n   modo 2 ---> Jogo entre Jogador1 x Jogador2");
                printf("\n\n   Selecione um modo de jogo: ");
                scanf(" %d",&novo_modo);

                if(novo_modo == 1 || novo_modo == 2)
                    break;
                else
                {
                    printf("\n   Instroduza uma opcao valida.\n");
                    fflush(stdin);
                }

            }while(1);

            if(novo_modo == 1)
                *pmodo = 1;
            else
                *pmodo = 2;

        }
        else
        {
            printf("\n ------------------------------------------------\n");
            printf("\n          Bem-Vindo de volta Jogador :)  !       \n");
            printf("\n ------------------------------------------------\n");

            lista = recupera_lista_e_tabuleiro(lista,tab,pmodo,conta);

            aux2 = 1;

        }

    }
    else
    {
        remove("jogo.bin");  /// caso o utilizador não queira retomar o jogo, removemos o ficehiro para não sobrepor jogadas

    }




    if(aux2 == 1) ///se existir algum ficheiro, se não nem vale a pena executar isto
    {
        auxi = lista;
        while(auxi != NULL)
        {
            x_prov = auxi->x;
            y_prov = auxi->y;
            jogador = auxi->jogador;
            auxi = auxi->prox;
        }

        aux3 = proximo_tabuleiro(tab,x_prov,y_prov);
        /**Descobrir a ultima posição, mas só fazemos isto se o modo selecionado for o 3 pq se não o modo é calculado de outra forma, ou seja tab 1 pq não há nada gravado**/
    }


    imprime_tabuleiro(tab);


    if(aux == 0)
    {
        if(aux2 == 1)
        {
            *ntab = aux3; ///começar na ultima jogada registada

            if(jogador == 1)
                jogador = 2;
            else
                jogador = 1;
        }
        else
        {
            *ntab = 0;  ///começar no mini tabueiro 0 caso não haja nenhum ficheiro ou jogar de novo
        }

        aux++;
        aux2++;
    }




    do{

        w = grande_vencedor(tab); ///chamar logo ao inicio pq dos ficehiros já existentes que se tiverem vitorias não vamos pedir coordenadas

        if(w == 0)
            break;

        if(jogador == 1)
        {

            if(modo == 1)
            {
                modo = 0;
                //o modo aqui será 1
                lista = lercoordenadas('X',1,tab,ntab,lista,conta,0,1); /** ntab vai variando de valores consoante as coordenadas inseridas

                                                                    na função lercoordenadas, esta dá return do novo valor***/
            }
            else
            {
                lista = lercoordenadas('X',1,tab,ntab,lista,conta,1,2);

            }

            jogador++;


        }
        else
        {

            lista = lercoordenadas('O',2,tab,ntab,lista,conta,1,modo);

            if(modo != 2)
                modo = 1;

            jogador = 1;
        }

        if(modo != 1)
            ultimas_jogadas(lista,conta); ///perguntar ao utilizador se deseja ver as k ultimas jogadas




    }while(1);



    ///após o final do jogo e de se ter um vencedor, perguntar nome ao uti para ficheiro text

    guardar_ficheiro_texto(lista);

    fclose(f);
    liberta(lista);

}



