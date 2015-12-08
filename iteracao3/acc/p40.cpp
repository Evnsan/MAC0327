/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Greg and Array**********/
/***********************************/
/*************Problema 40***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAX 100000

using namespace std;

int incrementa(long int esq, long int dir, long long int valor,
               long long int dif[MAX], long int tamDif){
    /*inicio*/
    if(esq != 0){
        dif[esq - 1] += valor;
    }
    /*final*/
    if(dir == tamDif - 1){
        dif[dir] += valor;
    }
    else{
        dif[dir] -= valor;
    }
    return 0;
}




/*main*/
int main(){
    long int n, m, k;
    long long int dif[MAX];
    long long int difOp[MAX];
    long long int saida[MAX];
    long long int op[MAX][3];
    long int qryEsq, qryDir;
    long long int tmp;

    /*Entrada*/
    cin >> n >> m >> k;
    
    /*vetor*/
    cin >> dif[0];
    for(long int i = 1; i < n; i++){
        cin >> dif[i];
        dif[i - 1] = dif[i] - dif[i - 1];
    }
    /*operacoes*/
    for(long int i = 0; i < m; i++){
        cin >> op[i][0] >> op[i][1] >> op[i][2];
        op[i][0] -= 1;
        op[i][1] -= 1;
        difOp[i] = 0;
    }
    
    /*requisicoes*/
    for(long int i = 0; i < k; i++){
        cin >> qryEsq >> qryDir;
        incrementa(qryEsq - 1, qryDir - 1, 1, difOp, m);
    }
    
    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : dif" << endl;
        for(long int i = 0; i < n; i++){
            cout << dif[i] << " ";
        }
        cout << endl;
        cout << "MAIN : difOp" << endl;
        for(long int i = 0; i < m; i++){
            cout << difOp[i] << " ";
        }
        cout << endl;
    }
    /***/
    
    /*Processamento*/
    tmp = difOp[m - 1];
    op[m - 1][2] *= tmp;
    for(long int i = m - 2; i >= 0; i--){
        tmp = tmp - difOp[i];
        op[i][2] *= tmp;
    }

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN : op" << endl;
        for(long int i = 0; i < m; i++){
            cout << "(" << op[i][0] << "->" << op[i][1] 
                 << "," << op[i][2] << ") ";
        }
        cout << endl;
    }
    /***/

    for(long int i = 0; i < m; i++){
        incrementa(op[i][0], op[i][1], op[i][2], dif, n);
    }
    
    tmp = dif[n - 1];
    saida[n - 1] = tmp;
    for(long int i = n - 2; i >= 0; i--){
        tmp = tmp - dif[i];
        saida[i] = tmp;
    }

    /*Saida*/
    for(long int i = 0; i < n; i++){
        cout << saida[i] << " ";
    }
    cout << endl;
    return 0;
}
