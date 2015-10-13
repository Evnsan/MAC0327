/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 02*************/
/***********************************/

#include<bits/stdc++.h>

#define MAX 8 

#define TESTE_NIVEL_1 1
#define TESTE_NIVEL_2 0

using namespace std;
#include <queue>
#include <iostream>
  
using namespace std;
  
struct comparator {
    bool operator()(pair< pair<int, int>, int>  i, pair< pair<int, int>, int > j) {
    return i.second > j.second;
    }
};
  
int main(int argc, char const *argv[])
{
    priority_queue<int, vector< pair< pair<int, int>, int> > , comparator> minHeap;
  
    minHeap.push(make_pair(make_pair(1,2), 10));
    minHeap.push(make_pair(make_pair(1,3), 12));
    minHeap.push(make_pair(make_pair(1,4), 3));
    minHeap.push(make_pair(make_pair(1,5), 3));
    minHeap.push(make_pair(make_pair(1,6), 4));
    minHeap.push(make_pair(make_pair(1,7), 6));
    minHeap.push(make_pair(make_pair(1,8), 5));
  
    while (!minHeap.empty()) {
        cout << minHeap.top().first.first << " " << minHeap.top().first.second << " " << minHeap.top().second << endl;
        minHeap.pop();
    }
    return 0;
}
