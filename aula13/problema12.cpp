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

vector<int> rotas[MAXROTAS];
vector<int> paradas[MAXPARADAS + 1];
vector<int> rotasIniciadas(MAXROTAS);
queue<int> saida;
int n = 0;

int percorrer(int r){
    rotasIniciadas[r] = 1;
    for(auto a = rotas[r].begin(); a != rotas[r].end(); a++){
        for(auto b = paradas[*a].begin(); b != paradas[*a].end(); b++){
            if(!rotasIniciadas[*b]){
                percorrer(*b);
            }
            else if( *b == r){
                swap(*b, paradas[*a].back());
                paradas.pop_back();
            }

        }
    }

    return 0;
}


/***main***/
int main(){
    int m;
    int entrada1;

    /*Entrada*/
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        for(int j = 0; j <= m; j++){
            cin >> entrada1;
            parada[entrada1].push_back(i);
            rotas[i].push_back(entrada1);
        }
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("##Dig_adj##\n");
        for(int i = 0; i < n; i++){
            printf("%d)", i);
            for(auto a = rotas[i].begin(); a != rotas[i].end(); a++){
                printf("%d->", (*a));
            }
            printf("FIM\n");
        }
        printf("###########\n");
    }
    /***/

    /*Processamento  -  Saida*/
    if(0){
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");
    
    return 0;
}
