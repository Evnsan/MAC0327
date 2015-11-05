/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Genie Bomber************/
/***********************************/
/***********Problema 11*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1
#define MAX 100


using namespace std;


struct Ponto{
    int x = 0, y = 0;

    double len(Ponto& p1){
        return sqrt(pow(x-p1.x,2.0) + pow(y-p1.y,2.0));
    } 
    
    struct Ponto& operator+=(const Ponto& p1){
        x += p1.x;
        y += p1.y;
        return *this;
    }
    struct Ponto& operator+=(const double& k){
        x += k;
        y += k;
        return *this;
    }
    struct Ponto& operator = (const pair<int, int>& p){
        x = p.first;
        y = p.second;
        return *this;
    }
};

Ponto operator+(Ponto p1, const Ponto& p2){
    return p1 += p2;
}
Ponto operator+(Ponto p1, const double& k){
    return p1 += k;
}
Ponto operator+(const double k, Ponto p1){
    return p1 += k;
}




/***GLOBAIS***/

/***main***/
int main(){
    int cid_n;   /*numero de cidades*/
    Ponto cidades[MAX];
    int max;
    int x, y;
    int bomb_r, cid_r;
    double distancia;
    Ponto cidA, cidB;
    Ponto p1, p2, p3;

    /*Entrada*/
    cin >> cid_n;
    for(int i = 0; i < cid_n; i++){
        cin >> x >> y;
        cidades[i] = make_pair(x,y);
    }
    cin >> bomb_r >> cid_r;

    
    /***/
    if(TESTE_NIVEL_1){
        cout << "CID_N: " << cid_n << endl;
        cout << "CID_R: " << cid_r << endl;
        cout << "BOMB_R: " << bomb_r << endl;
        for(int i = 0; i < cid_n; i++){
            cout << "CIDADE " << i << ": ("
                 << cidades[i].x << ","
                 << cidades[i].y << ")" << endl;
        }
    }
    /***/

    /*Processamento*/
    if(bomb_r > cid_r){
        max = 1;
        for(int i = 0; i < cid_n; i++){
            cidA = cidades[i];
            for( int j = i + 1; j < cid_n; j++){
                cidB = cidades[j];
            }
        }
    }
    else if(bomb_r == cid_r){
        max = 1;
    }
    else{
        max = 0;
    }
    cout << max << endl;

    /****************/
    
    p1.x = 1;
    p1.y = 6;

    p2.x = 1;
    p2.y = 1;

    p3 = p1 + p2;

    cout << "P1: " << p1.x << " " << p1.y << endl;
    cout << "P2: " << p2.x << " " << p2.y << endl;
    cout << "P3: " << p3.x << " " << p3.y << endl;

    cout << "LEN: " << p1.len(p2) << endl;



    return 0;
}
