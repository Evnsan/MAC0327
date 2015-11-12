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
#define INF 2001
#define PI 3.141592653589793
#define EPSILON 1e-10
using namespace std;

/*Classe ponto*/
struct Ponto{
    double x = 0, y = 0;
    
    /*Metodos*/
    double norma(){
        return sqrt(pow(x, 2.0) + pow(y, 2.0));
    }
    double len(Ponto& p1){
        return sqrt(pow(x-p1.x,2.0) + pow(y-p1.y,2.0));
    }
    struct Ponto& rot(double graus){
        double radianos = graus*PI/180;
        double seno = sin(radianos);
        double cosseno = cos(radianos);
        double xant;

        if(seno <= EPSILON) seno = 0;
        if(cosseno <= EPSILON) cosseno = 0;
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.ROT: recebeu " << graus
                 << " e calculou seno=" << seno
                 << "; cosseno=" << cosseno << endl;
            cout << "PONTO.ROT: ponto antigo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        xant = x;
        x = cosseno*x - seno*y;
        y = seno*xant + cosseno*y;
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.ROT: ponto novo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        return *this;
    }

    struct Ponto& setIntensidade(double k){
        double norma = this->norma(); 
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.SETINTENSIDADE: recebeu " << k
                 << " e calculou norma=" << norma << endl;
            cout << "PONTO.SETINTENSIDADE: ponto antigo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        x = x/norma * k;
        y = y/norma * k;
        /***/
        if(TESTE_NIVEL_1){
            cout << "PONTO.SETINTENSIDADE: ponto novo ("
                 << x << "," << y << ")" << endl;
        }
        /***/
        return *this;
    }
    
    int lexcmp(const Ponto& p1){
        /*
        cout << "LEXLESS: chegou c1=(" << x << ","
             << y << ") e c2=(" << p1.x << ","
             << p1.y << ")" << endl;
        */
        if(x != p1.x){
            return x - p1.x;
        }
        else{
           return y - p1.y;
        }
    } 

    struct Ponto& operator+=(const Ponto& p1){
        x += p1.x;
        y += p1.y;
        return *this;
    }
    struct Ponto& operator+=(const double& k){
        x += k;
        y += k;
        return *this;
    }
    struct Ponto& operator-=(const Ponto& p1){
        x -= p1.x;
        y -= p1.y;
        return *this;
    }
    struct Ponto& operator-=(const double& k){
        x -= k;
        y -= k;
        return *this;
    }
    struct Ponto& operator = (const pair<int, int>& p){
        x = p.first;
        y = p.second;
        return *this;
    }
};

Ponto operator+(Ponto p1, const Ponto& p2){
    return p1 += p2;
}
Ponto operator+(Ponto p1, const double& k){
    return p1 += k;
}
Ponto operator+(const double k, Ponto p1){
    return p1 += k;
}
Ponto operator-(Ponto p1, const Ponto& p2){
    return p1 -= p2;
}
Ponto operator-(Ponto p1, const double& k){
    return p1 -= k;
}
Ponto operator-(const double k, Ponto p1){
    return p1 -= k;
}
/*Final da Classe ponto*/


/*Globais*/
Ponto inf;

int compareMyType(const void* entrada1, const void* entrada2){
    Ponto p1, p2;
    p1 = *(Ponto*)entrada1;
    p2 = *(Ponto*)entrada2;

    return p1.lexcmp(p2);
}

/*Acha pontos*/
pair<Ponto, Ponto> achaPonto(Ponto a, Ponto b, Ponto c){
    Ponto p , q;
    double ab, ac, bc, perimetro;
    double aq, ap, delta;
    ab = a.len(b);
    ac = a.len(c);
    bc = b.len(c);
    perimetro = ab + ac + bc;
   
    /***/
    if(TESTE_NIVEL_1){
        cout << "ACHAPONTO: AB = " << ab << endl;
        cout << "ACHAPONTO: AC = " << ac << endl;
        cout << "ACHAPONTO: BC = " << bc << endl;
        cout << "ACHAPONTO: PERIMETRO = " << perimetro << endl;
    }
    /***/
    delta = perimetro*perimetro - 8*ab*ac;
    if(abs(delta) <= EPSILON) delta = 0;
    if(delta >= 0){
        aq = (perimetro + sqrt(delta))/4;
        ap = (perimetro - sqrt(delta))/4;
        if(ap > 0){
            q = b - a;
            q.setIntensidade(aq);
            q = a + q;
            if(a.len(q) < a.len(b) + EPSILON){
                p = c - a;
                p.setIntensidade(ap);
                p = a + p;
                if(a.len(p) < a.len(c) +  EPSILON){
                    return make_pair(p,q);
                }
            }
            else{
                q = c - a;
                q.setIntensidade(aq);
                q = a + q;
                if(a.len(q) < a.len(b) + EPSILON){
                    p = b - a;
                    p.setIntensidade(ap);
                    p = a + p;
                    if(a.len(p) < a.len(b) + EPSILON){
                       return make_pair(p,q);
                    }
                }
            }
        }
        else{
            /***/
            if(TESTE_NIVEL_1){
                cout << "ACHAPONTO: ap negativo!" << endl;
            }
            /***/
        }
    }
    else{
        /***/
        if(TESTE_NIVEL_1){
            cout << "ACHAPONTO: delta negativo!" << endl;
        }
        /***/
    }
    return make_pair(inf, inf);
}

/***main***/
int main(){
    Ponto a, b, c;
    double x, y;
    pair<Ponto, Ponto> resposta;
    /*Inicializando*/
    inf = make_pair(INF, INF);

    /*Entrada*/
    cin >> x >> y;
    a = make_pair(x,y);
    cin >> x >> y;
    b = make_pair(x,y);
    cin >> x >> y;
    c = make_pair(x,y);

    /***/
    if(TESTE_NIVEL_1){
        cout << "MAIN: A = (" << a.x << "," << a.y << ")" << endl;
        cout << "MAIN: B = (" << b.x << "," << b.y << ")" << endl;
        cout << "MAIN: C = (" << c.x << "," << c.y << ")" << endl;
    }
    /***/

    /*Processamento*/
    cout << setprecision(20);
   
    resposta = achaPonto(a, b, c);
    if(resposta.first.x == INF){
        resposta = achaPonto(b,c,a);
        if(resposta.first.x == INF){
            resposta = achaPonto(c,b,a);
        }
        else{
            cout << "NO" << endl;
        }
    }
    /*Saida*/ 
    cout << "YES" << endl;
    cout << resposta.first.x << " " << resposta.first.y << endl;
    cout << resposta.second.x << " " << resposta.second.y << endl;
    return 0;
}
