/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 07*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 1000
#define TESTE_NIVEL_1 0

using namespace std;

/***main***/
int main(){
    int nMercadorias;
    int nMaridos;
    pair <int, string> atendimento; 
    pair <int, string> ligacao; 
    pair <int, string> tmp; 
    vector<pair<int, string> > fila; 
    // typedef map<string, int> mapType2;
    // map<string, int> foo;
    typedef map<string, int> mapType;
    map<string, int> estoque;

    int entrada1;
    string entrada2;

    cin >> nMercadorias;
    for(int i = 0; i < nMercadorias; i++){
        cin >> entrada1 >> entrada2;
        cout << "N = " << entrada1 <<

    
    atendimento = make_pair(5, "teste");
    cout << atendimento.first;
    ligacao = atendimento;
    atendimento = make_pair(8, "testado");
    cout << " " << ligacao.second << "\n";
    cout << atendimento.first << " " << atendimento.second << "\n";;
    
    /*Saida*/
    
    return 0;
}
