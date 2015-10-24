/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 02*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 8 

#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0

using namespace std;
#include <queue>
#include <iostream>
  
using namespace std;
  
/***Tabuleiros-masq***/
typedef unsigned int Quad; /*quadrante*/
typedef tuple< Quad, Quad, Quad, Quad > Tabuleiro;
Quad mask[4][4][4];
/*********************/
typedef pair<int, int> Coordenada;
typedef pair< Coordenada, Tabuleiro > Estado;
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
Quad fQuad0 = 0;
Quad fQuad1 = 0;
Quad fQuad2 = 0;
Quad fQuad3 = 0;
/*************/

int iniciaMask(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                mask[i][j][k] = 1 << (j*4) + k;
            }
        }
    }
    return 0;
}

int calculaFullBoard(){
    if(board_n == 4){
        fQuad0 = 65535;
    }
    else if(board_n == 5){
        fQuad0 = 65535;
        fQuad1 = 4369;
        fQuad2 = 15;
        fQuad3 = 1;
    }
    else if(board_n == 6){
        fQuad0 = 65535;
        fQuad1 = 13107;
        fQuad2 = 255;
        fQuad3 = 51;
    }
    else if(board_n == 7){
        fQuad0 = 65535;
        fQuad1 = 30583;
        fQuad2 = 4095;
        fQuad3 = 1911;
    }
    else if(board_n == 8){
        fQuad0 = 65535;
        fQuad1 = 65535;
        fQuad2 = 65535;
        fQuad3 = 65535;
    }
    
    return 0;
}

tuple<int, int, int> calculaQuad(Coordenada pos){
    int q, x, y;
    tuple<int, int, int> retorno;

    if(pos.first > 3){
        x = pos.first - 4;
        if(pos.second > 3){
            y = pos.second - 4;
            q = 3;
        }
        else{
            y = pos.second;
            q = 2;
        }
    }
    else{
        x = pos.first;
        if(pos.second > 3){
            y = pos.second - 4;
            q = 1;
        }
        else{
        y = pos.second;
        q = 0;
        }
    }
    retorno = make_tuple(q, x, y);
    return retorno;
}

bool eMeta(Tabuleiro tabuleiro){
    Quad q0 = get<0>(tabuleiro);
    Quad q1 = get<1>(tabuleiro);
    Quad q2 = get<2>(tabuleiro);
    Quad q3 = get<3>(tabuleiro);
    if(q0 == fQuad0 && q1 == fQuad1 && q2 == fQuad2 && q3 == fQuad3)
        return true;
    else
        return false;
}

bool coordEmUso(Coordenada posicao, Tabuleiro tabuleiro){
    Quad qTab;
    Quad qT0, qT1, qT2,qT3;
    /*calcula quadrante da posicao*/
    tuple<int, int, int> mask_index;
    int index, x, y;
   
    mask_index = calculaQuad(posicao);
    
    index = get<0>(mask_index);
    x = get<1>(mask_index);
    y = get<2>(mask_index);
    qT0 = get<0>(tabuleiro);
    qT1 = get<1>(tabuleiro);
    qT2 = get<2>(tabuleiro);
    qT3 = get<3>(tabuleiro);

    if(index == 0)
        qTab = qT0;
    else if(index == 1)
        qTab = qT1;
    else if(index == 2)
        qTab = qT2;
    else
        qTab = qT3;

    if(TESTE_NIVEL_1 && false){
        cout << "indices: " << index << " " << x << " "<< y << endl
             << "quadrantes: " << endl
             << qT0 << endl
             << qT1 << endl
             << qT2 << endl
             << qT3 << endl
             << "quadrante escolhido: " << endl
             << qTab << endl
             << "Mask: " << endl
             << mask[index][x][y] << endl;
    }

    if(mask[index][x][y] & qTab)
        return true;

    return false;
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
Tabuleiro geraProxTabuleiro(Coordenada posicao, Tabuleiro velho){
    Tabuleiro retorno;
    Quad qT0, qT1, qT2, qT3;
    tuple<int, int, int> posTrad;
    int index, x, y;

    posTrad = calculaQuad(posicao);
    index = get<0>(posTrad);
    x = get<1>(posTrad);
    y = get<2>(posTrad);
    
    if(index == 0){
        qT0 = get<0>(velho) | mask[index][x][y];
        qT1 = get<1>(velho);
        qT2 = get<2>(velho);
        qT3 = get<3>(velho);
    }
    else if(index == 1){
        qT0 = get<0>(velho);
        qT1 = get<1>(velho) | mask[index][x][y];
        qT2 = get<2>(velho);
        qT3 = get<3>(velho);
    }
    else if(index == 2){
        qT0 = get<0>(velho);
        qT1 = get<1>(velho);
        qT2 = get<2>(velho) | mask[index][x][y];
        qT3 = get<3>(velho);
    }
    else{
        qT0 = get<0>(velho);
        qT1 = get<1>(velho);
        qT2 = get<2>(velho);
        qT3 = get<3>(velho) | mask[index][x][y];
    }
    
    retorno = make_tuple(qT0, qT1, qT2, qT3);
    return retorno;
}

Estado geraEstado(Estado entrada, int acao){
    Coordenada posicao;
    Estado retorno = make_pair(make_pair(-1, -1), make_tuple(0, 0, 0, 0));
    /*verifica se pode fazer acao*/
    posicao = proxCoord(entrada.first, acao);
    if(!eCoordenadaNula(posicao)){
            /*verifica se posicao esta vazia*/
            if(!coordEmUso(posicao, entrada.second)){
                /*cria estado*/
                retorno = make_pair(posicao,
                            geraProxTabuleiro(posicao, entrada.second)); 
            }
    }
    return retorno;
}

  
int testaPos(int x, int y)
{
    /***declaracoes internas***/
    Tabuleiro tab;
    Coordenada pos;
    Estado estado;
    priority_queue<int, vector<No*>, comparator > borda;
    No* p = nullptr;
    No* fila = nullptr;
    No* raiz = nullptr;
    No* pai = nullptr;
    map < Estado, bool > adicionados;
    bool continua = true;
    
    /*Inicio da Busca de melhor escolha*/
    pos = make_pair(x, y);
    tab = geraProxTabuleiro(pos, make_tuple(0, 0, 0, 0));
    estado = make_pair(pos, tab);
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
                 << ") q0 " << get<0>(p->estado.second)
                 << " q1 " << get<1>(p->estado.second)
                 << " q2 " << get<2>(p->estado.second)
                 << " q3 " << get<3>(p->estado.second) << endl;
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
                     << ") q0 " << get<0>(p->estado.second)
                     << " q1 " << get<1>(p->estado.second)
                     << " q2 " << get<2>(p->estado.second)
                     << " q3 " << get<3>(p->estado.second) << endl;
            }
            /***/
            /*verifica se ja esta em adicionado*/
            if(!eEstadoNulo(estado) && !adicionados.count(estado)){
                /*verifica se e estado meta*/
                if(eMeta(estado.second)){
                     cout << ") q0 " << get<0>(estado.second)
                          << " q1 " << get<1>(estado.second)
                          << " q2 " << get<2>(estado.second)
                          << " q3 " << get<3>(estado.second) << endl;
                    continua = false;
                    saida.push_back(estado.first);
                    while(p != nullptr){
                        saida.push_back(p->estado.first);
                    /*    cout << p << ":"
                             << p->estado.first.first << " "
                             << p->estado.first.second << " "
                             << p->estado.second << endl;
                      */  p = p->pai;
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
                        /*cout << "Adiocionado a borda: "
                             << p << ":"
                             << p->estado.first.first << " "
                             << p->estado.first.second << " "
                             << p->estado.second << endl;
                             */
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
        calculaFullBoard();
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
            while(!saida.empty()){
                printf( "(%d,%d) ", saida.back().first, saida.back().second);
                saida.pop_back();
            }
        }
    }
return 0;
}
/*
int main (){
    Tabuleiro tab;
    iniciaMask();
    tuple<int, int, int> posTrad;
    Coordenada pos;
    cin >> board_n;
    calculaFullBoard();
    cout << "FULBOARD:" << endl
         << fQuad0 << endl
         << fQuad1 << endl
         << fQuad2 << endl
         << fQuad3 << endl;
    
    tab = make_tuple(65535, 0, 0, 0);
    if(eMeta(tab)){
        cout << "SIM!" << endl;
    }
    else
       cout << "NAO!" << endl;
    tab = make_tuple(10, 1, 1, 1);
    pos = make_pair(4,3);
    tab = geraProxTabuleiro(pos, tab);
    cout << "q0: " << get<0>(tab)
         << " q1: " << get<1>(tab)
         << " q2: " << get<2>(tab)
         << " q3: " << get<3>(tab) << endl;
    if(coordEmUso(pos, tab))
        cout << "(4,3) esta em uso" << endl;

    posTrad = calculaQuad(pos);
    cout << "Traducao de (4,3)i:" << endl
         << get<0>(posTrad) << endl
         << get<1>(posTrad) << endl
         << get<2>(posTrad) << endl;


    return 0;
}*/
