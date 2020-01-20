#include <stdio.h>

bool arr[10010]={0};
int n;

int main(void){
	int temp1,temp2,i,j;
	int count;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&temp1,&temp2);
		
		for(j=temp1+1;j<=temp2;j++){
			arr[j]=1;
		}
	}
	
	for(i=1;i<=10000;i++){
		if(arr[i]==1)
			count++;
	}
	
	printf("%d",count);
}
