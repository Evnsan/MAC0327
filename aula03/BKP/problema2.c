#include <stdio.h>
#include <stdlib.h>

#define TESTE 0

int main()
{
    int check[33][33], pilha[1089][2], atual[2];
    int n, nparedes, topo;
    int lin, col;
    char a[33][33];
    char ch;
    /*controle*/
    int i, j;

    /*entrada de dados*/
    scanf("%d", &n);
	/*recebendo matrix*/
	for(i = 0; i < n; i++)
    	for(j = 0; j < n; j++){
            while(scanf("%c", &ch) && ch == '\n');
            a[i][j] = ch;
            check[i][j] = 0;
        }
    if(TESTE){
    	for(i = 0; i < n; i++){
        	for(j = 0; j < n; j++)
                printf("(%c ", a[i][j]);
            printf("\n");
        }
    }
    
    /*inicializando pilha e check*/
    /*entrada superior*/
    check[0][0] = 1;
    pilha[0][0] = 0;
    pilha[0][1] = 0;
    /*entrada inferior*/
    check[n-1][n-1] = 1;
    pilha[1][0] = n-1;
    pilha[1][1] = n-1;
    topo = 2;
    nparedes = 0;


    while(topo > 0){
        atual[0] = pilha[topo - 1][0];
        atual[1] = pilha[topo - 1][1];
        /*teste*/
        if(TESTE){
            printf("%d\n", nparedes);
            for(j = 0; j< topo; j++)
                printf( "%d %d, ", pilha[j][0], pilha[j][1]);
            printf(" => atual %d %d\n", atual[0], atual[1]);
        }
        /*teste*/
        topo--;
        for(j = 0; j < 4; j++){
            switch(j){
                case 0:
                    /*direita*/
                    lin = atual[0];
                    col = atual[1] +1;
                break;

                case 1:
                    /*esquerda*/
                    lin = atual[0];
                    col = atual[1] -1;
                break;

                case 2:
                    /*cima*/
                    lin = atual[0] - 1;
                    col = atual[1];
                break;

                case 3:
                    /*baixo*/
                    lin = atual[0] + 1;
                    col = atual[1];
                break;
            }
            /*olhar*/
            if(lin >= n || col >= n || lin < 0 || col < 0 || a[lin][col] == '#')
                nparedes++;
            else if(!check[lin][col]){
                check[lin][col] = 1;
                pilha[topo][0] = lin;
                pilha[topo][1] = col;
                topo++;
            }
        }
    }
    printf("%d\n", (nparedes - 4)*9);
        
    return 0;
}
