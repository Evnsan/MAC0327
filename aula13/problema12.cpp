/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 12*************/
/***********************************/

#include<bits/stdc++.h>

#define MAXROTAS 1000
#define MAXPARADAS 10000
#define TESTE_NIVEL_1 1

using namespace std;

struct node {
    int nparada;
    int estacao;
    node *prox;
};

node *rotas[MAXROTAS];
map<int, int> paradas[MAXPARADAS + 1];
int rotasIniciadas[MAXROTAS];
queue<int> saida;
int n = 0;
int maxparada = 0;


int percorrer(int rota, int estacao){
    node *p;
    node* inicio;

    rotasIniciadas[r] = 1;
    p = rotas[r];
    while( p->estacao != estacao) p = p->prox;
    inicio = p;
    p = p->prox;

    while(p != inicio){
        for(auto a = paradas[p->estacao].begin(); a != paradas[p->estacao].end(); a++){
            if(rotasIniciadas[a->first] == 0){
                saida.push(p->estacao);
                percorrer(a->first, p->estacao);
                break;
            }
        }
    }

    return 0;
}



/***main***/
int main(){
    int m;
    int entrada1;
    node *p;

    /*Entrada*/
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        cin >> entrada1;
        if(maxparada < entrada1) maxparada = entrada1;
        paradas[entrada1][i] = 1;
        p = new node;
        p->nparada = 0;
        p->estacao = entrada1;
        rotas[i] = p;
        for(int j = 1; j <= m; j++){
            p->prox = new node;
            p = p->prox;
            cin >> entrada1;
            if(maxparada < entrada1) maxparada = entrada1;
            p->nparada = j;
            p->estacao = entrada1;
            paradas[entrada1][i] = 1;
        }
        p->prox = rotas[i];
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("##Rotas##\n");
        for(int i = 0; i < n; i++){
            printf("%d)", i);
            p = rotas[i];
            printf("%d->", p->estacao);
            p = p->prox; 
            while(p != rotas[i]){
                printf("%d->", p->estacao);
                p = p->prox; 

            }
            printf("FIM\n");
        }
        printf("###########\n");
        printf("\n##Paradas##\n");
        for(int i = 1; i <= maxparada; i++){
            cout << "Parada " << i << endl;
            for(auto a = paradas[i].begin(); a != paradas[i].end(); a++){
               cout << a->first;
            }
            cout << endl;
       }
       printf("###########\n");
    }
    /***/

    for(int i = 0; i < n; i++){
        rotasIniciadas[i] = 0;
    }

    /*Processamento  -  Saida*/
    if(0){
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");
    
    return 0;
}
