/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 15*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 2000
#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 1

using namespace std;

vector<int> Dig_adj[MAX + 1];
int Dig_n = 0;

vector<int> pre(MAX + 1);
vector<int> parent(MAX + 1);
vector<int> low(MAX + 1);
queue<pair<int,int> > componente;

int conta;

unsigned long int BCCr(int v){
    int w;
    low[v] = pre[v] = ++conta;
    unsigned long int retorno = 0;
    int filhos = 0;
    pair<int, int> aresta;

    for (auto a = Dig_adj[v].begin(); a != Dig_adj[v].end(); a++){
        w = *(a);
        /***/
        if(TESTE_NIVEL_2){
            printf("Iniciou o %d\n", v);
            printf("vai tentar o %d que tem pre= %d e low = %d\n",
                   w, pre[w], low[w]);
        }
        /***/
        if (pre[w] == -1){
            filhos++;
            parent[w] = v;
            componente.push(make_pair(v, w));
            retorno += BCCr(w);
            low[v] = min(low[v], low[w]);

            if( (pre[v] == 1 && filhos > 1) || (pre[v] > 1 && low[w] >= pre[v]) ){
                cout << "vamos ver o pre de " << componente.front().first << endl;
                while(pre[componente.front().first] != low[w]){
                    /*criar novo grafo*/
                    aresta = componente.front();
                    componente.pop();
                    /***/
                    if(TESTE_NIVEL_1){
                        cout << aresta.first << "---" << aresta.second << " ";
                    }
                    /***/
                    /*colocar aresta no grafo*/
                }
                aresta = componente.front();
                componente.pop();
                /***/
                if(TESTE_NIVEL_1){
                    cout << aresta.first << "---" << aresta.second << " ";
                    cout << endl;
                }
                /***/
                /*colocar aresta v-w no grafo*/
                /*chamar Karger-Stein para o grafo*/
                /*retorno += karger*/
            }
        }
        else if(w != parent[v] && pre[w] < low[v]){
            low[v] = min(low[v], pre[w]);
            componente.push(make_pair(v, w));
        }

    }
    /***/
    if(TESTE_NIVEL_2){
        printf("Finalizou o %d\n", v);
    }
    /***/
    return retorno;
}


unsigned long int waysCount(){ 
    unsigned long int retorno = 0;
    pair<int, int> aresta;

    conta = 0;

    for (int v = 1; v <= Dig_n; v++){
        pre[v] = low[v] = parent[v] = -1;
    }
    for (int v = 1; v <= Dig_n; v++){
        if (pre[v] == -1)
            retorno += BCCr(v);
        if(!componente.empty()){
            if( componente.size() > 1){
                while(!componente.empty()){
                    /*cria grafo biconexo*/
                    aresta = componente.front();
                    componente.pop();
                    /***/
                    if(TESTE_NIVEL_1){
                        cout << aresta.first << "---" << aresta.second << " ";
                    }
                    /***/
                    /*colocar aresta no grafo*/
                }
                aresta = componente.front();
                componente.pop();
                /***/
                if(TESTE_NIVEL_1){
                    cout << aresta.first << "---" << aresta.second << " ";
                    cout << endl;
                }
                /***/
                /*roda karger-stein*/
                /*retorno += karger*/
            }
            else{
                aresta = componente.front();
                componente.pop();
                /***/
                if(TESTE_NIVEL_1){
                    cout << aresta.first << "---" << aresta.second << " ";
                    cout << endl;
                }
                /*contar quantos cortes*/
                /*retorno += conta*/
            }
        }
    }
    return retorno;
}

/***main***/
int main(){
    int entrada1, entrada2;
    long int m;

    /*Entrada*/
    cin >> Dig_n;
    cin >> m;
    for(long int i = 1; i <= m; i++){
        cin >> entrada1 >> entrada2;
        Dig_adj[entrada1].push_back(entrada2);
        Dig_adj[entrada2].push_back(entrada1);
    }
    /***/
    if(TESTE_NIVEL_2){
        printf("##Dig_adj##\n");
        for(int i = 0; i <= Dig_n; i++){
            for(auto a = Dig_adj[i].begin(); a != Dig_adj[i].end(); a++){
                printf("%d->%d\n", i , (*a));
            }
        }
        printf("###########\n");
    }
    /***/
    cout << waysCount();
    /*Processamento  -  Saida*/
/*    if(DIGts()){
        for(int i = Dig_n - 1; i >= 0; i--)
            printf("%d ", tsi[i]);
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");
  */  
    return 0;
}
