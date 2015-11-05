/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Genie Bomber************/
/***********************************/
/***********Problema 11*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 100


using namespace std;


typedef pair<int, int> Cidade;    /*(x, y)*/

/***GLOBAIS***/

/***main***/
int main(){
    int cid_n;   /*numero de cidades*/
    vector<Cidade> cidades;
    vector<int> interseccoes;
    int max;
    int x, y;
    int bomb_r, cid_r;
    double distancia;
    Cidade cidA, cidB;

    /*Entrada*/
    cin >> cid_n;
    for(int i = 0; i < cid_n; i++){
        cin >> x >> y;
        cidades.push_back(make_pair(x,y));
        interseccoes.push_back(0);
    }
    cin >> bomb_r >> cid_r;

    
    /***/
    if(TESTE_NIVEL_1){
        cout << "CID_N: " << cid_n << endl;
        cout << "CID_R: " << cid_r << endl;
        cout << "BOMB_R: " << bomb_r << endl;
        for(auto a : cidades){
            cout << "CIDADES : (" << a.first << "," << a.second 
                 << ")" << endl;
        }
        for(auto a : interseccoes){
            cout << "INTERSECCOES : " << a << endl;
        }
    }
    /***/

    /*Processamento*/
    if(bomb_r > cid_r){
        max = 1;
        for(int i = 0; i < cid_n; i++){
            cidA = cidades[i];
            for( int j = i + 1; j < cid_n; j++){
                cidB = cidades[j];
                distancia = sqrt(pow(cidA.first - cidB.first, 2.0) +
                                 pow(cidA.second - cidB.second, 2.0));
                if(distancia <= 2*(bomb_r - cid_r)){
                        interseccoes[i]++;
                        interseccoes[j]++;
                        if(interseccoes[i] > max){
                            max = interseccoes[i];
                        }
                        if(interseccoes[j] > max){
                            max = interseccoes[j];
                        }
                }


                /***/
                if(TESTE_NIVEL_1){
                   cout << "DISTANCIA = " << distancia << endl;
                }
                /***/
            }
        }
    }
    else if(bomb_r == cid_r){
        max = 1;
    }
    else{
        max = 0;
    }
    cout << max << endl;

    return 0;
}
