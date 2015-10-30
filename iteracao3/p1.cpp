/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***************JAMAICA*************/
/***********************************/
/*************Problema 01***********/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define MAXS 10000
#define MAXN 300


using namespace std;


typedef tuple<double, double, bool> Reta;    /*("0",Xo, ypar)*/

/* "0"  -> tangente do menor angulo formado pela reta que passa pelos dois
  pontos e a reta paralela ao eixo x no ponto com menor oordenada.
  O valor é positivo se o angulo é percorrido no sentido horário, e énegativo
  c.c.*/
/* Xo   -> abscissa do ponto sobre o eixo x que pertence a reta. */
/* ypar -> /1 , se os pontos formam reta paralela ao eixo y
           \0 , caso contrario */

/*****************/

/***GLOBAIS***/
map< Reta, long int > rotas;     /*("0",Xo, ypar) -> r*/

/***main***/
int main(){
    int cid_n;                                  /*numero de cidades*/
    vector< pair<long int, long int> > cidades;
    pair<long int, long int> entrada;
    double tetha;
    long int r;
    double x0;
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
                /***/
                if(TESTE_NIVEL_1){
                    cout << "X==X reta " << (i*cid_n)+j << ": "
                         << tetha << " " << x0 << " " << ypar << endl;
                }
                /***/
            }
            else if(p0.second == p1.second){
                ypar = false;
                tetha = 0;
                x0 = p0.second;
                /***/
                if(TESTE_NIVEL_1){
                    cout << "Y==Y reta " << (i*cid_n)+j << ": "
                         << tetha << " " << x0 << " " << ypar << endl;
                }
                /***/
            }
            else{
                ypar = false;
                tetha = double((p1.second - p0.second))/
                    (p1.first - p0.first);
                /***/
                if(TESTE_NIVEL_1){
                    cout << "Calculo do theta: p0(" << p0.first
                         << "," << p0.second << ") p1(" << p1.first
                        << "," << p1.second << ")" << endl;
                }
                /***/
                x0 =(double)(p0.first - double(p0.second)/tetha);
                /***/
                if(TESTE_NIVEL_1){
                    cout << "P!=P reta " << (i*cid_n)+j << ": "
                         << tetha << " " << x0 << " " << ypar << endl;
                }
                /***/
            }
            r = (p0.first - p1.first)*(p0.first - p1.first)
                    + (p0.second - p1.second)*(p0.second - p1.second);
            /***/
            if(TESTE_NIVEL_1){
                cout << setprecision(9) << r << endl;
            }
            /***/
            reta = make_tuple(tetha, x0, ypar);
            /***/
            if(TESTE_NIVEL_1){
                cout << "RETA" << (i*cid_n)+j << ": " << get<0>(reta) << " "
                     << get<1>(reta) << " " << get<2>(reta) << "->" <<
                     r  << endl;
            }
            /***/
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
    /*
    cout << setprecision(9) << " saida: 0" << endl;
    */
    for(auto a : rotas){
        saida += double(sqrt(a.second));
        /*
        cout << "+ " << double(sqrt(a.second)) << " = " << saida << endl;
        */
    }
    /*cout << round(saida) << endl;*/
    printf("%.0lf\n",  floor(saida + .5));
    return 0;
}
