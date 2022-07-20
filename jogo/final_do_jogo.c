#include <stdio.h>
#include <string.h>
#include "tic_tac_toe.h"


void  guardar_ficheiro_texto(NO* lista)
{
    char nome[200], auxiliar,extensao[]=".txt";

    do{

        auxiliar = 0;

        printf("\n   Introduza um nome para o ficheiro de texto: ");
        scanf(" %200[^\n]", nome);

        for(int i = 0; nome[i] != '\0'; i++)
        {
            if(nome[i] == 92 ||  nome[i] == '/' || nome[i] == ':' || nome[i] == '*' || nome[i] == '?' || nome[i]== '"' || nome[i] == '<' || nome[i] =='>' || nome[i] == '|')
            {
                auxiliar = 1;
                break;
            }
        }

    }while(auxiliar);

    strcat(nome,extensao); ///concatnar o nome com a extensão

    FILE *file = fopen(nome,"w");
    NO* aux;

    if(file == NULL)
        printf("\n   Erro ao criar um ficheiro");
    else
    {
        aux = lista;

        while(aux != NULL)
        {
            fprintf(file,"> O Jogador %d, inseriu um %c com as coordenadas (%d,%d)  no tabuleiro %d\n\n",aux->jogador,aux->c,aux->x,aux->y,aux->ntab);
            aux = aux->prox;
        }

        printf("\n   Ficheiro salvo com sucesso!\n");


    }

    fclose(file);

}


