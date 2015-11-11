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

#define TESTE_NIVEL_1 1
#define MAX 4000
#define EPSILON 1e-9 
using namespace std;

/*Classe ponto*/
struct Ponto{
    double x = 0, y = 0;
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

/*Globais*/
Ponto pontos[MAX];
vector <bool> used(MAX + 1);
int n;

/*esquerda*/
bool esquerda(const Ponto& p1, const Ponto& p2, const Ponto pAvaliado){
    double det = (p1.x*p2.y + p1.y*pAvaliado.x + p2.x*pAvaliado.y) -
                 (p1.x*pAvaliado.y + p1.y*p2.x + p2.y*pAvaliado.x);
    /***/
    if(TESTE_NIVEL_1){
        cout << "ESQUERDA: Entrou com postos p1 = (" << p1.x << ","
            << p1.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << pAvaliado.x << "," << pAvaliado.y << ")" << endl;
    }
    /***/
   return det > 0; 
          
}

bool lessP(const Ponto& p1, const Ponto& p2, const Ponto& p3){
    double det = (p1.x*p2.y + p1.y*p3.x + p2.x*p3.y) -
                 (p1.x*p3.y + p1.y*p2.x + p2.y*p3.x);
    /***/
    if(TESTE_NIVEL_1){
        cout << "LESSP: Entrou com postos p1 = (" << p1.x << ","
            << p1.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << p3.x << "," << p3.y << ")" << " e Vai retornar "
            << det << endl;
    }
    /***/
    if(det == 0){
        if(p1.x == p2.x)
            return p2.y < p3.y;
        else if( ((p1.y - p2.y)/(p1.x - p2.x)) < -1 )
            return p2.x < p3.x;
    }
    return det > 0;
}

bool colinear(const Ponto& p1, const Ponto& p2, const Ponto& p3){
    double det = (p1.x*p2.y + p1.y*p3.x + p2.x*p3.y) -
                 (p1.x*p3.y + p1.y*p2.x + p2.y*p3.x);
    /***/
    if(TESTE_NIVEL_1){
        cout << "COLINEAR: Entrou com postos p1 = (" << p1.x << ","
            << p1.y << ") , (" << p2.x << "," << p2.y << ") , ("
            << p3.x << "," << p3.y << ")" << " e Vai retornar "
            << det << endl;
    }
    /***/
    return det == 0;
}

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
            if(TESTE_NIVEL_1){
                for(auto a : pilha){
                    cout << "ACHAFECHO - PILHA: (" << pontos[a].x 
                         << "," << pontos[a].y << ")" << endl;
                }
            }
            /***/

            if(pilha.size() > 2){
                vector<int>::size_type size = pilha.size();
                for(unsigned i = 0; i < size; i++){
                    for(unsigned j = i + 1; j < size; j++){
                       for(unsigned k = j + 1; k < size; k++){
                           if(!colinear(pontos[pilha[i]],
                                      pontos[pilha[j]],
                                     pontos[pilha[k]])){
                                  return true;
                          }
                       }
                    }
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
    if(TESTE_NIVEL_1){
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
    if(TESTE_NIVEL_1){
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

/***main***/
int main(){
    int minIndex;
    double x, y;
    Ponto aux;
    Ponto temp[MAX];
    int achados, count;

    /*Entrada*/
    cin >> n;
    minIndex = 0;
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
        /***/
        if(TESTE_NIVEL_1){
            cout << "DEPOIS DE REORDENAR" << endl;
            for(int i = 0; i < n; i++){
                cout << "MAIN (PONTOS): " << i << " = ("
                     << pontos[i].x << "," << pontos[i].y
                     << ")" << endl;
            }
        }
        /***/
    }

    /*Saida*/
    cout << achados << endl;


    return 0;
}
