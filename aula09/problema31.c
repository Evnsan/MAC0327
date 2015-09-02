/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 31*************/
/***********************************/

#include<stdio.h>

#define TESTE 0

unsigned long long calculaM(int total, int escolhidos);

int main(){
    int n;
    unsigned long long saida;

    /*controle*/
    int i;

    /*Entrada*/
    scanf("%d", &n);
    
    /*Processamento*/
    saida = 0;
    if(n > 0){
        /*computando metade das bandeiras. i.e. começando com branco*/
        saida = 1; /*i = 0*/
        if(n%2 == 0){
            for(i = 1; i < n / 2; i++)
            saida += calculaM(n - (1+i), i);
        }
        else{
            for(i = 1; i <= n / 2; i++)
            saida += calculaM(n - (1+i), i);
        }

        /*calculando total*/
        saida *= 2;
    }

    /*Saida*/
    printf("%llu\n", saida);

    return 0;
}

unsigned long long calculaM(int total, int escolhidos){
    unsigned long long dividendo, divisor;
    int i;

    if(escolhidos > total/2)
        escolhidos = total - escolhidos;

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
        printf("Chamada com total = %d, escolhidos = %d e retorno = %llu\n",
                total, escolhidos, dividendo / divisor);
    }
    /***/

    return dividendo / divisor;
}
