/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 10*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 1000
#define TESTE_NIVEL_1 0

using namespace std;

vector<int> pais[MAX + 1];
vector<int> filhos[MAX + 1];
vector<bool> susp;
int susp_n = 0; /*suspeitos*/
int pop_n = 0; /*populacao*/

int dfsPais(int p){
    /***/
    if(TESTE_NIVEL_1){
        cout << "[DFSPAIS] Entrou para " << p << endl;
    }
    /***/
    for(auto a : pais[p]){
        if(susp[a] == true){
            susp[a] = false;
            susp_n--;
        }
        dfsPais(a);
    }
    return 0;
}

int dfsFilhos(int f){
    /***/
    if(TESTE_NIVEL_1){
        cout << "[DFSFILHOS] Entrou para " << f << endl;
    }
    /***/
    for(auto a : filhos[f]){
        if(susp[a] == true){
            susp[a] = false;
            susp_n--;
        }
        dfsFilhos(a);
    }
    return 0;
}

int removeSusp(int vit){
    if(susp[vit] == true){
        susp[vit] = false;
        susp_n--;
    }
    /*DFS nos pais*/
    dfsPais(vit);
    /*DFS nos filhos*/
    dfsFilhos(vit);
    return 0;
}

/***main***/
int main(){
    char entc;
    int entn1;
    int entn2;
    string blood;
    /*Entrada*/
    cin >> pop_n;
    susp_n = pop_n;
    susp.push_back(false);
    for(int i = 0; i < pop_n; i++){
        susp.push_back(true);
    }
    cin >> entc;
    while(entc != 'B'){
        cin.putback(entc);
        cin >> entn1 >> entn2;
        pais[entn1].push_back(entn2);
        filhos[entn2].push_back(entn1);
        cin >> entc;
    }
    cin >> blood;
    while(!cin.eof()){
        cin >> entn1;
        removeSusp(entn1);
        if(susp_n == 0)
            break;
    }
    /***/
    if(TESTE_NIVEL_1){
        cout << "SAINDO" << endl;
        printf("##PAIS##\n");
        for(int i = 0; i <= pop_n; i++){
            for(auto a : pais[i]){
                cout << i << "->" << a << endl;
            }
        }
        printf("###########\n");
        printf("##FILHOS##\n");
        for(int i = 0; i <= pop_n; i++){
            for(auto a : filhos[i]){
                cout << i << "->" << a << endl;
            }
        }
        printf("###########\n");
        printf("##SUSPEITOS##\n");
        for(auto a : susp){
            cout << a << endl;
        }
        printf("###########\n");
    }
    /***/
    if(susp_n == 0){
        cout << 0 << endl;
    }
    else{
        for(int i = 1; i <= pop_n; i++){
            if(susp[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
