/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********NUSP  5388861************/
/***********************************/
/***********Problema 04*************/
/***********************************/

#include<stdio.h>

#define MAX 100000
#define TESTE 1

int main(){
    long int n;
    int entrada[MAX], acumulado[2][MAX];
    char c;

    /*controle*/
    long int i;

    /*Entrada*/
    scanf("%ld", &n);


    while(scanf("%c", &c) && c == '\n');
    entrada[0] = c - '0';
    if(entrada[0] == 1){
        acumulado[0][0] = 1;
        acumulado[1][0] = 0;
    }
    else{
        acumulado[0][0] = 0;
        acumulado[1][0] = 1;
    }
    
    for(i = 1; i < n; i++){
        while(scanf("%c", &c) && c == '\n');
        entrada[i] = c - '0';
        if(entrada[i] == 1){
            acumulado[0][i] = acumulado[0][i-1] + 1;
            acumulado[1][i] = acumulado[1][i-1];
        }
        else{
            acumulado[0][i] = acumulado[0][i-1];
            acumulado[1][i] = acumulado[1][i-1] + 1;
        }
    }

    /***/
    if(TESTE){
        for(i = 0; i < n; i++){
            printf("%d",entrada[i]);
        }
        printf("\n");
        for(i = 0; i < n; i++){
            printf("%d",acumulado[0][i]);
        }
        printf("\n");
        for(i = 0; i < n; i++){
            printf("%d",acumulado[1][i]);
        }
        printf("\n");
    }
    /***/


    /*Processamento*/

    /*Saida*/

    return 0;
}
