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
typedef unsigned int tabuleiro;
tabuleiro l0c0 = 1;
tabuleiro l0c1 = 1 << 1;
tabuleiro l0c2 = 1 << 2;
tabuleiro l0c3 = 1 << 3;
tabuleiro l1c0 = 1 << 4;
tabuleiro l1c1 = 1 << 5;
tabuleiro l1c2 = 1 << 6;
tabuleiro l1c3 = 1 << 7;
tabuleiro l2c0 = 1 << 8;
tabuleiro l2c1 = 1 << 9;
tabuleiro l2c2 = 1 << 10;
tabuleiro l2c3 = 1 << 11;
tabuleiro l3c0 = 1 << 12;
tabuleiro l3c1 = 1 << 13;
tabuleiro l3c2 = 1 << 14;
tabuleiro l3c3 = 1 << 15;
/*********************/
/***Globais***/
int board_n = 0;
vector< pair< int, int > > saida;
/*************/

struct comparator {
    bool operator()(pair< int, pair< pair<int, int>, int> >  i,
                    pair< int, pair< pair<int, int>, int> > j) {
    return i.first > j.first;
    }
};
  
int testaPos(int x, int y)
{
    priority_queue<int,
        vector< pair< int, pair< pair<int, int>, unsigned int> > >,
        comparator> borda;
  
    borda.push(make_pair(5, make_pair(make_pair(1,2), 10)));
  
    while (!borda.empty()) {
        cout << borda.top().first << " (" 
             << borda.top().second.first.first 
             << "," << borda.top().second.first.second 
             << ") " << borda.top().second.second << endl;
        borda.pop();
    }
    return 1;
}

int main(){
    cin >> board_n;
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
