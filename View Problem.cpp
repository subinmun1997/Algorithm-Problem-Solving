#include <stdio.h>
#define MAX_NUM 1000

int buildings[MAX_NUM];

int CheckSight(int );
int main(void){
	int test_case;
	int i=0;
	while(i<10){
		int index;
		int result;
		scanf("%d",&test_case);
		
		for(index=0; index<test_case; index++){
			scanf("%d",&buildings[index]);
		}
		result = CheckSight(test_case);
		
		printf("#%d %d\n",++i,result);
	}
	return 0;
}

int CheckSight(int length){
	int i;
	int max_top;
	int check;
	int result=0;
	
	for(i=2;i<length-2;i++){
		int temp_index=i-2;
		check=0;
		max_top=0;
		
		for(;temp_index<i+3;temp_index++){
			if(i==temp_index) continue;
			
			else if(buildings[temp_index]>=buildings[i]){
				check = 1;
				break;
			}
			else{
				if(max_top<buildings[temp_index])
					max_top = buildings[temp_index];
				continue;
			}
		}
		
		if(!check){
			result += buildings[i]-max_top;
		}
		
	}
	
	return result;
	
}




