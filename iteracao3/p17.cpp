/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/********Median on the plane********/
/***********************************/
/***********Problema 17*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1
#define MAX 10000
#define EPSILON 1e-9 
using namespace std;

/*Classe ponto*/
struct Ponto{
    double x = 0, y = 0;
    struct Ponto& operator = (const pair<int, int>& p){
        x = p.first;
        y = p.second;
        return *this;
    }
    struct Ponto& operator = (const Ponto& p){
        x = p.x;
        y = p.y;
        return *this;
    }
};

/*Globais*/
Ponto pontos[MAX];

/*MergeSortG*/
int mergesortG(int tam){
    if(




/***main***/
int main(){
    int n;
    int minIndex;
    double x, y;
    Ponto aux;

    /*Entrada*/
    cin >> n;
    minIndex = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pontos[i] = make_pair(x,y);
        if(y < pontos[minIndex].y)
            minIndex = i;
    }
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ")" << endl;
        }
        cout << "MAIN: MININDEX = " << minIndex << endl;
    }
    /***/
    aux = pontos[0];
    pontos[0] = pontos[minIndex];
    pontos[minIndex] = aux;

    mergeSortG(n);
    /***/
    if(TESTE_NIVEL_1){
        cout << "DEPOIS DE ORDENADO" << endl;
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ")" << endl;
        }
    }

    /*sort*/

    return 0;
}
