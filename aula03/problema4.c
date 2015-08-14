#include <stdio.h>

#define MAX 37

int main()
{
    int n, soma, saida;
    long int i, candidato, max;
    int parcial[MAX];
    
    /*inicializacao*/
    for(i = 0; i < MAX; i++)
        parcial[i] = 0;
    
    scanf("%d", &n);
    
    n /= 2;
    
    max = 1;
    for(i = 0; i < n; i++)
        max *= 10;
    
    /*Processamento*/
    for(i = 0; i < max; i++){
        candidato = i;
        soma = 0;
        while(candidato != 0){
            soma += candidato % 10;
            candidato /= 10;
        }
        parcial[soma] += 1;
    }
    
    saida = 0;
    for(i = 0; i < MAX; i++)
        saida += (parcial[i] * parcial[i]);
    
    /*saida*/
    printf("%d\n", saida);
    
    return 0;
}
    
