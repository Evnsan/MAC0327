/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*********Young Photographer********/
/***********************************/
/*************Problema 25***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 1001 


using namespace std;

int main(){
    int n, inicio, fim, x0;
    int pista[MAX];
    int max, min;
    int distAntes, distDepois;
    int tmp;

    /*Entrada e Processamento*/
    cin >> n >> x0;

    /*inicializacao da pista*/ 
    for(int i = 0; i < MAX; i++){
        pista[i] = 0;
    }
    max = 0;
    min = MAX;
    for(int i = 0; i < n; i++){
        cin >> inicio >> fim;
        if(fim < inicio){
            tmp = inicio;
            inicio = fim;
            fim = tmp;
        }
        if(inicio < min) min = inicio;
        if(fim > max) max = fim;
        for(int j = inicio; j <= fim; j++){
            pista[j] += 1;
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : pista " << min << "-" << max << endl;
        for(int i = min; i <= max; i++){
            cout << pista[i] << " ";
        }
        cout << endl;
    }
    /***/

    /*Processamento*/
    distAntes = MAX + 1;
    distDepois = MAX + 1;
    for(int i = min; i <= x0; i++){
            if(pista[i] == n){
                distAntes = i;
            }
    }
    for(int i = max; i >= x0; i--){
            if(pista[i] == n){
                distDepois = i;
            }
    }
    if(distAntes != MAX + 1){
        if(distDepois != MAX + 1){
            distAntes = x0 - distAntes;
            distDepois = distDepois - x0;
            if(distAntes < distDepois){
                cout << distAntes << endl;
            }
            else{
                cout << distDepois << endl;
            }
        }
        else{
            distAntes = x0 - distAntes;
            cout << distAntes << endl;
        }
    }
    else{
        if(distDepois != MAX + 1){
            distDepois = distDepois - x0;
            cout << distDepois << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    
    return 0;
}
