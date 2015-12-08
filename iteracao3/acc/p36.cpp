/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********Cows and Sequence********/
/***********************************/
/*************Problema 36***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAXOP 200000 
#define MAXNUM 1000 

using namespace std;

/*main*/
int main(){
    long int n;
    long long int soma;
    long long int dif[MAXOP];
    long int tam;
    int op;
    int arg1, arg2;
    double media;

    /*inicializando*/
    tam = 1;
    dif[tam - 1] = 0;
    soma = 0;

    /*Entrada*/
    cin >> n;
    for(long int i = 0; i < n; i++){
        cin >> op;
        if(op == 1){
            cin >> arg1 >> arg2;
            soma += (arg1 * arg2);
            if(arg1 == tam){
                dif[arg1 - 1] += arg2;

            }
            else if(arg1 < tam){
                dif[arg1 - 1] -= arg2;
            }
            else{
                cout << "LIMITEDE OPERACAO INVALIDO" << endl;
            }
        }
        else if(op == 2){
            /*adiciona arg1 no final do array*/
            cin >> arg1;
            soma += arg1;
            dif[tam - 1] = arg1 - dif[tam - 1];
            dif[tam] = arg1;
            tam += 1;
        }
        else{
            /*remove o ultimo*/
            soma -= dif[tam - 1];;
            dif[tam - 2] = dif[tam - 1] - dif[tam - 2];
            tam -= 1;
        }

        media = soma*1.0 / tam;
        printf( "%.10lf\n", media);
    }

    /*Saida*/
    return 0;
}
