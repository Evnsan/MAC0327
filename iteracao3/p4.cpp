/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*****Levko*and*array*recovery******/
/***********************************/
/*************Problema 04***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAXN 5000
#define MAXM 5000
#define INF 1000000001

using namespace std;


/*****************/

/***main***/
int main(){
    int vetor_tam = 0;
    int op_num = 0;
    int operacao = 0;
    int l = 0, r = 0;
    long int saida = 0;
    long int operando = 0;
    long int somas[MAXN+1];
    long int vetor_max[MAXN+1];
    bool possivel = false;

    cin >> vetor_tam >> op_num;
    
    for(int i = 0; i <= vetor_tam ; i++){
        vetor_max[i] = INF - 1;
        somas[i] = 0;
    }
    for(int i = 0; i < op_num ; i++){
        cin >> operacao >> l >> r >> operando;
        if(operacao == 1){
            for(int j = l; j <= r; j++){
                somas[j] += operando;
                if(vetor_max[j] + operando >= INF){
                    vetor_max[j] = INF - 1 ;
                }
                if(vetor_max[j] + operando <= -INF){
                    cout << "NO" << endl;
                    return 0;
                }
                else{
                    vetor_max[j] += operando;
                }
            }
        }
        else{
            possivel = false;
            for(int j = l; j <= r; j++){
                if(vetor_max[j] >= operando){
                    vetor_max[j] = operando;
                    possivel = true;
                }
            }
            if(!possivel){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 1; i <= vetor_tam; i++){
            cout << "SOMAS[" << i << "]: " << somas[i] << endl;
        }
        for(int i = 1; i <= vetor_tam; i++){
            cout << "VETOR_MAX[" << i << "]: " << vetor_max[i] << endl;
        }
    }
    /***saida***/
    cout << "YES" << endl;
    for(int i = 1; i <= vetor_tam; i++){
        saida = vetor_max[i] - somas[i];
        if(saida <= -INF){
            cout << "cagou!" << endl;
        }
        else if(saida >= INF){
            cout << "0 ";
        }
        else{
            cout << saida << " ";
        }
    }
    cout << endl;
        
    return 0;
}
