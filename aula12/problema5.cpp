/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 05*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 10000
#define TESTE_NIVEL_1 0

using namespace std;

/***main***/
int main(){
    int inicioP, inicioT, taxaP, taxaT;
    int lanceP, lanceT;
    int rodadas;
    
    /*Entrada*/
    cin >> inicioP >> taxaP;
    cin >> inicioT >> taxaT;

    /*processamento*/
    if(inicioT < inicioP)
        rodadas = 0;
    else
        rodadas = (inicioT - inicioP) / (taxaP + taxaT);
    lanceP = inicioP + rodadas*taxaP;
    lanceT = inicioT - rodadas*taxaT;

    /***/
    if(TESTE_NIVEL_1){
        printf("rodadas = %d\n", rodadas);
        printf("lanceP = %d\n", lanceP);
        printf("lanceT = %d\n", lanceT);
    }
    /***/

    /*Saida*/
    if(lanceP >= lanceT)
        printf("%d\n", lanceP);
    else if( lanceP + taxaP > lanceT)
        printf("%d\n", lanceT);
    else
        printf("%d\n", lanceP + taxaP);
    
    return 0;
}
