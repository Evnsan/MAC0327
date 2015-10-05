/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 08*************/
/***********************************/
/*Baseado nos codigos do professor**/
/**********Paulo Feofiloff**********/
/***********************************/

#include<bits/stdc++.h>

#define MAX 300
#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0

using namespace std;

int Dig_adj[MAX][MAX] = {{0}};
int Dig_n = 0;

// typedef map<string, int> mapType2;
// map<string, int> foo;
typedef map<string, int> mapType;
map<string, int> prog;
string nProg[MAX];

queue <int> borda;
int lbl[MAX] = {0};

/***main***/
int main(){
    int nlinhas;
    int vert;

    string entrada1;
    string entrada2;
    string entrada3;

    /*Entrada*/
    cin >> nlinhas;
    Dig_n = 0;
    for(int i = 0; i < nlinhas; i++){
        cin >> entrada1 >> entrada2 >> entrada3;
        /*programadores.find("entrada1") == m.end()*/
        if(!prog.count(entrada1)){ 
            prog[entrada1] = Dig_n;
            nProg[Dig_n] = entrada1;
            Dig_n++;
        }
        if(!prog.count(entrada2)){ 
            prog[entrada2] = Dig_n;
            nProg[Dig_n] = entrada2;
            Dig_n++;
        }
        if(!prog.count(entrada3)){ 
            prog[entrada3] = Dig_n;
            nProg[Dig_n] = entrada3;
            Dig_n++;
        }
        Dig_adj[prog[entrada1]][prog[entrada2]] = 1;
        Dig_adj[prog[entrada1]][prog[entrada3]] = 1;
        Dig_adj[prog[entrada2]][prog[entrada1]] = 1;
        Dig_adj[prog[entrada2]][prog[entrada3]] = 1;
        Dig_adj[prog[entrada3]][prog[entrada1]] = 1;
        Dig_adj[prog[entrada3]][prog[entrada2]] = 1;
    }
    /*processamento*/
    for(int v = 0; v < Dig_n; v++){
        lbl[v] = -1;
    }
    if(prog.count("Isenbaev")){
        borda.push(prog["Isenbaev"]);
        lbl[prog["Isenbaev"]] = 0;
    }
    while(!borda.empty()){
        vert = borda.front();
        borda.pop();
        for(int v = 0; v < Dig_n; v++){
            if(Dig_adj[vert][v] == 1 && lbl[v] == -1){
                lbl[v] = lbl[vert] + 1;
                borda.push(v);
            }
        }
    }
    /***/
    if(TESTE_NIVEL_2){
        cout << "O prog é:\n";
        for (auto it = prog.begin(); it != prog.end(); ++it)
            cout << it->first << " => " << it->second << '\n';
    }
    /***/

    /*Saida*/
    for( auto it = prog.begin(); it != prog.end(); ++it){
        cout << it->first << " ";
        if(lbl[it->second] == -1)
            cout << "undefined \n";
        else
            cout << lbl[it->second] << "\n";
    }

    return 0;
}
