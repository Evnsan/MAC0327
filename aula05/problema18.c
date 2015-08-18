#include <stdio.h>

#define MAX 100000
#define INF 60000

int main(){
    int n;
    long int entrada[MAX][2], saida;
    long int valor, key;
    int dia, mes, hora, min;
    char lixo;
    /*controle*/
    int i;
    
    /*inicializacao*/
    scanf("%d", &n);
    
    saida = 0;
    for(i = 0; i < n; i++){
        scanf("%ld", valor);
        scanf("%c", &lixo);
        scanf("%d", &dia);
        scanf("%c", &lixo);
        scanf("%d", &mes);
        scanf("%c", &lixo);
        scanf("%d", &hora);
        scanf("%c", &lixo);
        scanf("%d", &min);
        scanf("%c", &lixo);
        key = min + 100*hora + 10000*dia + 1000000*mes;
        j = 0;
        while(entrada[j][0] < valor && j < i)
            j++;
    }
    /*Processamento*/
    /*sort*/
    qsort(entrada, MAX, sizeof(long int**), compara);
 
    /*saida*/
    
    return 0;
}
