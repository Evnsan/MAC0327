/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/************Four Segments**********/
/***********************************/
/*************Problema 25***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1
#define MAX 10e9 

struct Ponto{
    long int x, y;
};
struct Reta{
    Ponto p1, p2;
    char paralelo;

    struct Reta& setParalelo(){
        if(p1.x == p2.x && p1.y != p2.y)
            paralelo = 'y';
        else if(p1.y == p2.y && p1.x != p2.x)
            paralelo = 'x';
        else
            paralelo = 'f';
        return *this;
    }
};


using namespace std;

int main(){
    Reta r[4];
    long int x, y;

    /*Entrada*/
    for(int i = 0; i < 4; i++){
        cin >> x >> y;
        r[i].p1.x = x;
        r[i].p1.y = y;
        cin >> x >> y;
        r[i].p2.x = x;
        r[i].p2.y = y;
        r[i].setParalelo();
    }

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : retas" << endl;
        for(int i = 0; i < 4 ; i++){
            cout << "Reta " << i << ": ("
                 << r[i].p1.x << "," 
                 << r[i].p1.y << ") --> (" 
                 << r[i].p2.x << "," 
                 << r[i].p2.y << ") e paralelo ao eixo "
                 << r[i].paralelo << endl;
        }
    }
    /***/

    /*Processamento*/
    return 0;
}
