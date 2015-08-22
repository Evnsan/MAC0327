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
#define JOG1 0
#define JOG2 1

int main(){
    long int n;
    int entrada[MAX], saida[2][MAX], acumulado[2][MAX];
    char c;
    int vencedor, pontosMax, setsJogador1, setsJogador2, fimSetAnterior;
    int indice[2];

    /*controle*/
    long int i;

    /*Entrada*/
    scanf("%ld", &n);


    while(scanf("%c", &c) && c == '\n');
    entrada[0] = c - '0';
    if(entrada[0] == 1){
        acumulado[JOG1][0] = 1;
        acumulado[JOG2][0] = 0;
    }
    else{
        acumulado[JOG1][0] = 0;
        acumulado[JOG2][0] = 1;
    }
    
    for(i = 1; i < n; i++){
        while(scanf("%c", &c) && c == '\n');
        entrada[i] = c - '0';
        if(entrada[i] == 1){
            acumulado[JOG1][i] = acumulado[JOG1][i-1] + 1;
            acumulado[JOG2][i] = acumulado[JOG2][i-1];
        }
        else{
            acumulado[JOG1][i] = acumulado[JOG1][i-1];
            acumulado[JOG2][i] = acumulado[JOG2][i-1] + 1;
        }
    }

    if(entrada[n-1] == 1){
        vencedor = JOG1;
        pontosMax = acumulado[JOG1][n - 1];
    }
    else{
        vencedor = JOG2;
        pontosMax = acumulado[JOG2][n - 1];
    }

    /***/
    if(TESTE){
        for(i = 0; i < n; i++){
            printf("%d",entrada[i]);
        }
        printf("\n");
        for(i = 0; i < n; i++){
            printf("%d",acumulado[JOG1][i]);
        }
        printf("\n");
        for(i = 0; i < n; i++){
            printf("%d",acumulado[JOG2][i]);
        }
        printf("\n");
    }
    /***/


    /*Processamento*/
    for(i = pontosMax; i > 0; i++){
       /*verifica se jogo de i pontos e valido*/
        setsJogador1 = 0;
        setsJogador2 = 0;
        fimSetAnterior = 0;
        procura = acumulado[JOG1][fimSetAnterior] + i;
        indice[JOG1] = achaprox(acumulado, JOG1, procura);
        procura = acumulado[JOG2][fimSetAnterior] + i;
        indice[JOG2] = achaprox(acumulado, JOG2, procura);
        /*verificar se com t = i, o jogo termina com o set final para o vencedor e o vencedor termina com mais sets.*/
        /**sim* - adiciona [sets do vencedor] [i] no vetor saida*/



    }


    /*Saida*/
    /*retorna jogos validos em ordem crescente [sets] [points]*/

    return 0;
}
