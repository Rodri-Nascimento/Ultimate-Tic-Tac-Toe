#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"




///Gerador de numeros aleatorios
int intUniformRnd(int a, int b){
    return a + rand()%(b-a+1); ///Devolve um valor inteiro aleatório distribuído uniformemente no intervalo [a, b].
}


///Menu
int menu()
{
    int x;

    do{
        printf("\n > Jogo entre Jogador x Computador ---- 1");
        printf("\n > Jogo entre Jogador1 x Jogador2 ----- 2");
        printf("\n > Retomar Jogo Anterior -------------- 3");
        printf("\n\n   Selecione uma opcao: ");
        scanf(" %d",&x);

        if(x < 4 && x > 0)
            break;
        else{
            fflush(stdin); ///caso o utilizador introduza uma string ou uma letra
        }

    }while(1);

    return x;
}


