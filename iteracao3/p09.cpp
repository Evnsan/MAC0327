/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/****************Rope***************/
/***********************************/
/*************Problema 09***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAXN 100

using namespace std;
typedef pair<float, float> Ponto;

/*****************/

/***main***/
int main(){
    int p_num = 0;
    Ponto p1;
    Ponto pant;
    Ponto patual;
    float saida;
    float raio;
    float entrada1, entrada2;

    cin >> p_num >> raio;

    /* raio*( n*pi - (n-2)pi ) = raio*2*pi */
    saida = 2*raio*3.14159265358979323846;
    
    cin >> entrada1 >> entrada2;
    p1 = make_pair(entrada1, entrada2);
    pant = p1;
    if(p_num > 1){
        for(int i = 1; i < p_num ; i++){

            cin >> entrada1 >> entrada2;
            /***/
            if(TESTE_NIVEL_1){
                cout << "Fazendo o ponto (" << entrada1
                     << "," << entrada2 << ")" << endl;
            }
            /***/
            patual = make_pair(entrada1, entrada2);
            saida += sqrt(pow(patual.first - pant.first, 2.0) + 
                         pow(patual.second - pant.second, 2.0));
            pant = patual;
        }
        /*fechando o circuito*/
        saida += sqrt(pow(pant.first - p1.first, 2.0) + 
                      pow(pant.second - p1.second, 2.0));
    }
    
    /***saida***/
    printf("%.2f\n", saida);
        
    return 0;
}
