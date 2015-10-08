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
#define TESTE_NIVEL_1 0

using namespace std;


vector<int> rotas[MAXROTAS + 1];
map<int, int> paradas[MAXPARADAS + 1];
int rotasIniciadas[MAXROTAS];
queue<int> saida;
int n = 0;
int maxparada = 0;


int ePossivel(){
    for(int i = 0; i < n; i++){
        if(!rotasIniciadas[i]){
            return 0;
        }
    }
    return 1;
}

int percorrer(int rota, int estacao){
    int agora;
    int inicio;
    int est;

    rotasIniciadas[rota] = 1;
    agora = 0;
    while( rotas[rota][agora] != estacao ){
       agora++;
       agora %= rotas[rota].size();
    }
    inicio = agora;
    inicio++;
    inicio %= rotas[rota].size();
    agora++;
    agora %= rotas[rota].size();
    do{
        est = rotas[rota][agora];
        saida.push(est);
        for(auto a = paradas[est].begin(); a != paradas[est].end(); a++){
            if(rotasIniciadas[a->first] == 0){
                percorrer(a->first, est);
               /* paradas[est].erase(a->first);*/
            }
        }
        agora++;
        agora %= rotas[rota].size();
    }while(agora != inicio);

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
        for(int j = 0; j < m; j++){
            cin >> entrada1;
            if(maxparada < entrada1) maxparada = entrada1;
            paradas[entrada1][i] = 1;
            rotas[i].push_back(entrada1); 
        }
        cin >> entrada1; /*descartando a ultima*/
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("##Rotas##\n");
        for(int i = 0; i < n; i++){
            printf("rota %d com %lu estacoes: ",i, rotas[i].size());
            for(auto a = rotas[i].begin(); a != rotas[i].end(); ++a){
                printf("(%d)->", *a);

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
    saida.push(rotas[0][0]);
    percorrer(0, rotas[0][0]);
    if(ePossivel()){
        printf("%ld", saida.size() - 1);
        while(!saida.empty()){
            printf(" %d", saida.front());
            saida.pop();
        }
        printf("\n");
    }
    else
        printf("0\n");
    
    return 0;
}
