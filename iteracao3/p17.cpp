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

#define TESTE_NIVEL_1 0
#define MAX 10000
#define EPSILON 1e-9 
using namespace std;

/*Classe ponto*/
struct Ponto{
    double x = 0, y = 0;
    long int index = 0;
    struct Ponto& operator = (const pair<int, int>& p){
        x = p.first;
        y = p.second;
        return *this;
    }
    struct Ponto& operator = (const Ponto& p){
        x = p.x;
        y = p.y;
        index = p.index;
        return *this;
    }
};

/*Globais*/
Ponto pontos[MAX];

/*esquerda*/
bool esquerda(const Ponto& p1, const Ponto& p2, const Ponto pAvaliado){
    double det = (p1.x*p2.y + p1.y*pAvaliado.x + p2.x*pAvaliado.y) -
                 (p1.x*pAvaliado.y + p1.y*p2.x + p2.y*pAvaliado.x);
    /***/
    if(TESTE_NIVEL_1){
        cout << "ESQUERDA: Entrou com postos p1 = (" << p1.x << ","
            << p1.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << pAvaliado.x << "," << pAvaliado.y << ")" << endl;
    }
    /***/
   return det > 0; 
          
}

/*MergeSortG*/
int intercalaG(int l, int m, int r){
    Ponto aux[MAX];
    int p, q;
    /***/
    if(TESTE_NIVEL_1){
        cout << "INTERCALA: entrou com l= " << l
             << " m= " << m << " e r = " << r << endl;
    }
    /***/
    for(int i = l; i <= r; i++){
        aux[i] = pontos[i];
    }
    p = l;
    q = m + 1;
    for(int i = l; i <= r; i++){
        if(p > m){
            pontos[i] = aux[q];
            q++;
        }
        else if(q > r || esquerda(pontos[0], aux[p] ,aux[q])){
            pontos[i] = aux[p];
            p++;
        }
        else{
            pontos[i] = aux[q];
            q++;
        }
    }
    return 0;
}

int mergeSortG(int l, int r){
    int m = (l + r)/2;
    /***/
    if(TESTE_NIVEL_1){
        cout << "MERGESORTG: entrou com l= " << l
             << " e r = " << r << endl;
    }
    /***/
    if(l < r){
        mergeSortG(l, m);
        mergeSortG(m + 1,r);
        intercalaG(l,m,r);
    }
    return 0;
}

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
        pontos[i].index = i;
        if(y < pontos[minIndex].y)
            minIndex = i;
    }
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ") -> index = " << pontos[i].index << endl;
        }
        cout << "MAIN: MININDEX = " << minIndex << endl;
    }
    /***/
    aux = pontos[0];
    pontos[0] = pontos[minIndex];
    pontos[minIndex] = aux;

    /*sort*/
    mergeSortG(1, n - 1);
    
    /***/
    if(TESTE_NIVEL_1){
        cout << "DEPOIS DE ORDENADO" << endl;
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ") -> index = " << pontos[i].index << endl;
        }
    }
    /***/

    /*Saida*/
    cout << minIndex + 1 << " " << pontos[n/2].index + 1
        << endl;


    return 0;
}
