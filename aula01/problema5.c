#include <stdio.h>
#include <stdlib.h>
 
#define TESTE 1

int main()
{
	/*Declaracoes*/
	int npartituras, natores, capatores;
	int **partituras, **atores;
	
	int tamgrafo, posicao;
	int **grafoflux, **indexator;;
	int *index;
	
	/*controle*/
	int i = 0, j = 0;
	
	/*Entrada de dados*/
	/*recebendo numero de partituras*/
	scanf("%d", &npartituras);
	/*alocando e preenchendo matriz partituras*/
    partituras =  (int**)malloc(npartituras * sizeof(int*));
    for (i = 0; i < npartituras; i++){
        partituras[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d", &partituras[i][0]);
        scanf("%d", &partituras[i][1]);
    }
    /*recebendo numero de atores*/
	scanf("%d", &natores);
	/*alocando e preenchendo matriz atores*/
    atores =  (int**)malloc(natores * sizeof(int*));
    capatores = 0;
    for (i = 0; i < natores; i++){
        atores[i] = (int*)malloc(3 * sizeof(int));
        scanf("%d", &atores[i][0]);
        scanf("%d", &atores[i][1]);
        scanf("%d", &atores[i][2]);
        capatores += atores[i][2];
    }
    
    /*alocando matriz grafoflux*/
    tamgrafo = npartituras + capatores + 2;
    grafoflux =  (int**)malloc(tamgrafo * sizeof(int*));
    for (i = 0; i < tamgrafo; i++){
        grafoflux[i] = (int*)malloc(tamgrafo * sizeof(int));
        for(j = 0; j < tamgrafo; j++)
            grafoflux[i][j] = 0;
    }
    /*alocando indexator*/
    indexator = (int**)malloc(natores * sizeof(int));

    /*criando index de traducao para grafoflux + indexator*/
    index = (int*)malloc(tamgrafo * sizeof(int));
    for (i = 0; i < npartituras; i++)
        index[i] = i;
    posicao = npartituras;
    for (i = 0; i < natores; i++){
        j = atores[i][2];
        indexator[i] = (int*)malloc(2 * sizeof(int));
        indexator[i][0] = posicao;
        indexator[i][1] = posicao + j - 1;
        while(j != 0){
            index[posicao] = i + 1;
            posicao++;
            j--;
        }
    }
    index[posicao++] = -1; /*vertice s*/
    index[posicao] = -2; /*vertice t*/
   
    /*preenchendo grafoflux*/
    
    for (i = 0; i < npartituras; i++)
        grafoflux[tamgrafo - 2][i] = 1;
    for (i = npartituras; i < tamgrafo; i++)
        grafoflux[tamgrafo - 1][i] = 1;
    
    for (i = 0; i < natores; i++)
	for (j = 0; j < npartituras; j++){
		
        



    /***/
    if(TESTE){
	    for (i = 0; i < npartituras; i++)
	        printf("%d [%d - %d] \n", i, partituras[i][0], partituras[i][1]);
        printf("\n");
        printf("Capacidade total dos atores = %d\n", capatores);
    }
    /***/
    
    /*Processamento*/
 
	/*Resposta*/
	
	if(TESTE){
	    for (i = 0; i < tamgrafo; i++){
	        for( j = 0; j < tamgrafo; j++)
	            printf("%d ", grafoflux[i][j]);
	        printf("\n");
	    }
        printf("indexator\n");
	    for(i = 0; i < natores; i++)
	        printf("(%d - %d) ", indexator[i][0], indexator[i][1]);
        printf("\n");

        printf("index\n");
	    for(i = 0; i < tamgrafo; i++)
	        printf("%d ", index[i]);
        printf("\n");

	}
	
	/*freesss*/
	for (i = 0; i < npartituras; i++)
	    free(partituras[i]);
	free(partituras);
	for (i = 0; i < natores; i++)
	    free(atores[i]);
	free(atores);
	for (i = 0; i < npartituras; i++)
        free(grafoflux[i]);
    free(grafoflux);
	
	return 0;
}
