/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/************Permutations***********/
/***********************************/
/*************Problema 21***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 200000


using namespace std;

int main(){
    int vetor1[MAX];
    int vetor2[MAX];
    unsigned int n, saida;
    

    
    /*Entrada*/
    cin >> n;
    for(unsigned int i = 0; i < n; i++){
        cin >> vetor1[i];
    }
    for(unsigned int i = 0; i < n; i++){
        cin >> vetor2[i];
    }
    /***/
    if(TESTE_NIVEL_1){
        for(unsigned int i = 0; i < n; i++){
            cout << "MAIN: vetor1[" << i << "] = " << vetor1[i] << endl;
        }
        for(unsigned int i = 0; i < n; i++){
            cout << "MAIN: vetor2[" << i << "] = " << vetor2[i] << endl;
        }
    }
    /***/

    /*Processamento*/
    saida = n;
    for(unsigned int i = 0,  j = 0; i < n && j < n; i++){
        while(j < n && vetor1[i] != vetor2[j])
            j++;
        if(j < n && vetor1[i] == vetor2[j])
            saida--;
    }

    /*Saida*/
    cout << saida << endl;


    return 0;
}
