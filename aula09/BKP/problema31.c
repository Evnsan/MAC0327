/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 31*************/
/***********************************/

#include<stdio.h>

int calculaM(int faixas);

int main(){
    int n;
    int saida;

    /*controle*/

    /*Entrada*/
    scanf("%d", &n);
    
    /*Processamento*/
    
    /*computando metade das bandeiras. i.e. começando com branco*/
    saida = calculaM(n-1);
    /*calculando total*/
    saida *= 2;

    /*Saida*/
    printf("%d\n", saida);

    return 0;
}

int calculaM(int faixas){
    int retorno;
    if(faixas > 0){
        /*adicionado uma faixa cor diferentei i.e. b| -v*/
        retorno = calculaM(faixas - 1); 
        if(faixas > 1)
            /*adicionando uma faixa azul + uma cor diferente i.e. b| -a-v*/
            retorno += calculaM(faixas - 2);
    }
    else
        retorno = 1;
    return retorno;
}
