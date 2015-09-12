/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 24*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 100001

using namespace std;

vector<int> Dig_adj[MAX];
int Dig_n = 0;

vector<int> pre(MAX);
vector<int> pos(MAX);
vector<int> tsi;

int conta;

int TSdfsR(int v){
    int w;
    pre[v] = 1; 
    for (auto a = Dig_adj[v].begin(); a != Dig_adj[v].end(); a++){
        w = *(a); 
        if (!pre[w])
            TSdfsR(w);
        else
            if(!pos[w])
                return 0;
    }
    pos[v] = conta--;
    tsi.push_back(v);
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
    int m;
    int entrada1, entrada2;

    /*controle*/
    int i;

    /*Entrada*/
    cin >> Dig_n >> m;
    while(Dig_n != 0 && m != 0){

        for(i = 0; i < m; i++){
            cin >> entrada1 >> entrada2;
            Dig_adj[entrada1].push_back(entrada2);
        }
    
        /*Processamento  -  Saida*/
        if(DIGts()){
            for(int i = Dig_n - 1; i >= 0; i--)
                printf("%d\n", tsi[i]);
        }
        else
            printf("IMPOSSIBLE\n");
    
        cin >> Dig_n >> m;
    }
    return 0;
}
