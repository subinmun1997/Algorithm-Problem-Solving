#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		int result = 1;
		
		pair<int, int> p[N];
		
		for(int j = 0; j < N; j++){
			cin >> p[j].first >> p[j].second;
		}
		
		sort(p, p + N);
		
		int temp = p[0].second;

		for(int j = 1; j < N; j++){
			if(temp > p[j].second){
				temp = p[j].second;
				result++;
			}
		}
		cout << result << endl;
	}
	return 0;
}

