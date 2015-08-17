#include<stdio.h>

#define MAX 1000
#define TESTE 1

int main(){
    int n;
    char entrada;
    int numero[MAX];
    /*parte 1*/
    int nclusters, clusters[MAX][2];
    int tamclusteratual, tamclustermax;
    int inicio;

    /*controle*/
    int i, j;

    /*Inicializacao*/
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        while(scanf("%c", &entrada) && entrada == '\n');
        numero[i] = (int)(entrada - '0');
    }
    /***/
    if(TESTE){
        for (i = 0; i < n; i++)
            printf("%d ", numero[i]);
        printf("\n");
    }
    /***/
    
    /*Processamento*/
    /*achando clusters*/
    tamclustermax = 1;
    nclusters = 0;
    for(i = 0; i < n; i++){
        tamclusteratual = 1;
        inicio = i;
        i++;
        while(numero[inicio] == numero[i] && i != inicio){
            tamclusteratual++;
            i = (i + 1)%n;
        }
        if(tamclusteratual >= tamclustermax){
            if(tamclusteratual > tamclustermax)
                nclusters = 0;
            clusters[nclusters][0] = inicio;
            clusters[nclusters][1] = (i ? i - 1: n - 1);
            nclusters++;
        }
        i = inicio + tamclusteratual - 1;
    }

    /***/
    if(TESTE){
        printf("nclusters = %d:\n", nclusters);
        for (i = 0; i < nclusters; i++)
            printf("%d %d\n", clusters[i][0], clusters[i][1]);
    }
    /***/

    /*achando melhor cluster*/
    
    
    
    /*reposta*/
    rotmelhor = (10 - numero[clusters[*clustersvelho[0]][1]])%10;
    for(i = 0; i < n; i++){
        printf("clustersvelho[0] = %d\n", *clustersvelho[0]);
        j = (clusters[ *clustersvelho[0] ][0] + i)%n;
        printf("%d",(numero[j] + rotmelhor)%10);
    }
    printf("\n");

    return 0;
}


