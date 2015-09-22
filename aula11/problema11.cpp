/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***Problema  01 - segunda rodada***/
/***********************************/

#include<bits/stdc++.h>

#define MAX 100000
#define NMAX 20
#define TESTE_NIVEL_1 0
#define TESTE_NIVEL_2 0

using namespace std;

vector< vector<int> > p(2, vector<int>(NMAX*(MAX + 1), 0));
int n = 0;

int total;
int pmax;

/***main***/
int main(){
    int entrada;
    int anterior;
    float s;
    float min;

    /*Entrada*/
    cin >> n;

    cin >> entrada;
    total = entrada;
    pmax = entrada;
    p[0][entrada] = 1;
    p[0][0] = 1;
    anterior = 0;
    
    for(int i = 1; i < n; i++){
        cin >> entrada;
        total += entrada;
        if(entrada > pmax){pmax = entrada;}
        /***/
        if(TESTE_NIVEL_1){
            printf("Comecou elemento %d com anterior %d\n", entrada, anterior);
        }
        /***/
        for(int j = 0; j <= total; j++){
            if(p[anterior][j] == 1 
               || ( j - entrada >= 0) && p[anterior][j - entrada] == 1){
                /***/
                if(TESTE_NIVEL_1){
                    if(j == 32) {printf("Setou 32 com entrada = %d\n",
                            entrada);}
                    printf("Setou linha = %d e coluna %d\n", (anterior+1)%2 , j);
                }
                /***/
                p[(anterior+1)%2][j] = 1;
            }
        }
        /***/
        if(TESTE_NIVEL_1){
            printf("Terminou elemento %d com anterior %d\n", entrada, anterior);
        }
        /***/
        anterior = (anterior+1)%2;
    }
    /***/
    if(TESTE_NIVEL_2){
        printf("Atual = %d\n", anterior);
        printf("##Matriz P##\n");
        printf("  |");
        for(int i = 0; i <= total; i++){
            printf(" %2d", i);
        }
        printf("\n");
        for(int i = 0; i < 2; i++){
            printf("%2d| ", i);
            for(int j = 0; j <= total; j++){
                printf("%2d ", p[i][j]);
            }
            printf("\n");
        }
        printf("############\n");
    }
    /***/
    /*Processamento*/
    s = total/2.0;
    /***/
    if(TESTE_NIVEL_2){
        printf("Total = %d ==> s = %.2f\n", total, s);
        printf("Linha final = %d\n", anterior);
    }
    /***/
    min = s;
    for(int i = 0; i < int(s+1); i++){
        if(p[anterior][i] == 1 && (min > abs(s - i))){
            /***/
            if(TESTE_NIVEL_2){
            printf(" Min = %.1f, (s - i) = %.1f, i = %d\n",
                    min, abs(s-i), i);
            }
            /***/
            min = abs(s - i);
        }
    }
    /*Saida*/
    printf("%d\n", (int)(min * 2));
    return 0;
}
