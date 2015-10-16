/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 21*************/
/***********************************/

#include<bits/stdc++.h>

#define TESTE_NIVEL_1 0

using namespace std;


/*****************/
/***main***/
int main(){
    string ent, s;
    char sep = '-';
    int nNos = 0;
    map<string, bool> comp;

  getline(cin, ent);
  while(ent != "#"){
      for(size_t p=0, q=0; p!=ent.npos; p=q){
          s = ent.substr(p+(p!=0),
                  (q=ent.find(sep, p+1))-p-(p!=0));
          if(!comp.count(s)){
              comp[s] = true;
              nNos++;
          }
      }
      getline(cin, ent);
  }
  if(TESTE_NIVEL_1){
      for(auto a : comp){
          cout << a.first << endl;
      }
  }
  if(nNos == 0){
      cout << 0 << endl;
  }
  else{
      cout << nNos - 1 << endl;
  }
       
   return 0;
}
