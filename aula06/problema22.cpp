/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 22*************/
/***********************************/

#include <iostream>
#include <list>

#define MAX 250000

using namespace std;


int main(){
    long int n, numero;
    
    /* +1 para realizar a insercao em vetor cheio*/
     list<long int> sequencia;
    
    long int guardados;

    /*controle*/
    long int i;

    list<long int>::iterator j;

    /*Entrada*/
    cin >> n;
    guardados = 0;
    for(i = 0; i < n; i++){
        cin >>  numero;
        /*procura onde inserir*/
        j = sequencia.begin();
        while(*j < numero)
            j++;/*
        if(j != sequencia.begin())
            j--;*/
        /*insere na lista*/
        sequencia.insert(j,numero);
    }

    for(j = sequencia.begin(); j != sequencia.end(); j++)
        cout << *j << " ";
    cout << endl;

    /*Processamento*/

    /*Saida*/
    return 0; 

}
