/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 31*************/
/***********************************/

#include<stdio.h>

#define TESTE 0

int calculaM(int total, int escolhidos);

int main(){
    int n;
    int saida;

    /*controle*/
    int i;

    /*Entrada*/
    scanf("%d", &n);
    
    /*Processamento*/
    saida = 0;
    if(n > 0){
        /*computando metade das bandeiras. i.e. começando com branco*/
        saida = 1; /*i = 0*/
        for(i = 1; i <= n / 2; i++)
            saida += calculaM(n - (1+i), i);
        /*calculando total*/
        saida *= 2;
    }

    /*Saida*/
    printf("%d\n", saida);

    return 0;
}

int calculaM(int total, int escolhidos){
    int dividendo, divisor;
    int i;

    dividendo = 1;
    for(i = total; i >  total - escolhidos; i--){
        dividendo *= i;
    }
    divisor = 1;
    for(i = 1; i <= escolhidos; i++){
        divisor *= i;
    }
    /***/
    if(TESTE){
        printf("Chamada com total = %d, escolhidos = %d e retorno = %d\n",
                total, escolhidos, dividendo / divisor);
    }
    /***/

    return dividendo / divisor;
}
