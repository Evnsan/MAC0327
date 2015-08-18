#include<stdio.h>

int main(){
    int vetor1[]={1, 2, 3, 4};
    int vetor2[]={5, 6, 7, 8};
    int *tmp;

    tmp =(int*)vetor1;
    printf("=>%d\n", tmp[1]);
    tmp = (int*)vetor2;
    printf("==>%d\n", tmp[1]);
    return 0;
}
