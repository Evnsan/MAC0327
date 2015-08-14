#include <stdio.h>
#include <stdlib.h>

#define MAX 15000
#define TESTE 0

int eprimo(int primos[], int achados, int candidato);

int main()
{
    int n, max;
    int candidato, achados;
    int entrada[MAX], primos[MAX];
    /*controle*/
    int i;
    
    /*inicializacao*/
    scanf("%d", &n);
    max = 0;
    
    for(i = 0; i < n; i++){
        scanf("%d", &entrada[i]);
        if(max < entrada[i])
            max = entrada[i];
    }

    /*Processamento*/
    achados = 1;
    candidato = 3;
    primos[0] = 2;
    while( achados < max ){
        while(!eprimo(&primos[0], achados, candidato)){
            candidato++;
        }
        primos[achados] = candidato;
        achados++;
    }
   
    /*saida*/
    for(i = 0; i < n; i++)
        printf("%d\n", primos[entrada[i] - 1]);
    if(TESTE){    
        for(i = 0; i < max; i++)
            printf("%d ", primos[i]);
        printf("\n 4 é primo? %d \n",eprimo(&primos[0], achados, candidato));
    }
    return 0;
}

int eprimo(int primos[], int achados, int candidato){
    int i;
    
    for(i = 0; i < achados; i++){
        if(candidato%primos[i] == 0)
            return 0;
    }
    return 1;
}
