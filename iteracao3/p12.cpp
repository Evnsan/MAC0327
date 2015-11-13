/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***************Trash***************/
/***********************************/
/*************Problema 12***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1
#define MAXN 150
#define MAXC 100
#define INF 15001
#define VAZIO -1


using namespace std;

/***GLOBAIS***/
int Ma[MAXN];        /*Par do vertice i do A*/
int Mb[MAXN];        /*Par do vertice j do B*/
int n;               /*n = |A| = |B| = |V|/2*/
int w[MAXN][MAXN];   /*peso*/
bool visA[MAXN];     /*v E A visitado*/
bool visB[MAXN];     /*v E B visitado*/

/***Metodo Hungaro***/
int temAumento(int i){
    int delta = INF;
    
    /*para cada vizinho j E B de i*/
    for(int j = 0; j < n; j++){
        /*que nao foi vizitado*/
        if(!visB[j]){
            if(y[i] + z[j] == w[i][j] || temAumento(Mb[j]) == INF){
                Ma[i] = j;
                Mb[j] = i;
                return INF;
            }
            else if(y[i] + z[j] - w[i][j] < delta){
                delta = y[i] +z[j] - w[i][j];
            }
        }
    }
    
    return delta;
}

/*inicializacao*/
int inicializaHungaro(){
    for(int i = 0; i < n; i++){
        Ma[i] = VAZIO;
        Mb[i] = VAZIO;
        visA[i] = false;
        visB[i] = false;
        y[i] = 0;
        z[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(y[i] < w[i][j])
                y[i] = w[i][j];
        }
    }
    return 0;
}

/*Emparelhamento perfeito?*/
bool perfeitoHungaro(){
    return false;
}

/*vertice é livre?*/
bool livreA(int i){
    return Ma[i] == VAZIO;
}

/*MetodoHungaro - peso máximo*/
int hungaroN4(){
    int delta;

    inicializaHungaro();
    while(!perfeitoHungaro){
        for(int i = 0; i < n; i++){
            if(livreA(i)){
                delta = temAumento(i);
                if(delta < INF){
                    for(int i = 0; i < n; i++){
                        if(visA[i]){
                            y[i] = y[i] - delta;
                        }
                        if(visB[i]){
                            z[i] = z[i] + delta;
                        }
                    }
                }
            }
        }
    }
    return 0;
}



int main(){
    
    /*Entrada*/
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << "MAIN: w[" << i << "]["
                     << j <<"]= " << w[i][j] << endl;
            }
        }
    }
    /***/

    /*Processamento*/
    return 0;
}
