#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define TESTE 0
#define MAXRANGE 10000 

int main()
{
	int p, q, l, r;
	int xtime[MAX][2], ytime[MAX][2];
    int contador, desl;
    int range[MAXRANGE];

	/*controle*/
	int i, j;

	scanf("%d", &p);
	scanf("%d", &q);
	scanf("%d", &l);
	scanf("%d", &r);
	
	for (i = 0; i < p; i++){
        scanf("%d", &ytime[i][0]);
        scanf("%d", &ytime[i][1]);
    }

	for (i = 0; i < q; i++){
        scanf("%d", &xtime[i][0]);
        scanf("%d", &xtime[i][1]);
    }

    /***/
    if(TESTE){
        printf("-----------\n");
        printf("%d %d %d %d\n", p, q, l, r);
	    for (i = 0; i < p; i++){
            printf("%d %d\n", ytime[i][0], ytime[i][1]);
        }
	    for (i = 0; i < q; i++){
            printf("%d %d\n", xtime[i][0], xtime[i][1]);
        }
        printf("-----------\n");
    }
    /***/

    for (i = l; i <= r; i++){
        range[i] = 0;
    }

	for (i = 0; i < p; i++){
	    for (j = 0; j < q; j++){
            for (desl = l; desl <= r; desl++){
                if(ytime[i][0] <= xtime[j][0] + desl && ytime[i][1] >= xtime[j][0] + desl){
                    range[desl] = 1;
                }
                else if(xtime[j][0] + desl <= ytime[i][0] && xtime[j][1] + desl >= ytime[i][0]){
                    range[desl] = 1;
                }
                else if(xtime[j][0] + desl > ytime[i][1]){
                    desl = r + 1;
                }
            }
        }
    }

    /*saida*/
    contador = 0;
    for (i = l; i <= r; i++){
        contador += range[i];
    }
    printf("%d\n", contador);

	return 0;
}
