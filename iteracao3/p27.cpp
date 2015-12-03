/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**************Two Paths************/
/***********************************/
/*************Problema 27***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0
#define MAX 200 

using namespace std;

/*Globais*/
vector <int> adj[MAX];
int n;
int x, y;

/*Auxiliares*/
int bfsR(vector<int> pilha, int nivel, bool vis[MAX]){
    vector<int> novaPilha;
    if(false /*pilha vazia*/){
        return nivel;
    }
    for(auto a : pilha){
        for(auto cidade : adj[a]){
            if(!vis[cidade]){
                novaPilha.push_back(cidade);
            }
        }
        vis[a] = true;
    }
    return bfsR(novaPilha, nivel + 1, vis);
}

int custo(int cidDentro, int cidFora){
    vector<int> pilha;
    bool vis[MAX];

    for(int i = 0; i < n; i++){
        if( i == cidDentro ){
            vis[i] = true;
        }
        else{
            vis[i] = false;
        }
    }

    for(auto b : adj[a.first]){
        if(b != cidFora){
            pilha.push_back(b);
        }
    }
    return bfsR(pilha, 0, vis);
}


/*Programa principal*/
int main(){
    int max;
    /*componentes*/
    int comp1;
    int comp2;
    vector< pair<int, int> > arestas;

    /*Entrada*/
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        x -= 1;
        y -= 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
        arestas.push_back(make_pair(x, y));
    }

    /***/
    if(TESTE_NIVEL_2){
        cout << "####### MAIN : rotas #########" << endl;
        for(int i = 0; i < n ; i++){
            cout << "Cidade " << i << " :"<< endl;
            for(auto a : adj[i]){
                cout << " ->" << a << endl;
            } 
        }
        cout << "####### MAIN : arestas #########" << endl;
        for(auto a : arestas){
            cout << a.first << "->" << a.second << endl;
        }
    }
    /***/
    
    /*Processamento*/
    max = 0;
    for(auto a : arestas){
        comp1 = custo(a.first, a.second);
        comp2 = custo(a.second, a.first);
        if( max < comp1 * comp2){
            max = comp1 * comp2;
        }
    }

    /*Saida*/
    cout << max << andl;


    return 0;
}
