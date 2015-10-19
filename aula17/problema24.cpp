/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 24*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 25000

using namespace std;


/*****************/

/***GLOBAIS***/
vector<long int> maxVal;


int colocaNoMaxVal(long int val){
    if(!maxVal.empty() && maxVal.front() >= val){
        unsigned int i = 0; 
        for(;i < maxVal.size() && maxVal[i] >= val; i++);
        if( i < maxVal.size())
            maxVal.erase(maxVal.begin() + i,maxVal.end());
    }
    else{
        maxVal.clear();
    }
    maxVal.push_back(val);
    return 0;
}

/***main***/
int main(){
    int janelaTam;
    queue<int> janela;
    vector<long int> saida;
    long int leitura;


    cin >> janelaTam;
    leitura = 0;
    
    for(int i = 0; i < janelaTam && leitura != -1; i++){ 
        cin >> leitura;
        janela.push(leitura);
        colocaNoMaxVal(leitura);
    }
    saida.push_back(maxVal.front());
    cin >> leitura;
    while(leitura != -1){
        if(janela.front() == maxVal.front()){
            maxVal.erase(maxVal.begin());
        }
        janela.pop();
        janela.push(leitura);
        colocaNoMaxVal(leitura);
        saida.push_back(maxVal.front());
        cin >> leitura;
    }
    
    /***/
    if(TESTE_NIVEL_1){
        while(!janela.empty()){
            cout << janela.front() << endl;
            janela.pop();
        }
        for(auto a : maxVal){
            cout << "PRT-QUEUE: " << a << endl;
        }
        for(unsigned int i = 0; i < saida.size(); i++){
            cout << "SAIDA: " << saida[i] << endl;
        }
    }
    /***/
    
    /*saida*/
    for(unsigned int i = 0; i < saida.size(); i++){
        cout << saida[i] << endl;
    }

    return 0;
}
