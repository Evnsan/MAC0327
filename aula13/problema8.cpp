/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 08*************/
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
int pre[MAX] = {0};

/*BFS*/
int bfs(int startnode){
    borda.push(startnode);
    bfsR();
    return 0;
}
int bfsR(){
    return 0;
}


/***main***/
int main(){
    int nlinhas;

    string entrada1;
    string entrada2;
    string entrada3;

    /*Entrada*/
    cin >> nlinhas;
    for(int i = 0; i < nlinhas; i++){
        cin >> entrada1 >> entrada2 >> entrada3;
        /*programadores.find("entrada1") == m.end()*/
        if(prog.find("entrada1") == prog.end()){ 
            prog[entrada1] = Dig_n;
            nProg[Dig_n] = entrada1;
            dig_n++;
        }
        if(prog.find("entrada2") == prog.end()){ 
            prog[entrada2] = Dig_n;
            nProg[Dig_n] = entrada2;
            dig_n++;
        }
        if(prog.find("entrada3") == prog.end()){ 
            prog[entrada3] = Dig_n;
            nProg[Dig_n] = entrada3;
            dig_n++;
        }
        Dig_adj[prog[entrada1]][prog[entrada2]] = 1;
        Dig_adj[prog[entrada1]][prog[entrada3]] = 1;
        Dig_adj[prog[entrada2]][prog[entrada1]] = 1;
        Dig_adj[prog[entrada2]][prog[entrada3]] = 1;
        Dig_adj[prog[entrada3]][prog[entrada1]] = 1;
        Dig_adj[prog[entrada3]][prog[entrada2]] = 1;
    }
    /*processamento*/
    bfs(prog["Isenbaev"]);


    /*Saida*/
    
    return 0;
}
