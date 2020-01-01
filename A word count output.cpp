#include <stdio.h>
#include <string.h>

int main(void){
	char arr[1000001];
	int i=1;
	int count=0;
	fgets(arr,sizeof(arr)-1,stdin);
	arr[strlen(arr)-1]='\0';
	
	while(arr[i+1]){
		if(arr[i] == ' '){
			if((arr[i-1] != ' ') && (arr[i+1] != ' '))
				count++;
		}
		i++;
	}
	if(strlen(arr) == 1 && arr[0] == ' ')
		count--;
	printf("%d\n",++count);
	return 0;
}
