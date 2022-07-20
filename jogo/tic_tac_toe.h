#ifndef TIC_TAC_TOE_H_INCLUDED
#define TIC_TAC_TOE_H_INCLUDED

typedef struct mini_tabuleiro{

    char m[3][3]; /**mini tabuleiros**/
    int preenchido; /**variavel que nos vai ajudar a ver se o tabuleiro já se encontra preenchido**/

}TAB;

typedef struct jogada{

    int x,y,ntab, jogador, modo_de_jogo, conta;
    char c;

    struct jogada *prox;

}NO;


///->> ajuda.c
void matriz_ajuda();
void ajuda();



///->> menu_e_random.c
int menu();
int intUniformRnd(int a, int b);



///->> imprimir_na_consola.c
void inicializar_tabuleiro(TAB *tab);
void imprime_mini_tabuleiro(TAB *tab, int k, int i);
void imprime_tabuleiro(TAB *tab);



///->> jogabilidade.c
NO* lercoordenadas(char c, int l, TAB *tab, int *ntab, NO* lista, int* conta, int automatico, int modo_jogo);
int verifica(int x, int y, TAB *tab, int *ntab, int automatico);
int proximo_tabuleiro(TAB *tab,int x, int y);
void guardar_jogada(NO* lista);



///->> funcoes_importantes.c
NO* adicionar_no(NO* lista, int x, int y, int* ntab, char c, int l, int* conta, int modo_jogo);
NO* recupera_lista_e_tabuleiro(NO* lista, TAB *tab, int* pmodo, int* conta);
int ultimas_jogadas(NO *lista, int* conta);
void liberta(NO *lista);



///->> vitorias.c
void tabuleiro_preenchido(TAB *tab,int* ntab, char c, int jogador);
int empate_tabuleiro_mini(TAB *tab, int* ntab);
int ganhou_por_linhas(TAB *tab,char c, int* ntab);
int ganhou_por_colunas(TAB *tab,char c, int* ntab);
int ganhou_por_diagonal_principal(TAB *tab,char c, int* ntab);
int ganhou_por_diagonal_secundaria(TAB *tab,char c, int* ntab);
void bloquear_tabuleiro(TAB *tab,char c, int* ntab);
int grande_vencedor(TAB *tab) ;



///->> final_do_jogo.c
void  guardar_ficheiro_texto(NO* lista);



///->> tic_tac_toe.c
int jogar(TAB *tab, int modo);

#endif // TIC_TAC_TOE_H_INCLUDED

