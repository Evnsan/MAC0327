/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********Computer Games II********/
/***********************************/
/*************Problema 13***********/
/***********************************/

/*NOTA*/
/*algoritmo de Edmonds para emparelhamento de cardinalidade maxima em grafos
  genericos - implementando baseado no código apresentado no site:
https://sites.google.com/site/indy256/algo/edmonds_matching*/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 500

using namespace std;
/***GLOBAIS***/
vector<int> adj[MAX];

/*que rotina zuada!*/
/*Lowest Common Ancestor*/
int lca(int match[MAX], int base[MAX], int p[MAX], int a, int b, int n){
    bool used[n];
    for(int i = 0; i < n; i++){
        used[i] = false;
    }
    while(true){
        a = base[a];
        used[a] = true;
        if(match[a] == -1) break;
        a = p[match[a]];
    }
    while(true){
        b = base[b];
        if(used[b])
            return b;
        b = p[match[b]];
    }
}

/*ainda nao entendi direiro. provavelmente para fazer o shrink do blossom*/
void markPath(int match[MAX], int base[MAX], bool blossom[MAX], int p[MAX],
              int v, int b, int children){
    for(; base[v] != b; v = p[match[v]]){
        blossom[base[v]] = blossom[base[match[v]]] = true;
        p[v] = children;
        children = match[v];
    }
}

int findPath(vector<int> graph[MAX], int match[MAX], int p[MAX], int root,
                 int n){
    bool used[MAX];
    int base[MAX];
    int qh = 0;
    int qt = 0;
    int q[n];
    
    /*inicializando*/
    for(int i = 0; i < n; i++){
        p[i] = -1;
        base[i] = i;
    }
    used[root] = true;
    q[qt++] = root;

    /*inicio da busca*/
    while(qh < qt){
        int v = q[qh++];

        for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end();
                it++){
            int to = *it;
            /*se esta na mesma arvore que v ou e par de v em M => nao procura*/
            if(base[v] == base[to] || match[v] == to) continue;
            /*se for aresta v-root ou aresta para w emparelhado e alternante*/
            if(to == root || (match[to] != -1 && p[match[to]] != -1) ){
                int curbase = lca(match, base, p, v, to, n);
                bool blossom[MAX];
                markPath(match, base, blossom, p, v, curbase, to);
                markPath(match, base, blossom, p, to, curbase, v);
                for( int i = 0; i < n; i++){
                    if(blossom[base[i]]){
                        base[i] = curbase;
                        if(!used[i]){
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
                }
            }
            else if(p[to] == -1){
                p[to] = v;
                if(match[to] == -1){
                    return to;
                }
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}

int maxMatch(vector<int> graph[MAX], int n){
    int match[MAX];
    int p[MAX];
    int cont;

    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            cout << "MAXMATCH: graph[" << i << "] = ";
            for(vector<int>::iterator a = graph[i].begin();
                    a != graph[i].end(); a++){
                cout << *a  << " ";
            }
            cout << endl;
        }
    }
    /***/
    /*Iniciar emparelhamento vazio*/
    for(int i = 0; i < n; i++){
        match[i] = -1;
    }
    /*Busca por caminhos aumentadores*/
    for(int i = 0; i < n; i++){
        if(match[i] == -1){
            int v = findPath(graph, match, p , i , n);
            /*diferenca simetrica*/
            while(v != -1){
                int pv = p[v];
                int ppv = match[pv];
                match[v] = pv;
                match[pv] = v;
                v = ppv;
            }
        }
    }

    /*Segunda fase - contar pares*/
    cont = 0;
    for(int i = 0; i < n; i++){
        if(match[i] != -1){
            cont++;
        }
    }
    /*Saida*/
    return cont / 2;
}

int main(){
    int n;
    int k;
    int soma;
    int dif;
    int lvl[MAX];
    
    /*Entrada*/
    cin >> n >> k;
    while( n != 0 || k != 0){
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
                if(dif <= k && dif%2 == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        /***/
        if(TESTE_NIVEL_1){
            for(int i = 0; i < n; i++){
                cout << "MAIN: adj[" << i << "] = ";
                for(vector<int>::iterator a = adj[i].begin();
                        a != adj[i].end(); a++){
                    cout << *a  << " ";
                }
                cout << endl;
            }
        }
        /***/
        
        /*Processamento*/
        soma = maxMatch(adj, n);
        
        /*saida*/
        cout << soma << endl;

        cin >> n >> k;
    }
    return 0;
}
