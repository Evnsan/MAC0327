#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, f;
    long int size, animal, friendship;
    long int soma[20];
    /*controle*/
    int i = 0;

    scanf("%d", &n);
	
	for(i = 0; i < n; i++){
        scanf("%d", &f);
        soma[i] = 0;
	    while( f > 0 ){
            scanf("%ld", &size);
            scanf("%ld", &animal);
            scanf("%ld", &friendship);
            soma[i] += size*friendship;
            f--;
        }
    }
	for(i = 0; i < n; i++){
	    printf("%ld\n", soma[i]);
	}
    return 0;
}
