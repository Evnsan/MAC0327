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

#define TESTE_NIVEL_1 0
#define MAX 100
#define PI 3.14159265
#define EPSILON 0.0000001
using namespace std;

/*Classe ponto*/
struct Ponto{
    int x = 0, y = 0;
    
    /*Metodos*/
    float norma(){
        return sqrt(pow(x, 2.0) + pow(y, 2.0));
    }
    double len(Ponto& p1){
        return sqrt(pow(x-p1.x,2.0) + pow(y-p1.y,2.0));
    }
    struct Ponto& rot(float graus){
        float radianos = graus*PI/180;
        float seno = sin(radianos);
        float cosseno = cos(radianos);
        int xant;

        if(seno <= EPSILON) seno = 0;
        if(cosseno <= EPSILON) cosseno = 0;
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.ROT: recebeu " << graus
                 << " e calculou seno=" << seno
                 << "; cosseno=" << cosseno << endl;
            cout << "PONTO.ROT: ponto antigo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        xant = x;
        x = cosseno*x - seno*y;
        y = seno*xant + cosseno*y;
        return *this;
    }

    struct Ponto& setIntensidade(float k){
        float norma = this->norma(); 
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.SETINTENSIDADE: recebeu " << k
                 << " e calculou norma=" << norma << endl;
            cout << "PONTO.SETINTENSIDADE: ponto antigo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        x = x/norma * k;
        y = y/norma * k;
        return *this;
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
    struct Ponto& operator-=(const Ponto& p1){
        x -= p1.x;
        y -= p1.y;
        return *this;
    }
    struct Ponto& operator-=(const double& k){
        x -= k;
        y -= k;
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
Ponto operator-(Ponto p1, const Ponto& p2){
    return p1 -= p2;
}
Ponto operator-(Ponto p1, const double& k){
    return p1 -= k;
}
Ponto operator-(const double k, Ponto p1){
    return p1 -= k;
}
/*Final da Classe ponto*/



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
    return 0;
}
