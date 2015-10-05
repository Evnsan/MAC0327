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
#define TESTE_NIVEL_2 0

using namespace std;

vector<int> Dig_adj[MAX + 1];
int Dig_n = 0;
long int m; /*m arestas*/

/*Karger-Stein (unioni-find)*/
vector<pair<int, int> > KS_edgs;
/*Obs.: swap(v[n], v.back());
      v.pop_back();*/
vector<int> KS_vert[MAX + 1];
int KS_n = 0;

vector<int> pre(MAX + 1);
vector<int> parent(MAX + 1);
vector<int> low(MAX + 1);
stack<pair<int,int> > componente;
int bridges;

int conta;

unsigned long int BCCr(int v){
    int w;
    low[v] = pre[v] = ++conta;
    unsigned long int retorno = 0;
    int filhos = 0;
    pair<int, int> aresta;
    int tamanho = 0;

    /***/
    if(TESTE_NIVEL_2){
        printf("Iniciou o %d\n", v);
    }
    /***/
    for (auto a = Dig_adj[v].begin(); a != Dig_adj[v].end(); a++){
        w = *(a);
        /***/
        if(TESTE_NIVEL_2){
            printf("vai tentar o %d que tem pre= %d e low = %d\n",
                   w, pre[w], low[w]);
        }
        /***/
        if (pre[w] == -1){
            filhos++;
            parent[w] = v;
            aresta = make_pair(v, w);
            componente.push(aresta);
            /***/
            if(TESTE_NIVEL_2){
                cout << "adicionada a aresta " << componente.top().first << "---" << componente.top().second << endl;
            }
            /***/
            retorno += BCCr(w);
            low[v] = min(low[v], low[w]);

            if( (pre[v] == 1 && filhos > 1) || (pre[v] > 1 && low[w] >= pre[v]) ){
                /***/
                if(TESTE_NIVEL_2){
                    cout << "=>entrou com " << v << "---" << w << endl;
                    cout << "==>vai comparar: " << componente.top().first << "---" <<componente.top().second << endl;
                }
                /***/
                tamanho = 0;
                while(componente.top().first != v || componente.top().second != w){
                    /***/
                    if(TESTE_NIVEL_2){
                        cout << "==>comparou: " << componente.top().first << "---" <<componente.top().second << endl;
                    }
                    /***/
                    /*criar novo grafo*/
                    tamanho++;
                    aresta = componente.top();
                    componente.pop();
                    /*adiciona aresta e defini vert.*/
                    KS_edgs.push_back(aresta);
                    KS_vert[aresta.first] = aresta.first;
                    KS_vert[aresta.second] = aresta.second;
                    /***/
                    if(TESTE_NIVEL_2){
                        cout << "==>vai comparar: " << componente.top().first << "---" <<componente.top().second << endl;
                    }
                    /***/
                    /***/
                    if(TESTE_NIVEL_1){
                        cout << aresta.first << "---" << aresta.second << " ";
                    }
                    /***/
                    /*colocar aresta no grafo*/
                }
                tamanho++;
                aresta = componente.top();
                componente.pop();
                /*adiciona aresta e defini vert.*/
                KS_edgs.push_back(aresta);
                KS_vert[aresta.first] = aresta.first;
                KS_vert[aresta.second] = aresta.second;
                /***/
                if(TESTE_NIVEL_1){
                    cout << aresta.first << "---" << aresta.second << " ";
                    if(tamanho == 1)
                        cout << "bridge!";
                    cout << endl;
                }
                /***/
                /***/
                if(TESTE_NIVEL_2){
                    cout << "=>saiu com " << v << "---" << w << endl;
                }
                /***/
                if(tamanho == 1){
                    bridges++;
                }
                else{
                    /*chamar Karger-Stein para o grafo*/
                    KS_n = tamanho;
                    retorno += karger_stein();
                }
                /*Redefine estruturas KS*/
                KS_edgs.clear();
            }
        }
        else if(w != parent[v] && pre[w] < low[v]){
            low[v] = min(low[v], pre[w]);
            componente.push(make_pair(v, w));
            /***/
            if(TESTE_NIVEL_2){
                cout << "adicionada a aresta " << componente.top().first << "---" << componente.top().second << endl;
            }
            /***/
        }
        else if(w != parent[v] && pre[v] > pre[w]){
            componente.push(make_pair(v, w));
            /***/
            if(TESTE_NIVEL_2){
                cout << "adicionada a aresta " << componente.top().first << "---" << componente.top().second << endl;
            }
            /***/
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
    bridges = 0;

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
                    aresta = componente.top();
                    componente.pop();
                    /***/
                    if(TESTE_NIVEL_1){
                        cout << aresta.first << "---" << aresta.second << " ";
                    }
                    /***/
                    /*colocar aresta no grafo*/
                }
                /***/
                if(TESTE_NIVEL_1 ){
                    cout << endl;
                }
                /***/
                /*roda karger-stein*/
                /*retorno += karger*/
            }
            else{
                aresta = componente.top();
                componente.pop();
                bridges++;
                /***/
                if(TESTE_NIVEL_1){
                    cout << aresta.first << "---" << aresta.second << " " << "bridge!";
                    cout << endl;
                }
            }
        }
    }
    /*contando 1 bridge + qualquer aresta n bridge*/
    retorno += (m - bridges)*bridges;
    /*contando 2 bridges*/
    retorno += (bridges*(bridges-1))/2;
    return retorno;
}

/***main***/
int main(){
    int entrada1, entrada2;

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
    cout << waysCount() << endl;
    return 0;
}
