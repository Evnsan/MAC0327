/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/********Goat in the Garden*********/
/***********************************/
/************Problema 10************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 100
#define PI 3.1415926535


using namespace std;

/*****************/

/***main***/
int main(){
    int raio;
    int lado;
    double area;
    double segmentosCirc;
    double dSobre2r;

    /**Entrada**/
    cin >> lado >> raio;
    /**Processamento**/
    if(raio <= lado/2){
        area = raio*raio*PI;
    }
    else if(raio >= (lado/2)*sqrt(2)){
        area = lado * lado;
    }
    else{
        dSobre2r = (lado*1.0)/(2*raio);
        segmentosCirc = 2*raio*raio*(2*acos(dSobre2r)
                - sin(2*acos((dSobre2r))));

        area = raio*raio*PI - segmentosCirc;
    }
    /**Saida**/
    printf("%.3lf\n", area);


    return 0;
}
