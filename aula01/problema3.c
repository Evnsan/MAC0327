#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TESTE 1

int main()
{
	int n, m;
    char matrix[MAX][MAX];
    /*controle*/	
	int i, j;

    /*inicializando*/
	scanf("%d", &n);
	scanf("%d", &m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            while(scanf("%c",&matrix[i][j]) && matrix[i][j] == '\n');
    /***/
    if(TESTE){
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++)
                printf("%c", matrix[i][j]);
            printf("\n");
        }
    }
    /***/

    
	return 0;
}
