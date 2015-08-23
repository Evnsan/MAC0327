/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********NUSP  5388861************/
/***********************************/
/***********Problema 04*************/
/***********************************/

#include<stdio.h>

#define MAX 100001
#define TESTE 1
#define JOG1 0
#define JOG2 1

long int buscabin(int *vetor, long int esq, long int dir, long int key);


int main(){
    long int n;
    int entrada[MAX], acumulado[2][MAX], vencedor;
    long int saida[MAX][2];
    char c;
    long int pontosMax, setsJogador1, setsJogador2, procura;
    long int fimSetAnterior;
    long int indice[2];
    long int npossibilidades;

    /*controle*/
    long int i;

    /*Entrada*/
    scanf("%ld", &n);

    /*
    while(scanf("%c", &c) && c == '\n');
    entrada[0] = c - '0';
    if(entrada[0] == 1){
        acumulado[JOG1][0] = 1;
        acumulado[JOG2][0] = 0;
    }
    else{
        acumulado[JOG1][0] = 0;
        acumulado[JOG2][0] = 1;
    }
    */
    acumulado[JOG1][0] = 0;
    acumulado[JOG2][0] = 0;
    n++;


    for(i = 1; i < n; i++){
        while(scanf("%c", &c) && c == '\n');
        entrada[i] = c - '0';
        if(entrada[i] == 1){
            acumulado[JOG1][i] = acumulado[JOG1][i-1] + 1;
            acumulado[JOG2][i] = acumulado[JOG2][i-1];
        }
        else{
            acumulado[JOG1][i] = acumulado[JOG1][i-1];
            acumulado[JOG2][i] = acumulado[JOG2][i-1] + 1;
        }
    }

    if(entrada[n-1] == 1){
        vencedor = JOG1;
        pontosMax = acumulado[JOG1][n - 1];
    }
    else{
        vencedor = JOG2;
        pontosMax = acumulado[JOG2][n - 1];
    }

    /***/
    if(TESTE){
        for(i = 0; i < n; i++){
            printf("%d",entrada[i]);
        }
        printf("\n");
        for(i = 0; i < n; i++){
            printf("%d",acumulado[JOG1][i]);
        }
        printf("\n");
        for(i = 0; i < n; i++){
            printf("%d",acumulado[JOG2][i]);
        }
        printf("\n");
    }
    /***/


    /*Processamento*/
    npossibilidades = 0;
    for(i = pontosMax; i > 0; i--){
       /*verifica se jogo de i pontos e valido*/
        setsJogador1 = 0;
        setsJogador2 = 0;
        fimSetAnterior = 0;
        while(fimSetAnterior < n - 1){
            procura = acumulado[JOG1][fimSetAnterior] + i;
            indice[JOG1] = buscabin(acumulado[JOG1],fimSetAnterior, n-1, procura);
            procura = acumulado[JOG2][fimSetAnterior] + i;
            indice[JOG2] = buscabin(acumulado[JOG2],fimSetAnterior, n-1, procura);
            if(indice[JOG1] < indice[JOG2]){
                fimSetAnterior = indice[JOG1];
                setsJogador1++;
            }
            else{
                fimSetAnterior = indice[JOG2];
                setsJogador2++;
            }
        }
        if(fimSetAnterior < MAX){
            if(setsJogador1 > setsJogador2 && vencedor == JOG1){
                saida[npossibilidades][0] = setsJogador1;
                saida[npossibilidades][1] = i;
                npossibilidades++;
            }
            else if(setsJogador1 < setsJogador2 && vencedor == JOG2){
                saida[npossibilidades][0] = setsJogador2;
                saida[npossibilidades][1] = i;
                npossibilidades++;
            }
        }
    }


    /*Saida*/
    printf("%ld\n", npossibilidades);
    for( i = 0; i < npossibilidades; i++){
        printf("%ld %ld\n", saida[i][0], saida[i][1]);
    }
    /*retorna jogos validos em ordem crescente [sets] [points]*/

    return 0;
}

long int buscabin(int *vetor, long int esq, long int dir, long int key){
    
    if(TESTE){
        long int i;
        printf("Dentro do buscabin:\n");
        printf("Procurando key = %ld, de %ld a %ld\n", key, esq, dir);
        for(i = esq; i <= dir; i++){
           printf("%d ", vetor[i]);
        }
        printf("\n");
        /*return MAX;<=====================*/
    }
    if(dir < esq)
        return MAX;
    else{
        long int meio = (dir - esq)/2;
        
        if(vetor[meio] > key)
            return buscabin(vetor, esq, meio - 1, key);
        else if(vetor[meio] < key)
            return buscabin(vetor, meio + 1, dir, key);
        else
            return meio;
    }
}
