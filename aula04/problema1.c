#include <stdio.h>
#include <stdlib.h>

#define MAX 102

int compara(const void *a, const void *b);

int main()
{
    int n, saida;
    int grupos[MAX];
    /*controle*/
    int i;
    
    /*inicializacao*/
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &grupos[i]);
    for(i = n; i < MAX; i++)
        grupos[i] = 99999;
    
  

    /*Processamento*/
    
    /*sort*/
    qsort(grupos, MAX, sizeof(int), compara);
    
    n /= 2;
    saida = 0;
    for(i = 0; i <= n; i++)
        saida += (grupos[i]/2 + 1);
    
    /*saida*/
    printf("%d\n", saida);
    
    return 0;
}

int compara(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
    
