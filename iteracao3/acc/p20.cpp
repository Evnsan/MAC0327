/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Counting Rhombi*********/
/***********************************/
/*************Problema 20***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 4000


using namespace std;

int main(){
    int dimensao[2];
    long long int soma;
    int minx, miny;
    
    /*Entrada*/
    cin >> dimensao[0];
    cin >> dimensao[1];
    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN: dimensao[0] = " << dimensao[0] << endl;
        cout << "MAIN: dimensao[1] = " << dimensao[1] << endl;
    }
    /***/

    /*Processamento*/
    soma = 0;
    if(dimensao[0] > 1 && dimensao[1] > 1){
        for(int i = 1; i < dimensao[0]; i++){
            for(int j = 1; j < dimensao[1]; j++){
                if(i < dimensao[0] - i)
                    minx = i;
                else
                    minx = dimensao[0] - i;
                if(j < dimensao[1] - j)
                    miny = j;
                else
                    miny = dimensao[1] - j;
                soma += miny*minx;
            }
        }
    }


    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN: soma = " << soma << endl;
    }
    /***/

   
    cout << soma << endl;

    return 0;
}
