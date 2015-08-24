#include<stdio.h>

int main(){
    int matriz[][4]={{1, 2, 3, 4},{5, 6, 7, 8}};
    int *tmp;
    tmp = (int*)matriz;
    printf("=>%d\n", *((tmp+1*4)+2));
    return 0;
}
