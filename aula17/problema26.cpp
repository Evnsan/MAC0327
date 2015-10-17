/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 26*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0

#define INF 5

using namespace std;

int gameOver(char tabuleiro[10]){
    if(tabuleiro[0] != '#'){
        if((tabuleiro[0] == tabuleiro[1] and tabuleiro[0] == tabuleiro[2]) ||
           (tabuleiro[0] == tabuleiro[4] and tabuleiro[0] == tabuleiro[8]) ||
           (tabuleiro[0] == tabuleiro[3] and tabuleiro[0] == tabuleiro[6])   ){
            return 1;
        }
    }
    if(tabuleiro[4] != '#'){
        if((tabuleiro[1] == tabuleiro[4] and tabuleiro[4] == tabuleiro[7]) ||
           (tabuleiro[2] == tabuleiro[4] and tabuleiro[4] == tabuleiro[6]) ||
           (tabuleiro[3] == tabuleiro[4] and tabuleiro[4] == tabuleiro[5])   ){
            return 1;
        }
    }
    if(tabuleiro[8] != '#'){
        if((tabuleiro[2] == tabuleiro[5] and tabuleiro[2] == tabuleiro[8]) ||
           (tabuleiro[6] == tabuleiro[7] and tabuleiro[6] == tabuleiro[8])   ){
            return 1;
        }
    }
    for(int i = 0; i < 9; i++){
        if( tabuleiro[i] == '#'){
            return 0;
        }
    }

    return 1;
}

int valor(char tabuleiro[10]){
    if(tabuleiro[0] != '#'){
        if((tabuleiro[0] == tabuleiro[1] and tabuleiro[0] == tabuleiro[2]) ||
           (tabuleiro[0] == tabuleiro[4] and tabuleiro[0] == tabuleiro[8]) ||
           (tabuleiro[0] == tabuleiro[3] and tabuleiro[0] == tabuleiro[6])   ){
            return (tabuleiro[0] == 'X') ? 1 : -1;
        }
    }
    if(tabuleiro[4] != '#'){
        if((tabuleiro[1] == tabuleiro[4] and tabuleiro[4] == tabuleiro[7]) ||
           (tabuleiro[2] == tabuleiro[4] and tabuleiro[4] == tabuleiro[6]) ||
           (tabuleiro[3] == tabuleiro[4] and tabuleiro[4] == tabuleiro[5])   ){
            return (tabuleiro[4] == 'X') ? 1 : -1;
        }
    }
    if(tabuleiro[8] != '#'){
        if((tabuleiro[2] == tabuleiro[5] and tabuleiro[2] == tabuleiro[8]) ||
           (tabuleiro[6] == tabuleiro[7] and tabuleiro[6] == tabuleiro[8])   ){
            return (tabuleiro[8] == 'X') ? 1 : -1;
        }
    }
    return 0;
}

int alphaBeta(char tabuleiro[10], int alpha, int beta, char vez){
    char novoTab[10];
    int score, best;
    bool pruning = false;

    /***/
    if(TESTE_NIVEL_1){
        printf("[ALPHABETA] Chegou o tabuleiro = %s\n", tabuleiro);
    }
    /***/

    if(gameOver(tabuleiro)){
        /***/
        if(TESTE_NIVEL_1){
            printf("[ALPHABETA - GameOver] Vai retornar = %d\n",
                    valor(tabuleiro));
        }
        /***/
        return valor(tabuleiro);
    }
    if(vez == 'X'){
        best = -INF ;
    
        for(int i = 0; i < 9 && !pruning; i++){
            if(tabuleiro[i] == '#'){
                strcpy(novoTab, tabuleiro);
                novoTab[i] = vez;
                /***/
                if(TESTE_NIVEL_1){
                    printf("[ALPHABETA] %s\n", novoTab);
                }
                /***/
                score =  alphaBeta(novoTab, alpha, beta, 'O');
                if(best < score) best = score;
                if(alpha < best) alpha = best;
                if(beta <= alpha) pruning = true;
            }
        }
    }
    else{
        best = INF ;
    
        for(int i = 0; i < 9 && !pruning; i++){
            if(tabuleiro[i] == '#'){
                strcpy(novoTab, tabuleiro);
                novoTab[i] = vez;
                /***/
                if(TESTE_NIVEL_1){
                    printf("[ALPHABETA] %s\n", novoTab);
                }
                /***/
                score =  alphaBeta(novoTab, alpha, beta, 'X');
                if(best > score) best = score;
                if(alpha > best) alpha = best;
                if(beta <= alpha) pruning = true;
            }
        }
    }

    /***/
    if(TESTE_NIVEL_1){
        printf("[ALPHABETA] Vai retornar = %d\n", best);
    }
    /***/
        
    return best;
}


/*****************/

/***main***/
int main(){
    char tabuleiro[10];
    int res;
    for(int i = 0; i < 9; i++){
        scanf(" %c",&tabuleiro[i]);
    }
    tabuleiro[9] = '\0';
    /***/
    if(TESTE_NIVEL_1){
        printf("[MAIN] Tabuleiro de entrada: %s\n", tabuleiro);
    }
    /***/
    res = alphaBeta(tabuleiro, -INF, INF,'X');
    if(res == 1){
        printf("Crosses win\n");
    }
    else if(res == -1){
        printf("Ouths win\n");
    }
    else{
        printf("Draw\n");
    }

    /***/
    if(TESTE_NIVEL_1){
        printf("[MAIN] res = %d\n", res);
    }
    /***/
    return 0;
}
