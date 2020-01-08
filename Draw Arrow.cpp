#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
ll ret, n, b, c; 
const int INF = 987654321; 
vector<ll> v[100004];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;    
    for(int i = 0; i < n; i++){
        cin >> b >> c;
        v[c].push_back(b);  
    }  
    for(int i = 0; i < 100004; i++){
        if(v[i].size()){
            sort(v[i].begin(), v[i].end());  
            for(int j = 0; j < v[i].size(); j++){
                int _b = INF, _c = INF; 
                if(j + 1 <= v[i].size() - 1)_b = v[i][j + 1] - v[i][j];
                if(j - 1 >= 0)_c = v[i][j] - v[i][j - 1];   
                ret += min(_b, _c); 
            } 
        }
    } 
    cout << ret << "\n"; 

    return 0;
}


