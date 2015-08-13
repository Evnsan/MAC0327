#include <stdio.h>
#include <stdlib.h>

int main()
{
	int p, q, l, r;
	int **xtime, **ytime;
    int contador;

	/*controle*/
	int i = 0;

	scanf("%d", &p);
	scanf("%d", &q);
	scanf("%d", &l);
	scanf("%d", &r);
	
	xtime = (int**)malloc(p * sizeof(int*));
	
	for (i = 0; i < p; i++){
	    xtime[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d", &xtime[i][0]);
        scanf("%d", &xtime[i][1]);

	ytime = (int**)malloc(p * sizeof(int*));
	
	for (i = 0; i < q; i++){
	    ytime[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d", &ytime[i][0]);
        scanf("%d", &ytime[i][1]);

    for (desl = l; desl <= r; desl++)
        if(verifica(desl, &xtime, &ytime))
            contador++;

	return 0;
}

int verifica( int desl, int ***xtime, int ***ytime){

    return 0;
}
