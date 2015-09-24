/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 09*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 100
#define TESTE_NIVEL_1 0

using namespace std;

vector<int> Dig_adj[MAX + 1];
int Dig_n = 0;

vector<int> pre(MAX + 1);
vector<int> pos(MAX + 1);
vector<int> tsi;

int conta;

int TSdfsR(int v){
    int w;
    pre[v] = 1; 
    for (auto a = Dig_adj[v].begin(); a != Dig_adj[v].end(); a++){
        w = *(a);
        /***/
        if(TESTE_NIVEL_1){
            printf("Iniciou o %d\n", v);
            printf("vai tentar o %d que tem pre= %d e pos = %d\n", w, pre[w], pos[w]);
        }
        /***/
        if (!pre[w]){
            if(!TSdfsR(w)){
                return 0;
            }
        }
        else
            if(!pos[w])
                return 0;
    }
    pos[v] = conta--;
    tsi.push_back(v);
    /***/
    if(TESTE_NIVEL_1){
        printf("Finalizou o %d\n", v);
    }
    /***/
    return 1;
}


int DIGts(){ 
 conta = Dig_n - 1;
 for (int v = 0; v <= Dig_n; v++){
     pre[v] = pos[v] = 0;
 }
 for (int v = 1; v <= Dig_n; v++)
    if (!pre[v]) 
        if(!TSdfsR(v))
            return 0;
return 1;
}

/***main***/
int main(){
    int entrada1;

    /*Entrada*/
    cin >> Dig_n;
    for(int i = 1; i <= Dig_n; i++){
        cin >> entrada1;
        while(entrada1 != 0){
            Dig_adj[i].push_back(entrada1);
            cin >> entrada1;
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("##Dig_adj##\n");
        for(int i = 0; i <= Dig_n; i++){
            for(auto a = Dig_adj[i].begin(); a != Dig_adj[i].end(); a++){
                printf("%d->%d\n", i , (*a));
            }
        }
        printf("###########\n");
    }
    /***/

    /*Processamento  -  Saida*/
    if(DIGts()){
        for(int i = Dig_n - 1; i >= 0; i--)
            printf("%d ", tsi[i]);
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");
    
    return 0;
}
