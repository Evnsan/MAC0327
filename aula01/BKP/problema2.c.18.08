#include<stdio.h>

#define MAX 1000
#define TESTE 0 

int main(){
    int n;
    char entrada;
    int numero[MAX];
    /*parte 1*/
    int nclusters, clusters[MAX][2];
    int tamclusteratual, tamclustermax;
    int inicio;
    /*parte 2*/
    int vetor1[MAX], vetor2[MAX];
    int candidatosvelho, candidatosnovo;
    int rotcand, rotmelhor;
    int melhor;
    int digposcand, digposmelhor;
    int *tmp, *clustersvelho, *clustersnovo;

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
    /*parte 1 - achando clusters*/
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

    /*parte 2 - achando melhor cluster*/
    candidatosvelho = nclusters;
    candidatosnovo = 1;
    melhor = 0;
    clustersvelho = vetor1;
    clustersnovo = vetor2;

    for(i = 0; i < candidatosvelho; i++)
        clustersvelho[i] = i;
    clustersnovo[0] = 0;

    /***/
    if(TESTE){
        for(i = 0; i < candidatosvelho; i++)
            printf("%d ",clustersvelho[i]);
        printf("\n");
    }
    /***/
    i = 1;
    while(i < n && candidatosvelho != 1){
        for(j = 1; j < candidatosvelho; j++){
            /*preparando melhor*/
            rotmelhor = (10 - numero[ clusters[clustersvelho[melhor]][0] ])%10;
            digposmelhor = (numero[ (clusters[clustersvelho[melhor]][0] + i)%n] 
                            + rotmelhor)%10;
            /*preparando candiato*/
            rotcand = (10 - numero[ clusters[clustersvelho[j]][0] ])%10;
            digposcand = (numero[ (clusters[clustersvelho[j]][0] + i)%n ]
                            + rotcand)%10;
            /***/
            if(TESTE){

                printf("posmelhor = %d e poscand = %d\n", clustersvelho[melhor],
                        clustersvelho[j]);

                printf("digposmelhor = %d e numero = %d\n", digposmelhor,
                        numero[ (clusters[clustersvelho[melhor]][0] + i  )%n]);
                printf("digposcand = %d e numero = %d\n", digposcand,
                        numero[ (clusters[clustersvelho[j]][0] + i  )%n]);
                printf("rotmelhor = %d e rotcand = %d\n", rotmelhor, rotcand);
                printf("melhor = %d e candidato = %d\n", melhor, j);
                printf("deslocamento = %d\n", i);
                printf("teste = %d x %d\n\n", digposcand , digposmelhor);
            }
            /***/
            if(digposcand < digposmelhor){
                clustersnovo[0] = clustersvelho[j];
                candidatosnovo = 1;
                melhor = j;
            }
            else if(digposcand == digposmelhor){
                clustersnovo[candidatosnovo] = clustersvelho[j];
                candidatosnovo++;
            }
        }
        /***/
        if(TESTE){
            printf("candidatosnovo = %d \n", candidatosnovo);
        }
        /***/
        tmp = clustersvelho;
        clustersvelho = clustersnovo;
        clustersnovo = tmp;
        clustersnovo[0] = clustersvelho[melhor];

        candidatosvelho = candidatosnovo;
        candidatosnovo = 1;

        i++;
    }
    /*saida*/
    j = clusters[ clustersvelho[0] ][0];
    rotmelhor = (10 - numero[ clusters[clustersvelho[0]][0] ])%10;
    /***/
    if(TESTE){
        printf(" escolhidos: cluster de %d, com rot %d na posicao %d \n",
                numero[j], rotmelhor, j);
    }
    /***/
    for(i = 0; i < n; i++){
        printf("%d", (numero[j] + rotmelhor)%10);
        j = (j + 1)%n;
    }
    printf("\n");


    return 0;
}


