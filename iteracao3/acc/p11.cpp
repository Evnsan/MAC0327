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
#define PI 3.141592653589793
#define EPSILON 1e-9
using namespace std;

/*Classe ponto*/
struct Ponto{
    double x = 0, y = 0;
    
    /*Metodos*/
    double norma(){
        return sqrt(pow(x, 2.0) + pow(y, 2.0));
    }
    double len(Ponto& p1){
        return sqrt(pow(x-p1.x,2.0) + pow(y-p1.y,2.0));
    }
    struct Ponto& rot(double graus){
        double radianos = graus*PI/180;
        double seno = sin(radianos);
        double cosseno = cos(radianos);
        double xant;

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
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.ROT: ponto novo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        return *this;
    }

    struct Ponto& setIntensidade(double k){
        double norma = this->norma(); 
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
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.SETINTENSIDADE: ponto novo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        return *this;
    }
    
    int lexcmp(const Ponto& p1){
        /*
        cout << "LEXLESS: chegou c1=(" << x << ","
             << y << ") e c2=(" << p1.x << ","
             << p1.y << ")" << endl;
        */
        if(x != p1.x){
            return x - p1.x;
        }
        else{
           return y - p1.y;
        }
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

int compareMyType(const void* entrada1, const void* entrada2){
    Ponto p1, p2;
    p1 = *(Ponto*)entrada1;
    p2 = *(Ponto*)entrada2;

    return p1.lexcmp(p2);
}


/***GLOBAIS***/

/***main***/
int main(){
    int cid_n;   /*numero de cidades*/
    Ponto cidades[MAX];
    int max;
    int maxc1, maxc2;
    double x, y;
    int bomb_r, cid_r;
    Ponto d, c1, c2;
/*    
    double distancia;
*/
    Ponto cidA, cidB;

    /*Entrada*/
    cin >> cid_n;
    for(int i = 0; i < cid_n; i++){
        cin >> x >> y;
        cidades[i] = make_pair(x,y);
    }
    cin >> bomb_r >> cid_r;

    /*sort*/
    qsort(cidades, cid_n, sizeof(Ponto), compareMyType);

    
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
        bomb_r -= cid_r;
        max = 1;
        for(int i = 0; i < cid_n; i++){
            cidA = cidades[i];
            for( int j = i + 1; j < cid_n; j++){
                cidB = cidades[j];
                if(cidA.len(cidB) <= 2*bomb_r){
                    /***/
                    if(TESTE_NIVEL_1){
                        cout << "Avaliando cidades:" << endl;
                        cout << "  " << i << ": "
                             << "     CID(" << cidades[i].x << ","
                             << cidades[i].y << ")" << endl;
                        cout << "  " << j << ": " 
                             << "     CID(" << cidades[j].x << ","
                             << cidades[j].y << ")" << endl;
                        cout << " DISTANCIA= " << cidA.len(cidB) << endl;
                    }
                    /***/
                    d = cidB - cidA;
                    d.setIntensidade(d.norma()/2);
                    c1 = cidA + d;
                    /*
                        cout << "PROCESSAMENTO(parte1): c1 = (" << c1.x << ","
                             << c1.y << ")" << endl;
                             */
                    
                    d.rot(90);
                    d.setIntensidade(
                        sqrt(bomb_r*bomb_r - d.norma()*d.norma())
                    );
                    c2 = c1 -d;
                    c1 += d;
                    /***/
                    if(TESTE_NIVEL_1){
                        cout << "PROCESSAMENTO: d = (" << d.x << ","
                             << d.y << ")" << endl;
                        cout << "PROCESSAMENTO: c1 = (" << c1.x << ","
                             << c1.y << ")" << endl;
                        cout << "PROCESSAMENTO: c2 = (" << c2.x << ","
                             << c2.y << ")" << endl;
                    }
                    maxc1 = 0;
                    maxc2 = 0;
                    for(int k = 0; k < cid_n; k++){
                        double r1 = pow(cidades[k].x - c1.x , 2.0) + 
                                    pow(cidades[k].y - c1.y , 2.0);
                        double r2 = pow(cidades[k].x - c2.x , 2.0) + 
                                    pow(cidades[k].y - c2.y , 2.0);
                        if(r1 - bomb_r*bomb_r < EPSILON) maxc1++;
                        if(r2 - bomb_r*bomb_r < EPSILON) maxc2++;
                    }
                    if(maxc1 > max) max = maxc1;
                    if(maxc2 > max) max = maxc2;
                }
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
