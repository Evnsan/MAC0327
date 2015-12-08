/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********Series of Crimes*********/
/***********************************/
/*************Problema 29***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 10e9 

using namespace std;

/*main*/
int main(){
    map<int,int> px;
    map<int,int> py;
    int n, m;
    char pos;
    int x, y;

    /*Entrada e Processamento*/
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> pos;
            if(pos == '*'){
                if(px.find(i) == px.end()){
                    px[i] = 1;
                }
                else{
                    px[i] += 1;
                }
                if(py.find(j) == py.end()){
                    py[j] = 1;
                }
                else{
                    py[j] += 1;
                }
            }
        }
    }

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : " << n << "x" << m << endl;
        cout << "MAIN : px" << endl;
        for(auto a : px){
           cout << a.first << " " << a.second << endl; 
        }
        cout << "MAIN : py" << endl;
        for(auto a : py){
           cout << a.first << " " << a.second << endl; 
        }
    }
    /***/

    for(auto a : px){
        if(a.second == 1){
            x = a.first + 1;
        }
    }
    for(auto a : py){
        if(a.second == 1){
            y = a.first + 1;
        }
    }
    /*Saida*/
    cout << x << " " << y << endl;

    return 0;
}
