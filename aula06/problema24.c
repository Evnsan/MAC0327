/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 24*************/
/***********************************/

#include<stdio.h>

#define MAX 1000000

typedef struct node *Node;
struct node{
    long int valor;
    Node prox;
    };


int main(){
    long int n, m;
    *Node pool[2*MAX + 1];
    Node embaixo[MAX];
    Node emcima[MAX];
    Node p;
    Node retirado;
    long int topoPool;

    long int entrada1, entrada2;

    /*controle*/
    long int i;

    /*inicializacao*/
    for(i = 0; i < MAX; i++){
        embaixo[i] = emcima[i] = NULL;
    }
    retirado = pool[0];
    topoPool = 1;

    /*Entrada*/
    scanf("%ld", &n);
    scanf("%ld", &m);
    for(i = 0; i < m; i++){
        scanf("%ld", &entrada1);
        scanf("%ld", &entrada2);
        p = pool[topoPool];
        topoPool++;
        p->valor = entrada2;
        p->prox = emcima[entrada1];
        emcima[entrada1] = p;
    }

    /*Processamento*/

    /*Saida*/

    return 0;
}
