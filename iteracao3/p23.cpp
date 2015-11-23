/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***************Letter**************/
/***********************************/
/*************Problema 23***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 50 


using namespace std;

int main(){
    char vetor[MAX][MAX];
    int n, m;
    char saida[MAX][MAX];
    int dir, esq, cima, baixo;
    

    /*Entrada e Processamento*/
    cin >> n >> m;
    cima = n - 1;
    esq = m - 1;
    dir = baixo = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> vetor[i][j];
            if ( vetor[i][j] == '*'){
                if(i < cima){
                    cima = i;
                }
                if(i > baixo){
                    baixo = i;
                }
                if(j < esq){
                    esq = j;
                }
                if(j > dir){
                    dir = j;
                }
            }
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : entrada " << n << "x" << m << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << vetor[i][j];
            }
            cout << endl;
        }
    }
    /***/

    /*Saida*/
    for(int i = cima; i <= baixo; i++){
        for( int j = esq; j <= dir; j++){
           cout << vetor[i][j];
        }
       cout << endl; 
    }

    return 0;
}
