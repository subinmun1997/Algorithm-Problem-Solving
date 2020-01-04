#include <stdio.h>

int main(void){
	int N,i,j;
	scanf("%d",&N);
	
	for(i=0;i<2*N-1;++i){
		if(i<N){
			for(int j=0;j<=i;j++)
				printf("*");
		}
		else if(i>=N){
			for(j=0;j<2*N-1-i;j++)
				printf("*");
		}
		printf("\n");
	}
	return 0;
}

