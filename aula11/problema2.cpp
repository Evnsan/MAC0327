/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 02*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 8 

#define FULLBOARD 65535 
#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0

using namespace std;
#include <queue>
#include <iostream>
  
using namespace std;
  
/***Tabuleiros-masq***/
typedef unsigned int tabuleiro;
tabuleiro mask[4][4];
/*********************/
typedef pair<int, int> Coordenada;
typedef pair< Coordenada, unsigned int > Estado;
typedef struct no No; 
struct no{
    int acoes;
    Estado estado;
    No* pai;
    No* next;
};

struct comparator {
    bool operator()(No* i, No* j){
    return i->acoes > j->acoes;
    }
};

/***Globais***/
int board_n = 0;
vector< Coordenada > saida;
/*************/

int iniciaMask(){
    mask[0][0]= 1;
    mask[0][1] = 1 << 1;
    mask[0][2] = 1 << 2;
    mask[0][3] = 1 << 3;
    mask[1][0] = 1 << 4;
    mask[1][1] = 1 << 5;
    mask[1][2] = 1 << 6;
    mask[1][3] = 1 << 7;
    mask[2][0] = 1 << 8;
    mask[2][1] = 1 << 9;
    mask[2][2] = 1 << 10;
    mask[2][3] = 1 << 11;
    mask[3][0] = 1 << 12;
    mask[3][1] = 1 << 13;
    mask[3][2] = 1 << 14;
    mask[3][3] = 1 << 15;
    return 0;
}

bool eEstadoNulo(Estado entrada){
    return entrada.first.first == -1;
}

bool eCoordenadaNula(Coordenada entrada){
    return entrada.first == -1;
}

Coordenada proxCoord(Coordenada entrada, int acao){
    int x = entrada.first;
    int y = entrada.second;
    pair<int, int> retorno = make_pair(-1, -1);
    /*calcula acao*/
    if(acao == 0){
        x += 2;
        y += 1;
    }
    else if(acao == 1){
        x += 2;
        y -= 1;
    }
    else if(acao == 2){
        x -= 2;
        y += 1;
    }
    else if(acao == 3){
        x -= 2;
        y -= 1;
    }
    else if(acao == 4){
        x += 1;
        y += 2;
    }
    else if(acao == 5){
        x += 1;
        y -= 2;
    }
    else if(acao == 6){
        x -= 1;
        y += 2;
    }
    else if(acao == 7){
        x -= 1;
        y -= 2;
    }
    else{
        cout << "[proxCoord]Deu xabu no numero da acao: " << acao << endl;
    }
    if( x >= 0 && x < board_n){
        if ( y >= 0 && y < board_n){
            retorno = make_pair(x,y);
        }
    }
    return retorno;
}

int calculaAcoes(Coordenada entrada){
    int conta = 0;
    for(int i = 0; i < 8; i++){ 
        if(proxCoord(entrada, i).first != -1){
            conta++;
        }
    }
    return conta;
}

Estado geraEstado(Estado entrada, int acao){
    Coordenada posicao;
    Estado retorno = make_pair(make_pair(-1, -1), 0);
    /*verifica se pode fazer acao*/
    posicao = proxCoord(entrada.first, acao);
    if(!eCoordenadaNula(posicao)){
            /*verifica se posicao esta vazia*/
            if(!(entrada.second & mask[posicao.first][posicao.second])){
                /*cria estado*/
                retorno = make_pair(posicao, 
                       entrada.second | mask[posicao.first][posicao.second] );
            }
    }
    return retorno;
}

  
int testaPos(int x, int y)
{
    /***declaracoes internas***/
    Estado estado;
    priority_queue<int, vector<No*>, comparator > borda;
    int acaofinal = -1;
    No* p = nullptr;
    No* nofinal = nullptr;
    No* fila = nullptr;
    No* raiz = nullptr;
    No* pai = nullptr;
    map < Estado, bool > adicionados;
    bool continua = true;
    
    /*Inicio da Busca de melhor escolha*/
    estado = make_pair(make_pair(x,y), 0);
    raiz = fila = p = new No;
    if(p != nullptr){
        p->acoes = calculaAcoes(estado.first);
        p->estado = estado;
        p->pai = nullptr;
        p->next = nullptr;
        borda.push(p);
    }
    else
        cout << "[testaPos]Problemas com o new\n" << endl;
    while (!borda.empty() && continua) {
        p = borda.top();
        borda.pop();
        /***/
        if(TESTE_NIVEL_2){
            cout << p->acoes << " (" 
                 << p->estado.first.first 
                 << "," << p->estado.first.second 
                 << ") " << p->estado.second << endl;
        }
        /***/
        /*para cada acao possivel*/
        for(int i = 0; i < 8; i++){
            /*coleta estado gerado*/
            estado = geraEstado(p->estado, i);
            /***/  
            if(TESTE_NIVEL_2 && !eEstadoNulo(estado) ){
                cout << "Estado gerado: ("
                     << estado.first.first 
                     << "," << estado.first.second 
                     << ") " << estado.second << endl;
            }
            /***/
            /*verifica se ja esta em adicionado*/
            if(!adicionados.count(estado)){
                /*verifica se e estado meta*/
                if(estado.second == FULLBOARD){
                    continua = false;
                    saida.push_back(estado.first);
                    while(p != nullptr){
                        /*saida.push_back(p->estado.first);*/
                        cout << p << ":"
                             << p->estado.first.first << " "
                             << p->estado.first.second << endl;
                        p = p->pai;
                    }
                }
                /*gera no e adiciona na borda*/
                else{
                    pai = p;
                    p = new No;
                    if( p != nullptr){
                        fila->next = p;
                        fila = p;
                        p->estado = estado;
                        p->pai = pai;
                        p->next = nullptr;
                        p->acoes = calculaAcoes(estado.first);
                        adicionados[estado] = true;
                        borda.push(p);
                    }
                    else
                        cout << "[testaPos]Problemas com o new\n" << endl;
                }
            }
        }
    }
    p = raiz;
    while(p != nullptr){
        raiz = p->next;
        delete(p);
        p = raiz;
    }
    if(!continua){ 
        return 1;
    }
    else
        return 0;
}

int main(){
    cin >> board_n;
    iniciaMask();
    if(board_n <= 3){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(int i = 0; i < board_n; i++){
            for(int j = 0; j < board_n; j++){
                if(testaPos(i,j)){
                    i = j = board_n;
                }
            }
        }
        if(saida.empty()){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            /*printar saida*/
            cout << "SAIDA: " << endl;
        }
    }
return 0;
}
