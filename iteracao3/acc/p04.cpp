/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*****Levko*and*array*recovery******/
/***********************************/
/*************Problema 04***********/
/***********************************/
/*resubmetendo*/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAXN 5000
#define MAXM 5000
#define INF 1000000001

using namespace std;


/*****Globais*****/
long int resposta[MAXN+1];

long int vec_max(int l, int r){
    long int max = -INF;
    for(int i = l; i <= r; i++){
        if(max < resposta[i]){
           max = resposta[i];
        }
    }
    return max;
}

int vec_soma(int l, int r, long int valor){
    for(int i = l; i <= r; i++){
        resposta[i] += valor;
    }
    return 0;
}


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
    vector < tuple< int, int, int, long int> > operacoes;
    bool possivel = false;

    cin >> vetor_tam >> op_num;
    
    for(int i = 0; i <= vetor_tam ; i++){
        vetor_max[i] = INF - 1;
        somas[i] = 0;
    }
    for(int i = 0; i < op_num ; i++){
        cin >> operacao >> l >> r >> operando;
        operacoes.push_back(make_tuple(operacao, l, r, operando));
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
        for(auto a: operacoes){
            cout << "OPERACOES: (" << get<0>(a) << ", "
                 << get<1>(a) << ", " << get<2>(a) << ", "
                 << get<3>(a) << ")"<< endl;
        }
    }
    /***Fase II***/
    for(int i = 1; i <= vetor_tam; i++){
        resposta[i] = vetor_max[i] - somas[i];
        if(resposta[i] <= -INF){
            cout << "cagou no "<< i <<" !" << endl;
        }
        else if(resposta[i] >= INF){
            resposta[i] = 0;
        }
    }
    for(auto a : operacoes){
       if(get<0>(a) == 1){
           vec_soma(get<1>(a), get<2>(a), get<3>(a));
       }
       else
       {
           if(vec_max(get<1>(a), get<2>(a)) != get<3>(a)){
               cout << "NO" << endl;
               return 0;
           }
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
