#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TESTE 0

int main(){

    char buffer[105]; /*100 digitos + \n*/
    
    int saida[102];
    /*maior soma de 100 numeros de 100 digitos tem 102 digitos*/
   
    int soma,lidos;
   
    /*controle*/
    int i;
    soma = 0;
    
    for(i = 0; i < 102; i++)
        saida[i] = 0;
  
    /*entrada de dados*/
    fgets(buffer, sizeof(buffer), stdin);
    while(strcmp(buffer, "0\n")){
        lidos = strlen(buffer) - 1;
        for( i = 0; i < lidos; i++){
            soma  += (buffer[lidos - i - 1] - '0') + saida[101 - i];
            /*(-2 -> length e \n)*/
            /*soma*/
            saida[101 - i] = soma % 10;
            soma /= 10;
        }
        while( soma != 0 ){
            soma += saida[101 - i];
            saida[101 - i] = soma % 10;
            soma /= 10;
            i++;
        }
        
        fgets(buffer, sizeof(buffer), stdin);
    }
    
    
    /*saida*/
    i = 0;
    while(i < 102 && saida[i] == 0){
        i++;
    }

    if(i < 102){
        for(; i < 102; i++)
            printf("%d", saida[i]);
    }
    else
        printf("0");
    printf("\n");
    
    return 0;
}
