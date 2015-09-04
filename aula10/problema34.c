/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 34*************/
/***********************************/

#include<stdio.h>
#define MAXN 30
#define MAXW 1000
#define TESTE_NIVEL_1 0 
#define TESTE_NIVEL_2 0 

int main(){
    int n, W, k;
    int t[MAXN+1][MAXW+1];
    int saida[MAXW+1];
    int nrecovered;
    int v[MAXN + 1], w[MAXN + 1], d[MAXN + 1];
    int a, b;

    /*controle*/
    int i, y;
    int primeiro;

    primeiro = 1;
    /*Entrada*/
    while(scanf("%d %d", &W, &k) == 2){
        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d %d", &d[i], &v[i]);
            w[i] = d[i]*3*k;
        }
        if(TESTE_NIVEL_1){
            printf("W = %d, k = %d, n = %d\n", W, k, n);
            printf("i => d[i] , v[i] , w[i]\n");
            for(i = 0; i <= n; i++){
                printf("%d => %d  , %d  , %d\n", i, d[i], v[i], w[i]);
            }
        }

        /*Processamento*/
        for(y = 0; y <= W; y++){
            t[0][W] = 0;
            for(i = 1; i <= n; i++){
                a = t[i - 1][y];
                if(w[i] > y)
                    b = 0;
                else
                    b = t[i - 1][y - w[i]] + v[i];
                if(a >= b)
                    t[i][y] = a;
                else{
                    t[i][y] = b;
                    }
            }
        }
        y = W;
        for(i = n; i > 0; i--){
            if( t[i][y] == t[i - 1][y] ) {
                saida[i] = 0;
            }
            else{
                saida[i] =1;
                y -= w[i];
            }
        }

        /*Saida*/
        if(!primeiro)
            printf("\n");
        primeiro = 0;
        printf("%d\n",t[n][W]);
        nrecovered = 0;
        for(i = 1; i <= n; i++){
            nrecovered += saida[i];
        }
        printf("%d\n", nrecovered);
        for(i = 1; i <= n; i++){
            if(saida[i])
                printf("%d %d\n", d[i], v[i]);
        }
    }

    return 0;
}
