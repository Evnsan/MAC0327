/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/********Dividing an Island*********/
/***********************************/
/***********Problema 2**************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0
#define INF 20001
#define EPSILON 1e-10
using namespace std;

/*Classe Ponto*/
struct Ponto{
    double x;
    double y;
    /*metodos*/
    int set(double x, double y){
        this->x = x;
        this->y = y;
        return 0;
    }
    double len(Ponto& p1){
        return sqrt(pow(this->x - p1.x, 2.0) + pow(this->y - p1.y, 2.0));
    }
    /*sobrecarregando operadores*/
    struct Ponto& operator -= (const Ponto& p){
        x -= p.x;
        y -= p.y;
        return *this;
    }
    struct Ponto& operator += (const Ponto& p){
        x += p.x;
        y += p.y;
        return *this;
    }
};

/*algusn sugars*/
Ponto operator + (Ponto p1, const Ponto& p2){
    return p1 += p2;
}
Ponto operator - (Ponto p1, const Ponto& p2){
    return p1 -= p2;
}
/*Final da Classe ponto*/


/*Globais*/
Ponto p, q;

/*Acha pontos*/
bool achaPonto(Ponto a, Ponto b, Ponto c){
    double ab, ac, bc;
    double perimetro, semiperimetro;
    double delta;
    double xl, xll;
    Ponto difBA, difCA;

    ab = a.len(b);
    ac = a.len(c);
    bc = b.len(c);
    perimetro = ab + ac + bc;
    semiperimetro = perimetro / 2;

    /***/
    if(TESTE_NIVEL_1){
        cout << "ACHAPONTO: A = (" << a.x << "," << a.y << ")" << endl;
        cout << "ACHAPONTO: B = (" << b.x << "," << b.y << ")" << endl;
        cout << "ACHAPONTO: C = (" << c.x << "," << c.y << ")" << endl;
        cout << "ACHAPONTO: AB = " << ab << endl;
        cout << "ACHAPONTO: AC = " << ac << endl;
        cout << "ACHAPONTO: BC = " << bc << endl;
        cout << "ACHAPONTO: PERIMETRO = " << perimetro << endl;
        cout << "ACHAPONTO: SEMIPERIMETRO = " << semiperimetro << endl;
    }
    /***/
    /*Temos entao: x^2 - semiperimetro*x + ab*ac/2 = 0;*/

    delta = semiperimetro*semiperimetro - 2*ab*ac;
    xl = (semiperimetro + sqrt(delta)) / 2;
    xll = (semiperimetro - sqrt(delta)) / 2;

    /***/
    if(TESTE_NIVEL_1){
        cout << "ACHAPONTO: DELTA = " << delta << endl;
        cout << "ACHAPONTO: XL = " << xl << endl;
        cout << "ACHAPONTO: XLL = " << xll << endl;
    }
    /***/

    if(xll > 0){
        if(((xl - ab > EPSILON) && (xl - ac > EPSILON)) ||
           ((xll - ab > EPSILON) && (xll - ac > EPSILON)) ){
            return false;
        }
        if((xl - ab > EPSILON) || (xll - ac > EPSILON)){
            swap(xl, xll);
        }
        difBA = b - a;
        p.x = a.x + (xl/ab)*difBA.x;
        p.y = a.y + (xl/ab)*difBA.y;

        difCA = c - a;
        q.x = a.x + (xll/ac)*difCA.x;
        q.y = a.y + (xll/ac)*difCA.y;
        
        /***/
        if(TESTE_NIVEL_1){
            cout << "ACHAPONTO: difBA = (" << difBA.x << "," << difBA.y
                 << ")" << endl;
            cout << "ACHAPONTO: difCA = (" << difCA.x << "," << difCA.y
                 << ")" << endl;
        }
        /***/


        return true;
    }
    return false;
}

/***main***/
int main(){
    Ponto a, b, c;
    double x, y;
    pair<Ponto, Ponto> resposta;

    /*Inicializando*/


    /*Entrada*/
    cin >> x >> y;
    a.x = x;
    a.y = y;
    cin >> x >> y;
    b.x = x;
    b.y = y;
    cin >> x >> y;
    c.x = x;
    c.y = y;

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN: A = (" << a.x << "," << a.y << ")" << endl;
        cout << "MAIN: B = (" << b.x << "," << b.y << ")" << endl;
        cout << "MAIN: C = (" << c.x << "," << c.y << ")" << endl;
    }
    /***/

    /*Processamento*/
    cout << setprecision(15);
   
    if(!achaPonto(a, b, c)){
        if(!achaPonto(b,c,a)){
            if(!achaPonto(c,b,a)){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    /*Saida*/ 
    printf("YES\n%.15lf %.15lf\n%.15lf %.15lf\n", p.x, p.y, q.x, q.y);
/*
    cout << "YES" << endl;
    cout << resposta.first.x << " " << resposta.first.y << endl;
    cout << resposta.second.x << " " << resposta.second.y << endl;
*/    
    return 0;
}
