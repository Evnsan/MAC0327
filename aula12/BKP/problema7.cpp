/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 07*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 1000
#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0

using namespace std;

/***main***/
int main(){
    int nMercadorias;
    int nMaridos;
    int tempo;
    pair <int, string> atendimento; 
    pair <int, string> ligacao; 
    pair <int, string> tmp; 
    const pair <int, string> MyNull = make_pair(0, "0"); 
    queue<pair<int, string> > fila; 
    
    // typedef map<string, int> mapType2;
    // map<string, int> foo;
    typedef map<string, int> mapType;
    map<string, int> estoque;

    int entrada1;
    string entrada2;
    string entrada3;

    /*Entrada*/
    cin >> nMercadorias;
    for(int i = 0; i < nMercadorias; i++){
        cin >> entrada1 >> entrada2 >> entrada3;
        estoque[entrada3] = entrada1;
    }
    cin >> nMaridos;
    for(int i = 0; i < nMaridos; i++){
        cin >> entrada1 >> entrada2 >> entrada3;
        tmp = make_pair(entrada1, entrada3);
        fila.push(tmp);
    }
    fila.push(MyNull);
    /***/
    if(TESTE_NIVEL_2){
        cout << "A fila é:\n";
        while(!fila.empty()){
            tmp = fila.front();
            cout << tmp.first << " " << tmp.second << "\n";
            fila.pop();
        }
    }
    /***/
    /***/
    if(TESTE_NIVEL_2){
        cout << "O estoque é:\n";
        for (auto it = estoque.begin(); it != estoque.end(); ++it)
            cout << it->first << " => " << it->second << '\n';
    }
    /***/

    /*Processamento*/
    tempo = 0;
    ligacao = MyNull;
    tmp = MyNull;
    atendimento = fila.front();
    fila.pop();
    while(atendimento != MyNull){
        tempo++;
        /*atender*/
        if(estoque[atendimento.second] >= atendimento.first){
            estoque[atendimento.second] -= atendimento.first;
        }
        else if (estoque[atendimento.second] != 0) {
            atendimento.first = estoque[atendimento.second];
            tmp = atendimento;
        }
        /*pegar proximo*/
        if(ligacao != MyNull){
            atendimento = ligacao;
        }
        else{
            atendimento = fila.front();
            fila.pop();
        }
        /*consertar estruturas*/
        ligacao = tmp;
        tmp = MyNull;
    }
    
    /*Saida*/
    printf("%d\n", tempo);
    
    return 0;
}
