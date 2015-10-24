/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/**************JAMAICA**************/
/***********************************/
/*************Problema 01***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAXS 10000
#define MAXN 300


using namespace std;


typedef tuple<float, long int, bool> Reta;    /*("0",Xo, ypar)*/


/*****************/

/***GLOBAIS***/
map< Reta, double > rotas;     /*("0",Xo, ypar) -> r*/

/***main***/
int main(){
    int cid_n;                                  /*numero de cidades*/
    vector< pair<long int, long int> > cidades;
    pair<long int, long int> entrada;
    float tetha;
    double r;
    long int x0;
    bool ypar;                                  /*paralelo ao eixo y*/
    pair< long int, long int> p0, p1;
    Reta reta;
    double saida;


    cin >> cid_n;
    
    for(int i = 0; i < cid_n; i++){ 
        cin >> entrada.first >> entrada.second;
        cidades.push_back(entrada);
    }
    
    for(int i = 0; i < cid_n; i++){
        for(int j = i + 1; j< cid_n; j++){
            /*cout << "fazendo para: (" << cidades[i].first << "," 
                 <<  cidades[i].second << ") e ("
                 << cidades[j].first << "," 
                 << cidades[j].second<< ")" << endl;*/
            if(cidades[i].second <= cidades[j].second){
                p0 = cidades[i];
                p1 = cidades[j];
            }
            else{
                p0 = cidades[j];
                p1 = cidades[i];
            }
            if(p0.first == p1.first){
                /*cout << "entrou para: (" << cidades[i].first << "," 
                 <<  cidades[i].second << ") e ("
                 << cidades[j].first << "," 
                 << cidades[j].second<< ")" << endl;*/
                ypar = true;
                tetha = 0;
                x0 = p0.first;
            }
            else if(p0.second == p1.second){
                ypar = false;
                tetha = 0;
                x0 = p0.second;
            }
            else{
                ypar = false;
                tetha = (p1.second - p0.second)/(p1.first - p0.first);
                x0 = p0.first - p0.second/tetha;
            }
            r = sqrt(pow((p0.first - p1.first), 2.0)
                    + pow((p0.second - p1.second), 2.0) );
           reta = make_tuple(tetha, x0, ypar);
           if(!rotas.count(reta) || rotas[reta] < r){
               rotas[reta] = r;
           }
        }
    }
    
    /***/
    if(TESTE_NIVEL_1){
        for(auto a : cidades){
            cout << "CIDADES: (" << a.first << "," <<  a.second <<")"<<endl;
        }
        
        for(auto a : rotas){
            cout << "ROTAS: " << get<0>(a.first) << " " << get<1>(a.first)
                 << " " << get<2>(a.first) << " -> " << a.second << endl;
        }
    }
    /***/
    
    /*saida*/
    saida = 0;
    for(auto a : rotas){
        saida += a.second;
    }
    cout << saida << endl;
    return 0;
}
