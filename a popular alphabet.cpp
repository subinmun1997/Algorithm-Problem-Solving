#include <stdio.h>
#include <string.h>

int main(){
	char arr[1000000];
	int count[26]={0,};
	int index=0;
	int max=0;
	int check=0;
	
	fgets(arr,sizeof(arr)-1,stdin);
	arr[strlen(arr)-1]='\0';
	
	while(arr[index]){
		if(arr[index]>90){
			arr[index]=arr[index]-32;
		}
		count[arr[index]-65] += 1;
		index++;
	}
	index = 1;
	
    while(index<26){
    	if(count[max]<count[index]){
		max=index;
		check = 0;
	}
	    else if(count[max]==count[index]){
		    check = 1;
	}
	index++;
    }

    if(check){
	    printf("\n");
    }
    else{
	    printf("%c\n",char(max+65));
    }
    return 0;
	
	
	
	
	
}
