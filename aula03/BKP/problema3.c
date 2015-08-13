#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TESTE 0

int main(){

    char buffer[100];
    
    int numeros[100][100], saida[102];
    /*maior soma de 100 numeros de 100 digitos tem 102 casas*/
    int soma, linhas, lidos;
    /*controle*/
    int i, j;
    
    /*inicializar matriz numeros com 0's*/
    for(i = 0 ; i < 100; i++)
        for(j = 0; j < 100; j++)
            numeros[i][j] = 0;
    
    /*entrada de dados*/    
    linhas = 0;
    fgets(buffer, sizeof(buffer), stdin);
    while(strcmp(buffer, "0\n")){
        lidos = strlen(buffer) - 1; /*(-1 -> /n)*/
        for( i = 0; i < lidos; i++){
            numeros[linhas][99 - i] = buffer[lidos - i - 1] - '0';
            /*(-1 -> length)*/
        }
        linhas++;
        fgets(buffer, sizeof(buffer), stdin);
    }
    if(TESTE){
        printf("%d\n", linhas);
        for(i = 0; i < linhas; i++){
            for(j = 0; j < 100; j ++)
                printf("%d", numeros[i][j]);
            printf("\n");
        }
    }
    
    /*processamento*/
    soma = 0;
    for(i = 99; i >= 0; i--){
        for(j = 0; j < linhas; j++)
            soma += numeros[j][i];
        saida[i+2] = soma % 10;
        soma /= 10;
    }
    for( i = 2; i >=0; i--){
        saida[i] = soma % 10;
        soma /= 10;
    }
    
    
    if(TESTE){
        for(i = 0; i < 102; i++)
            printf("%d", saida[i]);
        printf("\n");
    }
    
    
    /*saida*/
    i = 0;
    while(saida[i] == 0) i++;
    if(i < 102)
        for(; i < 102; i++)
            printf("%d", saida[i]);
    else
        printf("0");
    printf("\n");
    
    return 0;
}
