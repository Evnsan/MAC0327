/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 01*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 65536 
#define TAB_LIN 4
#define TAB_COL 4
#define MASK_LIN 3
#define MASK_COL 3
#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_1 0

using namespace std;

/*vector<int> tsi;*/


int main(){ 
    unsigned int tabuleiro;
    char linha[TAB_LIN + 1];
    int mask[MASK_LIN][MASK_COL];

    /*entrada*/
    for(int i = 0; i < TAB_LIN; i++){
        cin >> linha;
        for(int j = 0; j < TAB_COL; j++){
            if(linha[j] == 'B'){
                tabuleiro = tabuleiro | (1 << (i * 4 + j));
            }
        }
    }
    
    /***/
    if(TESTE_NIVEL_2){
        cout << "MASK <<" << endl;
    }
    /***/

    for(int i = 0; i < MASK_LIN; i++){
        cin >> linha;
        for(int j = 0; j < MASK_COL; j++){
            if(linha[j] == '1'){
                mask[i][j] = 1;
            }
            else{
                mask[i][j] = 0;
            }
        }
    }
    /***/
    if(TESTE_NIVEL_2){
        cout << "Tabuleiro: " << tabuleiro << endl;
        cout << "MASK:" << endl;
        for( int i = 0; i < MASK_LIN; i++){
            for(int j = 0; j < MASK_COL; j++)
                cout << mask[i][j];
            cout << endl;
        }
    }
    /***/



    return 0;
}
