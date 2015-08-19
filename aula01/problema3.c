#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TESTE 0

int colocaordem(char* vetora, char* vetorb, void* remov, int n);


int main()
{
	int n, m;
    int removidos[MAX];
    char matrix[MAX][MAX];
    int saida;
    /*controle*/	
	int i, j;

    /*entrada de dados*/
    scanf("%d", &n);
	scanf("%d", &m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            while(scanf("%c",&matrix[i][j]) && matrix[i][j] == '\n');
	
    /*inicializando*/
    for(i = 0; i < m; i++)
        removidos[i] = 0;
    
    /***/
    if(TESTE){
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++)
                printf("%c", matrix[i][j]);
            printf("\n");
        }
    }
    /***/

    /*Processamento*/
    for(i = 1; i < n; i++){
          if(colocaordem(matrix[i - 1], matrix[i], &removidos, m)){
              i = 0;
          }
    }

    /***/
    if(TESTE){
        printf("vetor removidos:\n");
        for(i = 0; i < m; i++){
            printf("%d ", removidos[i]);
        }
        printf("\n");
    }
    /***/

    /*Saida*/
    saida = 0;
    for(i = 0; i < m; i++)
        saida+=removidos[i];
    printf("%d\n", saida);

	return 0;
}

int colocaordem(char* vetora, char* vetorb, void* remov, int m){
    int i, removeu = 0;
    int* removidos = (int*)remov;

    /***/
    if(TESTE){
        printf("vetor removidos recebido em colocaordem:\n");
        for(i = 0; i < m; i++){
            printf("%d ", removidos[i]);
        }
        printf("\n");
    }
    /***/
    
    i = 0;

    while(i < m && removidos[i] == 1)
        i++;
    /***/
    if(TESTE){
    printf("%d<=0== i\n", i);
    }
    /***/

    while(i < m && vetora[i] >= vetorb[i]){
        /***/
        if(TESTE){
            printf("%d<=1== i\n", i);
            printf("teste executado: %c == %c\n",vetora[i], vetorb[i]);
            printf("resultado: %d\n", vetora[i] == vetorb[i]);
        }   
        /***/
        while(i < m && vetora[i] == vetorb[i])
            do{
                i++;
            } while(i < m && removidos[i] == 1);
        /***/
        if(TESTE){
            printf("%d<=2== i\n", i);
        }   
        /***/
        
        if(i < m && vetora[i] > vetorb[i]){
            removidos[i] = 1;
            removeu = 1;
            do{
                i++;
            } while(i < m && removidos[i] == 1);
        }
        
        /***/
        if(TESTE){
            printf("%d<=3== i\n", i);
            printf("teste executado: %c >= %c\n",vetora[i], vetorb[i]);
            printf("resultado: %d\n", vetora[i] >= vetorb[i]);
        }   
        /***/
    }
    return removeu;
}
