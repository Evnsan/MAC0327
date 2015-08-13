#include <stdio.h>
#include <stdlib.h>
 
#define TESTE 0

/*resubmetendo*/

int main()
{
	/*Declaracoes*/
	int n, entrada;
	int tamclustermax = 1, tamclusteratual = 1, nclusters = 0;
	
	int candidatosvelho, candidatosnovo, rotmelhor, rotcand, melhor;
	int digposimelhor, digposicand;
	int *clustersvelho, *clustersnovo;
	
	int *numero, **clusters;
	
	int resposta;
	
	/*controle*/
	int *tmp;
	int i = 0, inicio = 0, j = 0;
	
	/*Entrada de dados*/
	/*recebendo numero de digitos*/
	scanf("%d", &n);
	/*alocando e preenchendo vetor para digitos
	  e criando matriz de clusters*/
	numero =  (int*)malloc(n * sizeof(int));
	clusters =  (int**)malloc(n * sizeof(int*));
    clustersvelho = (int*)malloc(n * sizeof(int));
    clustersnovo = (int*)malloc(n * sizeof(int));
	
	scanf("%d" , &entrada);
	for (i = 0; i < n; i++){
	    clusters[i] = (int*)malloc(2 * sizeof(int));
	    numero[n-1-i] = entrada%10;
	    entrada = entrada/10;
	}
    
    /***/
    if(TESTE){
	    for (i = 0; i < n; i++)
	        printf("%d ", numero[i]);
        printf("\n");
    }
    /***/
    
    /*Processamento*/
    /*1 - procurar clusters de tamanho max*/
    for (i = 0; i < n; i++){
        tamclusteratual = 1;
        inicio = i;
        i++;
        while(numero[inicio] == numero[i] && i != inicio){
            tamclusteratual++;
            i = (i + 1)%n;
        }
        if(tamclusteratual > tamclustermax){
            nclusters = 1;
            clusters[0][0] = inicio;
            clusters[0][1] = (i ? i - 1 : n - 1);
            tamclustermax = tamclusteratual;
        }
        else if(tamclusteratual == tamclustermax){
            clusters[nclusters][0] = inicio;
            clusters[nclusters][1] = (i ? i - 1 : n - 1);
            nclusters++;
        }
        i = inicio + tamclusteratual - 1;
    
    }
    
    /***/
    if(TESTE){
	    for (i = 0; i < nclusters; i++)
	        printf("%d %d\n", clusters[i][0], clusters[i][1]);
    }      
    /***/
    
    /*2 - achar melhor cluster - gera menor digito depois do final do cluster*/
    candidatosvelho = nclusters;
    candidatosnovo = 1;
    melhor = 0;
    for (i = 0; i < candidatosvelho; i++)
        clustersvelho[i] = i;
    i = 1;
    while (i < n  && candidatosvelho != 1){
    /*i sera o deslocamento em relacao ao final do cluster*/
        for (j = 1; j < candidatosvelho; j++){
            /*comparar cada candidato j - avaliar posicao fim cluster + i*/
            rotmelhor = (10 - numero[ clusters[clustersvelho[melhor]][1] ])%10;
            digposimelhor = (numero[(clusters[clustersvelho[melhor]][1] + i)%n]
                             + rotmelhor)%10;
            rotcand = (10 - numero[clusters[clustersvelho[j]][1]])%10;
            digposicand = (numero[(clusters[clustersvelho[j]][1] + i)%n]
                             + rotcand)%10;

            if(TESTE){
	            printf("melhor = %d e candidato =  %d\n", melhor, j);
	            printf("deslocamento = %d \n", i);
	            printf("teste = %d x %d\n\n", digposicand, digposimelhor);
            }

            if(digposicand < digposimelhor){
                clustersnovo[0] = clustersvelho[j];
                candidatosnovo = 1;
                melhor = j;
            }
            else if(digposicand == digposimelhor){
                clustersnovo[candidatosnovo] = j;
                candidatosnovo++;
            }
        }
        tmp = clustersvelho;
        clustersvelho = clustersnovo;
        clustersnovo = tmp;

        candidatosvelho = candidatosnovo;
        
        if(TESTE){
    	    printf("candidatos velho = %d\n", candidatosvelho);
        }

        i++;
	}
	
	if(TESTE){
	    printf("melhor = %d\n", clustersvelho[0]);
    } 
	
	/*Resposta*/
	resposta = 0;
	rotmelhor = (10 - numero[clusters[clustersvelho[0]][1]])%10;
	for (i = 0; i < n; i++){
	    resposta *= 10;
	    j = (clusters[ clustersvelho[0] ][0] + i)%n;
	    resposta += (numero[j] + rotmelhor)%10;
	}
	
	for (i = 0; i < tamclustermax; i++)
		printf("0"); 
	printf("%d\n", resposta);
	
	
	/*freesss*/
	for (i = 0; i < n; i++)
	    free(clusters[i]);
	free(clusters);
	free(numero);
	free(clustersvelho);
	free(clustersnovo);
	
	return 0;
}
