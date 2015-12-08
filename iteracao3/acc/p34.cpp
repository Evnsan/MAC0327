/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*********Cows and Poker Game*******/
/***********************************/
/*************Problema 35***********/
/***********************************/
/*resubmetendo*/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 200000 

using namespace std;

/*main*/
int main(){
    long int n;
    long int qtde_i, qtde_a;
    char ch;

    /*Entrada*/
    cin >> n;
    qtde_i = 0;
    qtde_a = 0;
    for(long int i = 0; i < n; i++){
        cin >> ch;
        if(ch == 'I'){
            qtde_i += 1;
        }
        else if(ch == 'A'){
            qtde_a += 1;
        }
    }

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : char lidos =" << n << endl;
        cout << "QTDE_I = " << qtde_i << endl;
        cout << "QTDE_A = " << qtde_a << endl;
    }
    /***/

    /*Saida*/
    if(qtde_i > 0){
        if(qtde_i > 1){
           cout << 0 << endl;
        }
        else{
           cout << 1 << endl;
        }
    }
    else{
        cout << qtde_a << endl;
    }
    return 0;
}
