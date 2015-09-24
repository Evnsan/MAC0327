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
#define TAB_PRETO 65535 
#define TAB_BRANCO 0

#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0

using namespace std;

unsigned int geraMask(int x, int y, int mask[MASK_LIN][MASK_COL]){
    unsigned int retorno = 0;
    /*Primeira linha*/
    if(x > 0){
        if(y > 0 && mask[0][0]){
            retorno ^= 1 << ((x - 1)*TAB_COL + (y - 1));
        }
        if(mask[0][1]){
            retorno ^= 1 << ((x - 1)*TAB_COL + y);
        }
        if(y < TAB_COL - 1 && mask[0][2]){
            retorno ^= 1 << ((x - 1)*TAB_COL + (y + 1));
        }
    }
    /*Segunda linha*/
    if(y > 0 && mask[1][0]){
        retorno ^= 1 << (x*TAB_COL + (y - 1));
    }
    if(mask[1][1]){
        retorno ^= 1 << (x*TAB_COL + y);
    }
    if(y < TAB_COL - 1 && mask[1][2]){
        retorno ^= 1 << (x*TAB_COL + (y + 1));
    }
    /*Terceira linha*/
    if(x < TAB_LIN - 1){
        if(y > 0 && mask[2][0]){
            retorno ^= 1 << ((x + 1)*TAB_COL + (y - 1));
        }
        if(mask[2][1]){
            retorno ^= 1 << ((x + 1)*TAB_COL + y);
        }
        if(y < TAB_COL - 1 && mask[2][2]){
            retorno ^= 1 << ((x + 1)*TAB_COL + (y + 1));
        }
    }
    return retorno;
}


int main(){ 
    unsigned int tabuleiro;
    char linha[TAB_LIN + 1];
    int mask[MASK_LIN][MASK_COL];
    unsigned int masks[TAB_LIN*TAB_COL];
    unsigned int tabPre, tabPos;
    
    typedef map<unsigned int, int> mapType;
    map<unsigned int, int> lbl;

    queue <unsigned int> borda;

    /*entrada*/
    tabuleiro = 0;
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
        for(int i = 0; i < MASK_LIN; i++){
            for(int j = 0; j < MASK_COL; j++){
                cout << mask[i][j];
            }
            cout << endl;
        }
    }
    /***/

    /*Pre-Processamento*/
    for(int i = 0; i < TAB_LIN; i++){
        for(int j = 0; j < TAB_COL; j++){
            masks[i*TAB_COL + j] = geraMask(i, j, mask);
            /***/
            if(TESTE_NIVEL_2){
               cout << "Mask" << i*TAB_COL + j << ": ";
               cout << masks[i*TAB_COL + j] << endl;
            }
            /***/
        }
    }

    /*Processamento*/
    if(tabuleiro == TAB_BRANCO || tabuleiro == TAB_PRETO){
        cout << 0 << endl;
        return 0;
    }

    borda.push(tabuleiro);
    lbl[tabuleiro] = 0;
    while(!borda.empty()){
        tabPre = borda.front();
        borda.pop();
        for(int i = 0; i < TAB_LIN*TAB_COL; i++){
            tabPos = tabPre ^ masks[i];
            if(tabPos == TAB_BRANCO){
                cout << lbl[tabPre] + 1 << endl;
                return 0;
            }
            if(tabPos ==  TAB_PRETO){
                cout << lbl[tabPre] + 1 << endl;
                return 0;
            }
             
            if(!lbl.count(tabPos)){
                lbl[tabPos] = lbl[tabPre] + 1;
                borda.push(tabPos);
            }
        
        }
    }
    cout << "Impossible\n";
    
    /***/
    if(TESTE_NIVEL_2){
        cout << "Tabuleiro: " << tabuleiro << endl;
        cout << "MASK:" << endl;
        for(int i = 0; i < MASK_LIN; i++){
            for(int j = 0; j < MASK_COL; j++){
                cout << mask[i][j];
            }
            cout << endl;
        }
    }
    /***/



    return 0;
}
