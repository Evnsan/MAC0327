/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 06*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 100
#define TESTE_NIVEL_1 0

using namespace std;

/***main***/
int main(){
    int taxaOut, nEntradas;
    int entrada;
    int total; 
    
    /*Entrada*/
    cin >> taxaOut >> nEntradas;
    total = 0;
    for(int i = 0; i < nEntradas; i++){
        cin >> entrada;
        total += entrada;
        total -= taxaOut;
        if(total < 0){ total = 0; }
    }

    /*Saida*/
    printf("%d\n", total);
    
    return 0;
}
