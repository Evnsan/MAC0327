#include <stdio.h>
#include <math.h>

int main()
{
    int n, n2, soma, saida;
    long int i, candidato, max;
    int j;
    
    scanf("%d", &n);
    n2 = n/2;
    saida = 0;
    max = 1;
    for(i = 0; i < n; i++)
        max *= 10;
    for(i = 0; i < max; i++){
        candidato = i;
        soma = 0;
        for(j = 1; j <= n2; j++){
            soma += candidato%10;
            candidato /= 10;
        }
        for(j = n2; j <=n; j++){
            soma -= candidato%10;
            candidato /= 10;
        }
        if(!soma)
            saida++;
    }
    
    printf("%d\n", saida);
    
    return 0;
}
    
