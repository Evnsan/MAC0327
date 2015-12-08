/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*****Yaroslav and Permutations*****/
/***********************************/
/*************Problema 39***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define NMAX 100 
#define MAX 1000

using namespace std;

/*main*/
int main(){
    int n;
    int vetor[NMAX];
    int count;
    int max;

    /*Entrada*/
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    
    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : vetor" << endl;
        for(int i = 0; i < n; i++){
            cout << vetor[i] << endl;
        }
    }
    /***/
    
    /*Processamento*/
    max = 0;
    for(int i = 1; i <= MAX; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(i == vetor[j]){
                count += 1;
            }
        }
        if(count > max){
            max = count;
        }
    }

    /*Processamento e Saida*/
    if(max > (n + 1)/2){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
