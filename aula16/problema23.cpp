/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 23*************/
/***********************************/

#include<bits/stdc++.h>

#define MAXV 50
#define MAXA 100
#define TESTE_NIVEL_1 0

using namespace std;

vector<int> Dig_adj[MAXV + 1];
int Dig_n = 0;

vector<int> cor(MAXV + 1);
map<int, int> ncor;
vector<int> saida1;
vector<int> saida2;
int cormax;

int di[MAXV];

/*****************/
int TSdfsR(int v, int c){
    int w;
    int nextc;

    cor[v] = c;
    ncor[c] = ncor[c] + 1;
    nextc = (c%2 == 1 ? c - 1 : c + 1);
    /***/
    if(TESTE_NIVEL_1){
        printf("Iniciou o %d\n", v);
        printf("Chegou c = %d e geramos nextc = %d\n", c, nextc);
    }
    /***/
    
    for (auto a = Dig_adj[v].begin(); a != Dig_adj[v].end(); a++){
        w = *(a);
        /***/
        if(TESTE_NIVEL_1){
            printf("    vai tentar o %d que tem cor = %d\n", w, cor[w]);
        }
        /***/
        if (cor[w] == -1){

            if(!TSdfsR(w, nextc)){
                return 0;
            }
        }
        else{
            if(cor[w] == c)
                return 0;
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("Finalizou o %d\n", v);
    }
    /***/
    return 1;
}

/******/
int DIGtwocolor(){
    int c = -2;
    for (int v = 0; v <= Dig_n; v++){
        cor[v] = -1;
    }
    for (int v = 1; v <= Dig_n; v++)
        if (cor[v] == -1){
            c += 2;
            cormax = c;
            ncor[c] = 0;
            ncor[c+1] = 0;
            cor[v] = c; 
            if(!TSdfsR(v, c))
                return 0;
        }
    return 1;
}
/*****************/
int separaR(int atual, int soma, int comp){
    printf("Entrou no comp: %d com soma = %d e comp = %d\n", atual, soma, comp);
    if(atual < comp){
        if(di[atual] == 0)
            return separaR(atual + 1, soma, comp);
        else{
            if(separaR(atual + 1, soma + di[atual], comp)){
               return 1;
            }
            else{
                return separaR(atual + 1, soma - di[atual], comp);
            }
        }
    }
    else{
        if(soma + di[atual] == 0)
            return 1;
        else if(soma - di[atual] == 0)
            return 1;
        else
            return 0;
    }
}


int separa(){
    int d;
    int componentes = cormax/2 + 1;
    for(int i = 0; i < componentes; i++){
        d = ncor[2*i] - ncor[2*i+1];
        di[i] = d > 0 ? d : -d; 
/*        printf("d[%d] = %d\n", i, di[i]);*/
    }
    if(!separaR(0, 0, componentes)){
        return 0;
    }
    return 1;
}




/*****************/
/***main***/
int main(){
    int entrada1;
    int entrada2;
    int m;

    /*Entrada*/
    cin >> Dig_n;
    Dig_n *= 2;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> entrada1;
        cin >> entrada2;
        Dig_adj[entrada1].push_back(entrada2);
        Dig_adj[entrada2].push_back(entrada1);
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("##Dig_adj##\n");
        for(int i = 0; i <= Dig_n; i++){
            for(auto a = Dig_adj[i].begin(); a != Dig_adj[i].end(); a++){
                printf("%d->%d\n", i , (*a));
            }
        }
        printf("###########\n");
    }
    /***/

    /*Processamento  -  Saida*/
    if(DIGtwocolor()){
        for(int i = 0; i <= Dig_n; i++)
            printf("%d ", cor[i]);
        printf("\n");
        if(separa())
            printf("é possivel!!!!!!!!!!!!\n");
    }

    else
        printf("IMPOSSIBLE\n");
    /***/
    if(TESTE_NIVEL_1){    
        printf("###########\n");
        printf("CorMax = %d\n", cormax);
        for(auto a : ncor){
            printf("cor = %d tem numero %d\n", a.first, a.second);
        }
        printf("###########\n");
    }
    /***/
    
    return 0;
}
