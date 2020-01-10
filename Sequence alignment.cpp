#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
	int index;
	int value;
}A;
int P[50];

bool comp(A a,A b){
	if(a.value<b.value){
		return true;
	}
	else if(a.value>b.value){
		return false;
	}
	else{
		if(a.index<b.index){
			return true;
		}
		else{
			return false;
		}
	}
}

int main(){
	A arr[50];
	
	int i,N;
	cin >> N;
	
	for(i=0;i<N;i++){
		cin >> arr[i].value;
		arr[i].index = i;
	}
	sort(arr,arr+N,comp);
	
	for(i=0;i<N;i++){
		P[arr[i].index] = i;
	}
	
	for(i=0;i<N;i++){
		cout << P[i] << " ";
	}
	cout << endl;
	
	return 0;
}

