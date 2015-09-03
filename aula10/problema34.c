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

int main(){
    int n, W, k;
    int t[MAXN+1][MAXW+1];
    int saida[MAXN+1][MAXW+1];
    int nrecovered;
    int v[MAXN + 1], w[MAXN + 1], d[MAXN + 1];

    /*controle*/
    int i, y, j;

    /*Entrada*/

    /*Processamento*/
    for(y = 0; y < W; y++){
        t[0][w] = 0;
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
                for(j = 0; j <= n; j++){
                    saida[j][y] = saida[j][y - w[i]];
                }
                saida[i][y] = 1;
            }
        }
    }

    /*Saida*/
    printf("%d\n",t[n][W]);
    nrecovered = 0;
    for(i = 0; i <= n; i++){
        nrecovered += saida[i][W];
    }
    printf("%d\n", nrecovered);
    for(i = 0; i <= n; i++){
        if(saida[i][W])
            printf("%d %d\n", d[i], v[i]);
    }


    return 0;
}
