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
pair<int, int> dfsR(int vertice, int maxLateral, bool vis[MAX]){
    int max1, max2;
    pair<int, int> retorno;

    max1 = 0;
    max2 = 0;

    /***/
    if(TESTE_NIVEL_1){
        cout << "DFSR: recebeu (" << vertice << "," << maxLateral
             << endl;
    }
    /***/

    /*processar*/
    for(auto a : adj[vertice]){
        if(!vis[a]){
            vis[a] = true;
            retorno = dfsR(a, maxLateral, vis);
            if(retorno.first + 1 > max1){
                max2 = max1;
                max1 = retorno.first + 1;
            }
            else if(retorno.first  + 1> max2){
                max2 = retorno.first + 1;
            }
            if(retorno.second > maxLateral){
                maxLateral = retorno.second;
            }
        }
    }
    if(max1 + max2 > maxLateral){
        maxLateral = max1 + max2;
    }
    
    return make_pair(max1, maxLateral);

}

int custo(int cidDentro, int cidFora){
    pair <int, int> retorno;
    bool vis[MAX];

    for(int i = 0; i < n; i++){
        if(i == cidFora || cidDentro){
            vis[i] = true;
        }
        else{
            vis[i] = false;
        }
    }

    retorno = dfsR(cidDentro, 0, vis);

    if(retorno.first > retorno.second){
        return retorno.first;
    }
    else{
        return retorno.second;
    }
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
    cout << max << endl;


    return 0;
}
