#include <stdio.h>

int main(void){
	int i,alpha,max=0;
	char c='?';
	char word[1000001];
	int alphabetCnt[26]={0,};
	fgets(word,sizeof(word),stdin);
	
	for(i=0;word[i]!='\0';i++){
		if('a'<=word[i])
			word[i]=word[i]-32;
		alphabetCnt[word[i]-'A']++;
	}
	
	for(alpha=0;alpha<='Z'-'A';alpha++){
		if(alphabetCnt[alpha]>max){
			max = alphabetCnt[alpha];
			c = alpha;
		}
		else if(alphabetCnt[alpha]==max){
			c='?';
		}
	}
	printf("%c",(c=='?')? '?':c+65);
	return 0;
}
