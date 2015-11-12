/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/*************Cut Ribbon************/
/***********************************/
/*************Problema 19***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 4000


using namespace std;

int main(){
    int n;
    int divisores[3];
    int tmp;
    int soma;
    int si, sj;
    int k;
    int resto;
    
    /*Entrada*/
    cin >> n;
    cin >> divisores[0];
    cin >> divisores[1];
    cin >> divisores[2];
   
    soma = 0;
    for(int i = 0; i*divisores[0] <= n; i++){
        si = i*divisores[0];
        for(int j = 0; j*divisores[1] + si <= n; j++){
            resto = n - si - j*divisores[1];
            k = resto / divisores[2];
            resto %= divisores[2];
            if(resto == 0 && (i + j + k > soma))
                soma = i + j + k;
        }
    }
    cout << soma << endl;

    return 0;
}
