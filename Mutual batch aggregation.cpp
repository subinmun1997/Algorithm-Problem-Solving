#include<bits/stdc++.h>   
using namespace std; 
int uf[1000001], a[1000001], n, m, temp, ok = 1, value;
int find(int n){
    if(uf[n] < 0) return n; 
    return find(uf[n]);
}
bool merge(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return 1; 
    else {
        uf[b] = a; return 0;
    }
}
int main(){
    cin >> n >> m; 
    fill(uf, uf + 1000001, -1);
    for(int i =1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> value; if(value) merge(i, j);
        }
    }
    cin >> temp;
    int root = find(temp);
    for(int i = 1; i < m; i++){
        cin >> temp; 
        if(root != find(temp)) ok = 0; 
    }
    if(ok) cout << "YES" << "\n";
    else cout << "NO" << "\n"; 
    return 0;
} 

