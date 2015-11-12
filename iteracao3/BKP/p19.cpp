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
    
    /*Entrada*/
    cin >> n;
    cin >> divisores[0];
    cin >> divisores[1];
    cin >> divisores[2];
    
    /*Merge sort na mao - n = 3*/
    if(divisores[1] < divisores[0]){
        tmp = divisores[0];
        divisores[0] = divisores[1];
        divisores[1] = tmp;
    }
    if(divisores[2] < divisores[0]){
        tmp = divisores[1];
        divisores[1] = divisores[0];
        divisores[0] = divisores[2];
        divisores[2] = tmp;
    }
    else if(divisores[2] < divisores[1]){
        tmp = divisores[1];
        divisores[1] = divisores[2];
        divisores[2] = tmp;
    }

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN: n = " << n << endl;
        cout << "MAIN: divisores[0] = " << divisores[0] << endl;
        cout << "MAIN: divisores[1] = " << divisores[1] << endl;
        cout << "MAIN: divisores[2] = " << divisores[2] << endl;
    }
    /***/
    /*inicializando*/
    k = l = m = 0;
    /*Processamento*/
    k = n/divisores[0];
    resto = n % divisores[0];
    while(k > 0 && resto != 0){
        k--;
        resto += divisores[0];
        l = resto / divisores[1];
        resto %= divisores[1];
        /***/
        if(TESTE_NIVEL_1){
            cout << "INTERNO: k = " << k << endl;
            cout << "INTERNO: l = " << l << endl;
            cout << "INTERNO: m = " << m << endl;
            cout << "INTERNO: RESTO = " << resto << endl;
        }
        /***/
        while(l > 0 && resto != 0){
            l--;
            resto += divisores[1];
            m = resto/divisores[2];
            resto %= divisores[2];
            /***/
            if(TESTE_NIVEL_1){
                cout << "INTERNO: k = " << k << endl;
                cout << "INTERNO: l = " << l << endl;
                cout << "INTERNO: m = " << m << endl;
                cout << "INTERNO: RESTO = " << resto << endl;
            }
            /***/
        }
    }
    cout << k + l + m << endl;
                


       

    

    return 0;
}
