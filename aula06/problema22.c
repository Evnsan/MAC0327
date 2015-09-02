/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 22*************/
/***********************************/

/*Implementacao de     arvore binaria de busca */
/*Codigo baseado no codigo apresentado no livro*/
/*  "Introduction to Algorithms" - Cormen,     */
/*  Leiserson, Rivest e Stein                  */
/***********************************************/
#include<stdlib.h>
#include<stdio.h>

#define MAX 250000
#define TESTE_NIVEL_1 0
#define TESTE_NIVEL_2 0



/*dados satelites*/
typedef long int Item;

/*estrutura do heap*/
    /*vetor de Itens*/

/*variaveis globais para heap*/
Item heap[MAX/2 + 2];
long int tamanho = 0;

/*remove max*/
long int removeMax(){
    long int retorno;
    long int preencher;
    tamanho--;
    retorno = heap[0];
    preencher = 0;
    while( preencher * 2 + 2 <= tamanho ){
        if(heap[preencher * 2 + 1] > heap[preencher * 2 + 2]){ 
            if( heap[preencher * 2 + 1] > heap[tamanho]){
                heap[preencher] = heap[preencher * 2 + 1];
                preencher = preencher * 2 + 1;
            }
            else{
                heap[preencher] = heap[tamanho];
                preencher = tamanho;
            }

        }
        else{
            if( heap[preencher * 2 + 2] > heap[tamanho]){
                heap[preencher] = heap[preencher * 2 + 2];
                preencher = preencher * 2 + 2;
            }
            else{
                heap[preencher] = heap[tamanho];
                preencher = tamanho;
            }
        }
    }
    heap[preencher] = heap[tamanho];
    
    return retorno;
}

/*insere*/
int insereItem(Item z){
    long int f = tamanho;
    long int t;
    heap[f] = z;
    while(f > 0 && heap[f/2] < heap[f]){
        t = heap[f/2];
        heap[f/2] = heap[f];
        heap[f] = t;
        f /= 2;
    }
    tamanho++;
    return 0;
}

/**********************************/
/*programa principal*/
int main(){
    
    long int n;
    Item entrada;
    float x, y;
    Item p;

    /*controle*/
    long int i, j;

    /*entrada*/
    scanf("%ld", &n);

    for(i = 0; i < n; i++){
        scanf("%ld", &entrada);
        insereItem(entrada);
        /***/
        if(TESTE_NIVEL_1){
            printf("Heap:\n");
            for(j = 0; j < tamanho; j++)
                printf("%ld ", heap[j]);
            printf("\n n = %ld, i = %ld, tamanho = %ld\n", n, i, tamanho);
        } 
        /***/
        if(i > n/2){
            p = removeMax();
            /***/
            if(TESTE_NIVEL_1){
                printf("Heap:\n");
                for(j = 0; j < tamanho; j++)
                    printf("%ld ", heap[j]);
                printf("\n n = %ld, i = %ld, tamanho = %ld\n", 
                        n, i, tamanho);
                printf("maximo (%ld)\n", p);
            }
            /***/
        }
    
    }
    /***/
    if(TESTE_NIVEL_1){
        printf("Heap:\n");
        for(i = 0; i < tamanho; i++)
            printf("%ld ", heap[i]);
        printf("\n");
    } 
    /***/

    if(n % 2 != 0)
        printf("%ld.0\n", heap[0]);
    else{
        x = (float)heap[0];
        y = (float)(heap[1]>heap[2]?heap[1]:heap[2]);
        x /= 2;
        y /= 2;
        printf("%.1f\n", x + y);
    } 

    return 0;
}
