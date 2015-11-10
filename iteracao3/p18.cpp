/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********Military Story***********/
/***********************************/
/***********Problema 18*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 4000
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
bool used[MAX + 1];
int n;

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

/*achaFechoConvexo*/
int proximoIndice(int atual){
    int prox = atual + 1;
    while(used[prox]){
        prox++;
    }
    if(prox < n)
        return prox;
    else
        return -1;
}

bool achaFechoConvexo(){
    vector<Ponto> pilha;
    int atual;
    atual = 0;
    if(used[0] || (atual = proximoIndice(0)) != -1){
        pilha.push_back(atual);
        if((atual = proximoIndice(atual)) != -1){
            pilha.push_back(atual);

    }

    return false;
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
    int minIndex;
    double x, y;
    Ponto aux;
    int achados;

    /*Entrada*/
    cin >> n;
    minIndex = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pontos[i] = make_pair(x,y);
        if(y < pontos[minIndex].y)
            minIndex = i;
        used[i] = false;
    }
    used[MAX] = false;
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

    /*sort*/
    mergeSortG(1, n - 1);
    
    /***/
    if(TESTE_NIVEL_1){
        cout << "DEPOIS DE ORDENADO" << endl;
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ")" << endl;
        }
    }
    /***/
    achados = 0;
    while(achaFechoConvexo()){
        achados++;
    }

    /*Saida*/
    cout << achados << endl;


    return 0;
}
