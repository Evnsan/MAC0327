/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********Computer Games II********/
/***********************************/
/*************Problema 13***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1
#define MAX 500

using namespace std;
/***GLOBAIS***/
int adj[MAX][MAX];


int maxMatch(){
    return 0;
}

int main(){
    int n;
    int k;
    int soma;
    int dif;
    int lvl[MAX];
    
    /*Entrada*/
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> lvl[i];
    }
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            cout << "MAIN: lvl[" << i << "] = " << lvl[i] << endl;
        }
    }
    /***/

    /*Pre-Processamento*/
    /*construindo Matriz de Adj*/
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            dif = lvl[i] - lvl[j];
            dif = abs(dif);
            cout << i << " " << j << " -> " << dif << endl;
            if(dif <= k && dif%2 == 1){
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
            else{
                adj[i][j] = 0;
                adj[j][i] = 0;
            }
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << "MAIN: adj[" << i << "][" << j << "] = " 
                     << adj[i][j] << endl;
            }
        }
    }
    /***/

    
    /*Processamento*/
    soma = maxMatch();
    
    /*saida*/
    cout << soma << endl;

    return 0;
}
