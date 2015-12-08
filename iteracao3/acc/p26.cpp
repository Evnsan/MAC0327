/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/************Four Segments**********/
/***********************************/
/*************Problema 26***********/
/***********************************/
/*resubmetendo*/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 10e9 



using namespace std;

/*Estruturas auxiliares*/
struct Ponto{
    long int x, y;
};
struct Reta{
    Ponto p1, p2;
    char paralelo;

    struct Reta& setParalelo(){
        if(p1.x == p2.x && p1.y != p2.y)
            paralelo = 'y';
        else if(p1.y == p2.y && p1.x != p2.x)
            paralelo = 'x';
        else
            paralelo = 'f';
        return *this;
    }
};


/*Programa principal*/
int main(){
    Reta r[4];
    long int x, y;
    map<long int, int> eixox, eixoy;
    int xpar, ypar;


    /*Entrada*/
    for(int i = 0; i < 4; i++){
        cin >> x >> y;
        r[i].p1.x = x;
        r[i].p1.y = y;
        cin >> x >> y;
        r[i].p2.x = x;
        r[i].p2.y = y;
        r[i].setParalelo();
    }

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : retas" << endl;
        for(int i = 0; i < 4 ; i++){
            cout << "Reta " << i << ": ("
                 << r[i].p1.x << "," 
                 << r[i].p1.y << ") --> (" 
                 << r[i].p2.x << "," 
                 << r[i].p2.y << ") e paralelo ao eixo "
                 << r[i].paralelo << endl;
        }
    }
    /***/
    
    /*inicializando variaveis*/
    for(int i = 0; i < 4; i++){
        eixox[r[i].p1.x] = 0;
        eixoy[r[i].p1.y] = 0;
        eixox[r[i].p2.x] = 0;
        eixoy[r[i].p2.y] = 0;
    }
    xpar = 0;
    ypar = 0;


    /*Processamento*/
    for(int i = 0; i < 4; i++){
        if(r[i].paralelo == 'x'){
            xpar += 1;
        }
        else if(r[i].paralelo == 'y'){
            ypar += 1;
        }
        eixox[r[i].p1.x] += 1;
        eixoy[r[i].p1.y] += 1;
        eixox[r[i].p2.x] += 1;
        eixoy[r[i].p2.y] += 1;
    }
    /***/
    if(TESTE_NIVEL_1){
        cout << "EIXO X:" << endl;
        for( auto a : eixox){
            cout << "[" << a.first << "] = " << a.second << endl;
        } 
        cout << "EIXO Y:" << endl;
        for( auto a : eixoy){
            cout << "[" << a.first << "] = " << a.second << endl;
        }
    } 
    if(xpar == 2 && ypar == 2){
        for(int i = 0; i < 4; i++){
            /*se alguma entrada nao tem exatamente duas ocorrencias
              não pode ser retangulo*/
            if(eixox[r[i].p1.x] != 4 ||eixoy[r[i].p1.y] != 4 ||
               eixox[r[i].p1.x] != 4 ||eixoy[r[i].p2.y] != 4 ){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
