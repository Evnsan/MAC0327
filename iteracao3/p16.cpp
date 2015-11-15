/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*******Factors and Multiples*******/
/***********************************/
/************Problema 16************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 100
#define VAZIO -1

using namespace std;
/***GLOBAIS***/
vector<int> adj[MAX];
int Ma[MAX];
int Mb[MAX];
int mTam;
bool visA[MAX], visB[MAX];

/*inicializacao*/

int inicializa(int n){
    mTam = 0;
    for(int i = 0; i < n; i++){
        Ma[i] = VAZIO;
        Mb[i] = VAZIO;
    }
    return 0;
}

/*vertice é livre?*/
bool livreA(int i){
    return Ma[i] == VAZIO;
}
bool livreB(int i){
    return Mb[i] == VAZIO;
}

/*Limpar vetor Visitados*/
int limpaVis(int n){
   for(int i = 0; i < n; i++){
       visA[i] = visB[i] = false;
   }
   return 0;
} 

bool temAumento(int a){
    /***/
    if(TESTE_NIVEL_1){
        cout << "TEMAUMENTO: entrou com " << a << endl;
    }
    /***/
    for(auto b : adj[a]){
        if(!visB[b]){
            if(livreB(b)){
                Ma[a] = b;
                Mb[b] = a;
                return true;
            }
            else{
                visB[b] = true;
                if(temAumento(Mb[b])){
                    Ma[a] = b;
                    Mb[b] = a;
                    return true;
                }
            }

        }
    }
    return false;
}
/*principal*/
int match(int n){
    int delta;
    bool teveAumento;

    /***/
    if(TESTE_NIVEL_1){
        cout << "MATCH entrou" << endl;
    }
    /***/
    inicializa(n);
    /***/
    if(TESTE_NIVEL_1){
        cout << "MATCH passou inicializa" << endl;
    }
    /***/
    teveAumento = true;
    while(teveAumento){
        teveAumento = false;
        for(int i = 0; i < n; i++){
            if(livreA(i)){
                /***/
                if(TESTE_NIVEL_1){
                    cout << "MATCH vai chamar temAumento, i = " << i << endl;
                }
                /***/
                teveAumento = temAumento(i);
                /***/
                if(TESTE_NIVEL_1){
                    cout << "MATCH passou temAumento, i = " << i << endl;
                }
                /***/
                limpaVis(n);
            }
        }
    }
    mTam = 0;
    for(int i = 0; i < n; i++){
        if(!livreA(i)){
            mTam++;
        }
    }
    return mTam;
}

/**MAIN**/
int main(){
    int testes,n,m;
    int A[MAX],B[MAX];
    
    cin >> testes;
    for(int t = 0; t < testes; t++){
        cin >> n; 
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        cin >> m; 
        for(int i = 0; i < m; i++){
            cin >> B[i];
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((A[i] != 0 && B[j] % A[i] == 0) || B[j] == 0){
                    adj[i].push_back(j);
                }
            }
        }
        /***/
        if(TESTE_NIVEL_1){
            for(int i = 0; i < n; i++){
                /***/
                if(TESTE_NIVEL_1){
                    cout << "MAIN: adj[" << i << "] = ";
                }
                /***/
                for(auto a : adj[i]){
                    cout << a << " ";
                }
                cout << endl;
            }
        }

        cout << "Case " << t + 1 << ": " << match(n) << endl;;
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
    }
    
    return 0;
}
