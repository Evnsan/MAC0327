#include <stdio.h>
#include <stdlib.h>


/*resubmetendo*/ 
int main()
{
	int n, hmin, damax, ddmax, da, dd, di;
	int *a;
	
	int i = 1;
	
	scanf("%d", &n);
	/*printf("%d\n" , n);*/
	a =  (int*)malloc(n * sizeof(int));
	for(i = 0; i < n ; i++)
		scanf("%d" , &a[i]);
    
	damax = da = a[1] - a[0];
	ddmax = dd = a[2] - a[1];
	hmin = da + dd;
		
	for( i = 2; i < n-1; i++){
		da = dd;
		dd = a[i+1] - a[i];
		di = da + dd;
		if(di < hmin){
			hmin = di;
			if(damax > di && damax > ddmax) ddmax = 0;

			else if(ddmax > di) damax = 0;
			else{
				damax = da;
				ddmax = dd;
			}
		}
		if(dd > damax + ddmax){
			damax = 0;
			ddmax = dd;
		}
	}

	printf("%d\n" , damax + ddmax);
	return 0;
}
