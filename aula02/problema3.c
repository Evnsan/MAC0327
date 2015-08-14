#include <stdio.h>

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    if(n < 4){
        printf("NO\n");
    }
    else{
        if(n%2 == 0){
            printf("YES\n");
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
            for(i = 5; i <= n; i+= 2){
                printf("%d - %d = 1\n", i+1, i);
                printf("24 * 1 = 24\n");
            }
        }
        else{
            printf("YES\n");
            printf("1 * 2 = 2\n");
            printf("3 + 4 = 7\n");
            printf("7 + 5 = 12\n");
            printf("12 * 2 = 24\n");
            for(i = 6; i <= n; i+= 2){
                printf("%d - %d = 1\n", i+1, i);
                printf("24 * 1 = 24\n");
            }
        }
    }
    
	return 0;
}
