/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 24*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 1

using namespace std;


/*****************/

typedef struct node* Node;
struct node{
    long int val;
    Node next;
};

/***GLOBAIS***/
Node maxVal = nullptr;


int colocaNoMaxVal(long int val){
    Node novo, ant, p;

    novo = new(node);
    novo->next = nullptr;
    novo->val = val;

    ant = maxVal;
    if(maxVal != nullptr && maxVal->val >= novo->val){
        p = maxVal->next;
        while(p != nullptr && p->val >= novo->val){
            ant = p;
            p = p->next;
        }
        ant->next = novo;
    }
    else{
        p = maxVal;
        maxVal = novo;
    }
    ant = p;
    while(ant != nullptr){
        p = ant->next;
        delete(ant);
        ant = p;
    }
    return 0;
}

/***main***/
int main(){
    int janelaTam;
    queue<int> janela;
    vector<long int> saida;
    long int leitura;
    Node p;


    cin >> janelaTam;
    leitura = 0;
    
    for(int i = 0; i < janelaTam && leitura != -1; i++){ 
        cin >> leitura;
        janela.push(leitura);
        colocaNoMaxVal(leitura);
    }
    cin >> leitura;
    while(leitura != -1){
        if(janela.front() == maxVal->val){
            p = maxVal;
            maxVal = maxVal->next;
            delete(p);
        }
        janela.pop();
        cin >> leitura;
    }
    
    /***/
    if(TESTE_NIVEL_1){
        while(!janela.empty()){
            cout << janela.front() << endl;
            janela.pop();
        }
        p = maxVal;
        while(p != nullptr){
            cout << "PRT-QUEUE: " << p->val << endl;
            p = p->next;
        }
    }
    /***/

    /*limpeza*/
    p = maxVal;
    while(p != nullptr){
        maxVal = p->next;
        delete(p);
        p = maxVal;
    }
    return 0;
}
