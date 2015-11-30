/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*********Number of Triplets********/
/***********************************/
/*************Problema 30***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define TESTE_NIVEL_2 0
#define MAX 3000 
#define INF 1001

using namespace std;

/*Ponto*/
typedef pair<int, int> Ponto;


Ponto achaPontoMedio(Ponto a, Ponto b){
    Ponto saida;
    saida.first = a.first + b.first;
    saida.second = a.second + b.second;
    /***/
    if(TESTE_NIVEL_1){
        cout << "ACHAPONTOMEDIO: soma = ("
             << saida.first << "," << saida.second
             << ")" << endl;
    }
    /***/
    if(saida.first % 2 != 0 || saida.second % 2 != 0){
        saida.first = INF;
        saida.second = INF;
    }
    else{
        saida.first /= 2;
        saida.second /= 2;
    }
    /***/
    if(TESTE_NIVEL_1){
        cout << "ACHAPONTOMEDIO: vai retornar ("
             << saida.first << "," << saida.second
             << ")" << endl;
        cout << "ACHAPONTOMEDIO: chegaram ("
             << a.first << "," << a.second 
             << ") e ("
             << b.first << "," << b.second
             << ")" << endl;
    }
    /***/
    return saida;
}

bool pontoIgual(Ponto a, Ponto b){
    /***/
    if(TESTE_NIVEL_1){
        cout << "PONTOIGUAL: chegaram ("
             << a.first << "," << a.second 
             << ") e ("
             << b.first << "," << b.second
             << ")" << endl;
        cout << "PONTOIGUAL: vai retornar "
             << (a.first == b.first && a.second == b.second)
             << endl;
    }
    /***/
    return (a.first == b.first && a.second == b.second);
}

int compara(const void * a, const void * b){
    Ponto p1 = *(Ponto*)a;
    Ponto p2 = *(Ponto*)b;
    if ( p1.first <  p2.first ) return -1;
    if ( p1.first >  p2.first ) return 1;
    if ( p1.second < p2.second ) return -1;
    if ( p1.second > p2.second ) return 1;
    return 0;
}

int comp(Ponto p1, Ponto p2){
    if ( p1.first <  p2.first ) return -1;
    if ( p1.first >  p2.first ) return 1;
    if ( p1.second < p2.second ) return -1;
    if ( p1.second > p2.second ) return 1;
    return 0;
}

/*GLOBAIS*/
Ponto pts[MAX];

bool buscaBin(Ponto t, int esq , int dir){
    int meio = (esq + dir) / 2;
    if(dir < esq){
        return false;
    }
    if(pontoIgual(pts[meio], t)){
        return true;
    }
    if(comp(pts[meio], t) == 1){
        return buscaBin(t, esq, meio - 1);
    }
    else{
        return buscaBin(t, meio + 1, dir);
    }
}
   

/*main*/
int main(){
    Ponto pteste;
    int n;
    int x, y;
    long int total;

    /*Entrada*/
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pts[i] = make_pair(x,y);
    }
    qsort(pts, n, sizeof(Ponto), compara);

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : " << endl;
        cout << "MAIN : pts" << endl;
        for(int i = 0; i < n; i ++){
           cout << "PTS[" << i << "]= (" << pts[i].first
                << "," << pts[i].second  << ")"<< endl; 
        }
    }
    /***/
    total = 0;
    /*Processamento*/
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pteste = achaPontoMedio(pts[i], pts[j]);
            if(pteste.first != INF){
                if(buscaBin(pteste, i, j)){
                    total++;
                }
            }
        }
    }

    /*Saida*/
    cout << total << endl;

    return 0;
}
