/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*****Yaroslav and Permutations*****/
/***********************************/
/*************Problema 40***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 100000

using namespace std;

/*main*/
int main(){
    int n, m, k;
    long long int vetor[MAX];
    long int ops[MAX][3];
    long int qry[MAX][2];

    /*Entrada*/
    cin >> n >> m >> k;

    for(long int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    for(long int i = 0; i < m; i++){
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    for(long int i = 0; i < k; i++){
        cin >> qry[i][0] >> qry[i][1];
    }
    
    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : vetor" << endl;
        for(long int i = 0; i < n; i++){
            cout << vetor[i] << " ";
        }
        cout << endl;
    }
    /***/
    
    /*Processamento*/

    /*Saida*/
    for(long int i = 0; i < n; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
    return 0;
}
