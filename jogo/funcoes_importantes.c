#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"


NO* adicionar_no(NO* lista, int x, int y, int* ntab, char c, int l, int* conta, int modo_jogo)
{
    NO *novo = malloc(sizeof(NO));

    if(novo == NULL)
    {
        printf("\nErro de alocacao!");
        return lista;
    }

    (*conta)++; ///incrementar o conta pq estamos a adicionar mais um no e vai dar jeito saber quantos nos temos no total

    novo->x = x;
    novo->y = y;
    novo->jogador = l;
    novo->c = c;
    novo->ntab = (*ntab);
    novo->conta = *conta;
    novo->modo_de_jogo = modo_jogo;



    if(lista == NULL) ///caso a lista esteja vazia
    {
        novo->prox = NULL;
        lista = novo;
    }
    else
    {
        NO *aux = lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        novo->prox = NULL;
        aux->prox = novo;
    }

    guardar_jogada(novo);

    return lista;
}




/********************************** REUPERAR LSITAS *************************************************************/

NO* recupera_lista_e_tabuleiro(NO* lista, TAB *tab, int* pmodo, int* conta)
{
    FILE *file = fopen("jogo.bin","rb");

    int *a;


    if(file)
    {

        while(!feof(file))
        {

            NO* novo = malloc(sizeof(NO));

             if(novo == NULL){
                printf("\n ERRO ALOCACAO!");
                fclose(file);
                return lista;
             }

                if(fread(novo,sizeof(NO),1,file))
                {

                    if(lista == NULL) ///caso a lista esteja vazia
                    {
                        lista = novo;
                        novo->prox = NULL;

                    }
                    else
                    {
                        NO *aux = lista;

                        while(aux->prox != NULL){
                            aux = aux->prox;
                        }

                        novo->prox = NULL;
                        aux->prox = novo;
                    }


                    tab[novo->ntab].m[novo->x][novo->y]  = novo->c; ///alterar o tabuleiro inicia

                    *a = novo->ntab; ///passar este valor para um ponteiro pois na função o parametro que recebe
                                     /// é do tipo ponteiro

                    tabuleiro_preenchido(tab,a,novo->c,novo->jogador);

                    *pmodo = novo->modo_de_jogo;

                    *conta = novo->conta;  ///para sabermos quantos nós temos até ao momento
                }


        }

    }
    else
    {
        printf("\n   Erro, nao foi encontrado nenhum ficheiro");

    }

    fclose(file);
    return lista;

}


/********************************** Ultimas Jogadas *******************************************************************/

int ultimas_jogadas(NO *lista, int* conta)
{
    int k,m,aux, i=0;
    NO *inicio = lista;
    char letra;


    do{
        printf("\n   Deseja ver as ultimas k jogadas ?(1-SIM/0-NAO) ");
        scanf(" %d",&m);

        if(m == 1 || m == 0)
            break;
        else
        {
            printf("\n   Introduza um numero valido\n");  ///verificar se o utilizador introduziu um dos numeros pedidos

            fflush(stdin);
        }

    }while(1);

    if(m == 0)
    {
        return 0;
    }
    else
    {
        do{
            printf("\n   Introduza um valor para k no intervalo de 1 a 10: ");
            scanf(" %d",&k);

            if(k>0 && k <= 10)
                break;
            else
            {
                printf("\n   Introduza um numero valido\n");  ///verificar se o utilizador introduziu um nuemro
                fflush(stdin); ///limpar o buffer
            }

        }while(1);


        aux = *(conta) - k; ///o aux vai nos ajudar a saber a partir de que jogada queremos mostrar ao utilizador
        int aux2=0;


        if(aux <= 0)  ///mostra todos os nos pq o uti quer ver mais nos do que aqueles que existem
        {
               while(inicio != NULL)
               {
                   if(i == 10)
                     break;
                   printf("\n   O Jogador %d colocou o caracter %c no tabuleiro numero %d na posicao (%d,%d)", inicio->jogador,inicio->c,(inicio->ntab)+1,inicio->x,inicio->y);

                   inicio = inicio->prox;

                   i++;

               }

        }
        else ///temos nós suficientes para mostrar, convem mostar do mais recente- x jogadas atras, a não contar da mais antiga ou seja da mais recente x para tras
        {
            while(inicio != NULL) ///so começa a mostrar quando estivermos na "posição" de lista certa
            {
                  if(aux2 >= aux)
                  {
                      printf("\n   O Jogador %d colocou o caracter %c no tabuleiro numero %d na posicao (%d,%d)", inicio->jogador,inicio->c,(inicio->ntab)+1,inicio->x,inicio->y);

                  }

                  inicio = inicio->prox;
                  aux2++;

             }

        }

    }
    return 1;
}



///Libertar os nós criados


void liberta(NO *lista)
{
    NO *aux;

    while(lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

}

///Após cada jogada é importatne guardar a mesma no ficheiro para assim mais tarde a recuperar

void guardar_jogada(NO* novo) //chamamos esta função quando estamos a criar o no para ele ficar logo guardado e  não termos de percorer a lista
{
    FILE *file = fopen("jogo.bin","ab");

    if(file)
    {
        fwrite(novo, sizeof(NO),1,file);

    }
    else
    {
        printf("\nErro na abertura do ficheiro para guardar jogo!");
    }

    fclose(file);
}

