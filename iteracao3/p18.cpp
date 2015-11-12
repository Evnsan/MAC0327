/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**********Military Story***********/
/***********************************/
/***********Problema 18*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define TESTE_NIVEL_2 0
#define MAX 4000
#define EPSILON 1e-15 
using namespace std;

/********************************Classe Ponto*********************************/
struct Ponto{
    int x = 0, y = 0;

    struct Ponto& operator = (const pair<int, int>& p){
        x = p.first;
        y = p.second;
        return *this;
    }
    struct Ponto& operator = (const Ponto& p){
        x = p.x;
        y = p.y;
        return *this;
    }
};
/*****************************************************************************/

/*****************************Variaveis Globais*******************************/
Ponto pontos[MAX];
vector <bool> used(MAX + 1);
int n;
/*****************************************************************************/

/********************************Auxiliares***********************************/
/*calcDet*/
double calcDet(const Ponto& p1, const Ponto& p2, const Ponto p3){
    double det = 1.0*(p1.x*p2.y + p1.y*p3.x + p2.x*p3.y) -
                 (p1.x*p3.y + p1.y*p2.x + p2.y*p3.x);
    return det;
}

/*esquerda*/
bool esquerda(const Ponto& p1, const Ponto& p2, const Ponto pAvaliado){
    double det = calcDet(p1, p2, pAvaliado);
    /***/
    if(TESTE_NIVEL_2){
        cout << "ESQUERDA: Entrou com pontos p1 = (" << p1.x << ","
            << p1.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << pAvaliado.x << "," << pAvaliado.y << ")" << endl;
        cout << "ESQUERDA: recebeu det = " << det << " e -EPSILON = "
             << -EPSILON << " comparacao com epsilon " << (det > EPSILON)
             << endl;
    }
    /***/
   return det > EPSILON; 
          
}

bool lessP(const Ponto& pReferencia, const Ponto& p2, const Ponto& p3){
    double det = calcDet(pReferencia, p2, p3);
    /***/
    if(TESTE_NIVEL_2){
        cout << "LESSP: Entrou com pontos p1 = (" << pReferencia.x << ","
            << pReferencia.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << p3.x << "," << p3.y << ")" << " e Vai retornar "
            << det << endl;
    }
    /***/
    if(det == 0){
        if(pReferencia.x == p2.x)
            return p2.y < p3.y;
        else
            return p2.x < p3.x;

    }
    return det > EPSILON;
}

bool colinear(const Ponto& p1, const Ponto& p2, const Ponto& p3){
    double det = calcDet(p1, p2, p3);
    /***/
    if(TESTE_NIVEL_2){
        cout << "COLINEAR: Entrou com pontos p1 = (" << p1.x << ","
            << p1.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << p3.x << "," << p3.y << ")" << " e Vai retornar "
            << det << endl;
    }
    /***/
    return (det > -EPSILON && det < EPSILON);
}

bool concertaOrdem(){
    Ponto temp[MAX];
    int inicio;
    int fim;
    
    if(pontos[0].x < pontos[n-1].x){
        inicio = n-2;
        while(colinear(pontos[0], pontos[n-1], pontos[inicio])){
            inicio--;
        }
        inicio++;
        for(int i = inicio; i < n; i++){
            temp[i] = pontos[i];
        }
        for(int i = inicio; i < n; i++){
            pontos[i] = temp[n + inicio - i - 1];
        }
    }
    else if(pontos[0].x > pontos[1].x){
        fim = 2;
        while(colinear(pontos[0], pontos[1], pontos[fim])){
            fim++;
        }
        for(int i = 1; i < fim; i++){
            temp[i] = pontos[i];
        }
        for(int i = 1; i < fim; i++){
            pontos[i] = temp[fim - i];
        }
    }
    return 0;
}

/*****************************************************************************/

/**********************************Graham*************************************/
/*achaFechoConvexo*/

int proximoIndice(int atual){
    int prox = atual + 1;
    while(used[prox]){
        prox++;
    }
    if(prox < n)
        return prox;
    else
        return -1;
}

bool achaFechoConvexo(){
    vector<int> pilha;
    int atual;
    atual = 0;
    if(!used[0] || (atual = proximoIndice(0)) != -1){
        pilha.push_back(atual);
        used[atual] = true;
        if((atual = proximoIndice(atual)) != -1){
            pilha.push_back(atual);
            used[atual] = true;
            while((atual = proximoIndice(atual)) != -1){
                while( pilha.size() >= 2 &&
                       esquerda(
                         pontos[pilha.back()],
                         pontos[pilha[pilha.size() - 2]],
                         pontos[atual])
                     ){
                    used[pilha.back()] = false;
                    pilha.pop_back();
                }
                pilha.push_back(atual);
                used[atual] = true;
            }
            /***/
            if(TESTE_NIVEL_2){
                for(auto a : pilha){
                    cout << "ACHAFECHO - PILHA: (" << pontos[a].x 
                         << "," << pontos[a].y << ")" << endl;
                }
            }
            /***/

            if(pilha.size() > 2){
                /*Podemos avaliar se os pontos formam um poligono, nao sao
                  colineares, olhando apenas para o primeiro e o ultimo pontos
                  pois escolhemos como ponto de referencia(ponto[0]) o ponto
                  com menor y, desempatando pelo maior x*/ 
                if(!colinear(pontos[pilha[0]],
                             pontos[pilha[1]],
                             pontos[pilha[pilha.size() - 1]])){
                    return true;
                }
            }
        }
    }

    return false;
}

/*MergeSortG*/
int intercalaG(int l, int m, int r){
    Ponto aux[MAX];
    int p, q;
    /***/
    if(TESTE_NIVEL_2){
        cout << "INTERCALA: entrou com l= " << l
             << " m= " << m << " e r = " << r << endl;
    }
    /***/
    for(int i = l; i <= r; i++){
        aux[i] = pontos[i];
    }
    p = l;
    q = m + 1;
    for(int i = l; i <= r; i++){
        if(p > m){
            pontos[i] = aux[q];
            q++;
        }
        else if(q > r || lessP(pontos[0], aux[p] ,aux[q])){
            pontos[i] = aux[p];
            p++;
        }
        else{
            pontos[i] = aux[q];
            q++;
        }
    }
    return 0;
}

int mergeSortG(int l, int r){
    int m = (l + r)/2;
    /***/
    if(TESTE_NIVEL_2){
        cout << "MERGESORTG: entrou com l= " << l
             << " e r = " << r << endl;
    }
    /***/
    if(l < r){
        mergeSortG(l, m);
        mergeSortG(m + 1,r);
        intercalaG(l,m,r);
    }
    return 0;
}
/*****************************************************************************/



/***main***/
int main(){
    int minIndex;
    int x, y;
    Ponto aux;
    Ponto temp[MAX];
    int achados, count;
    int inicio;

    /*Entrada*/
    cin >> n;
    minIndex = 0;
    /*Preprocessamento*/
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        pontos[i] = make_pair(x,y);
        if( y < pontos[minIndex].y ||
            (y == pontos[minIndex].y && x > pontos[minIndex].x)
          )
            minIndex = i;
        used[i] = false;
    }
    used[n] = false;
    /***/
    if(TESTE_NIVEL_1){
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ")" << endl;
        }
        cout << "MAIN: MININDEX = " << minIndex << endl;
    }
    /***/
    aux = pontos[0];
    pontos[0] = pontos[minIndex];
    pontos[minIndex] = aux;

    /*sort*/
    mergeSortG(1, n - 1);
    /***/
    if(TESTE_NIVEL_1){
        cout << "PARCIALMENTE ORDENADO" << endl;
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ")" << endl;
        }
    }
    /***/
    concertaOrdem(); 
    /***/
    if(TESTE_NIVEL_1){
        cout << "DEPOIS DE ORDENADO" << endl;
        for(int i = 0; i < n; i++){
            cout << "MAIN (PONTOS): " << i << " = ("
                 << pontos[i].x << "," << pontos[i].y
                 << ")" << endl;
        }
    }
    /***/
    achados = 0;
    while(achaFechoConvexo()){
        achados++;
        count = 0;
        for(int i = 0; i < n; i++){
            if(!used[i]){
                temp[count++] = pontos[i];
            }
            else{
                /***/
                if(TESTE_NIVEL_1){
                    cout << " Retirando ponto (" << pontos[i].x
                         << "," << pontos[i].y << ")" << endl;
                }
                /***/
            }
        }
        /***/
        if(TESTE_NIVEL_1){
            cout << "achou um poligono => total = " << achados << endl;
            cout << "______________________________________________" << endl;
        }
        /***/
        minIndex = 0;
        for(int i = 0; i < count; i++){
            pontos[i] = temp[i];
            used[i] = false;
            if( y < pontos[minIndex].y ||
                (y == pontos[minIndex].y && x > pontos[minIndex].x)
            )
                minIndex = i;
            
        }
        aux = pontos[0];
        pontos[0] = pontos[minIndex];
        pontos[minIndex] = aux;

        n = count;
        used[n] = false;
        mergeSortG(1, n - 1);
        concertaOrdem();
        /***/
        if(TESTE_NIVEL_1){
            if(n > 0){
                cout << "DEPOIS DE REORDENAR" << endl;
                for(int i = 0; i < n; i++){
                    cout << "MAIN (PONTOS): " << i << " = ("
                         << pontos[i].x << "," << pontos[i].y
                         << ")" << endl;
                }
            }
        }
        /***/
    }

    /*Saida*/
    cout << achados << endl;

    return 0;
}
