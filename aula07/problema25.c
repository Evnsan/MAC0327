/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 25*************/
/***********************************/

#include<stdio.h>

#define MAX 10000
#define NPRIMOS 1229
#define TESTE 0

int eprimo(int primos[], int achados, int candidato);

int main(){
    int n, magico;
    int primos[NPRIMOS], expoente[NPRIMOS];
    int candidato, achados;

    /*controle*/
    int i, j;

    /*preparando vetor de primos*/
    candidato = 3;
    primos[0] = 2;
    achados = 1;
    while( achados < NPRIMOS ){
        while(!eprimo(&primos[0], achados, candidato)){
            candidato++;
        }
        primos[achados] = candidato;
        achados++;
    }
    /***/
    if(TESTE && 0){
        printf("primos\n");
        for(i = 0; i < NPRIMOS; i++){
            printf("%d ", primos[i]);
        }
        printf("\n");
    }
    /***/
    /*preparando vetor de primos*/
    for(i = 0; i < NPRIMOS; i++){
        expoente[i] = 0;
    }
    /*Entrada*/
    for(i = 0; i < 10; i++){
        scanf("%d", &n);
        if( n > 0 && n <= 10000){
            for(j = NPRIMOS - 1; j >= 0; j--){
                while(!(n % primos[j])){
                    n /= primos[j];
                    expoente[j]++;
                }
            }
        }
    /***/
        if(TESTE){
            printf("Fatoracao de n:\n");
            for(j = 0; j < NPRIMOS; j++){
                if(expoente[j] != 0){
                    printf("%d => %d\n", primos[j], expoente[j]);
                }
            }
        }
    }


    /*Processamento*/
    magico = 1;
    for(i = 0; i < NPRIMOS; i++){
        if(expoente[i] > 0)
            magico *= (expoente[i] + 1);
    }
    /*Saida*/
    if(magico != 1)
        printf("%d\n", magico%10);
    else
        printf("1\n");

    return 0;
}

int eprimo(int primos[], int achados, int candidato){
    int i;

    for(i = 0; i < achados; i++){
        if(candidato%primos[i] == 0)
            return 0;
    }
    return 1;
}

