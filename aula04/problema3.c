#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

typedef struct celula *link;

struct celula {
            long int inicio;
            long int final;
            long int tamanho;
            char cor;
            link prox;
        } strcelula;



int main()
{
    int n;
    long int inicio, final;
    char cor;
    link saida, eixo, pool, tmp, anterior, posterior;
    /*controle*/
    int i;

    /*Inicializacao*/

    scanf("%d", &n);

    /*lista ligada com cabeca pool e eixo*/
    /*cabeca*/
    tmp = (link)malloc(sizeof(*tmp));
    tmp->inicio = tmp->final = tmp->tamanho = 0;
    tmp->prox = NULL;
    eixo = tmp;
    
    tmp = malloc(sizeof(*tmp));
    tmp->inicio = tmp->final = tmp->tamanho = 0;
    tmp->prox = NULL;
    pool = tmp;
    
    /* alocando numero maximo de faixas(2*n) na pull*/
    for( i = 0; i < 2*n; i++){
        tmp = malloc( sizeof(*tmp) );
        tmp->inicio = tmp->final = tmp->tamanho = 0;
        tmp->prox = pool;
        pool = tmp;
    }
    /*alocando primeira faixa branca*/
    tmp = malloc(sizeof(*tmp));
    tmp->inicio = 0;
    tmp->final = MAX;
    tmp->prox = eixo;
    eixo = tmp;
        
    for(i = 0; i < n; i++){
        scanf("%ld", &inicio);
        scanf("%ld", &final);
        scanf("%c", &cor);
    
        /*montar lista ordenada*/
        tmp = eixo;
        while( tmp != NULL && tmp->final < inicio ){
            tmp = tmp->prox;
            }
        anterior = tmp;
        while( tmp != NULL && tmp->inicio > final )
            tmp = tmp->prox;
        posterior = tmp;
        if( anterior == posterior ){
            /*criar duas*/
        }
        else{
            /*retirar faixas que sobram*/
            tmp = anterior->prox;
            while(tmp != posterior){
                /*devolver tmp*/
            }
            anterior->tamanho = inicio - anterior->final;
            anterior->final = inicio;
            posterior->tamanho = final - posterior->inicio;
            posterior->inicio = final;
            tmp = pool;
            pool = pool->prox;
            tmp->inicio = inicio;
            tmp->final = final;
            tmp->tamanho = final - inicio;
            anterior->prox = tmp;
            tmp->prox = posterior;
        }      
    }
  

    /*Processamento*/
    tmp = eixo->prox;
    
    while(tmp != NULL && tmp->cor != 'w'){
        tmp = tmp->prox;
    }
    if(tmp == NULL){
        printf("0 0\n");
        return 0;
    }
    saida = tmp;
    tmp = tmp->prox;
    
    while(tmp != NULL){
        if(tmp->cor == 'w')
            if(saida->tamanho < tmp->tamanho)
                saida = tmp;
        tmp =tmp->prox;
    }
    
    /*Saida*/
    printf("%ld %ld\n", saida->inicio, saida->final);
    
    return 0;
}
    
