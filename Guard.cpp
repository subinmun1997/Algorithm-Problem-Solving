#include<bits/stdc++.h> 
using namespace std; 
int n, m, t, a, b, ret, path; 
struct Point{
    int dir, dist;  
}; 
vector<Point> v;
int main(){
    cin >> n >> m; 
    cin >> t; t++;  
    while(t--){
        cin >> a >> b;
        if(a == 2) b = n + m + (n - b); 
        else if(a == 3)b = 2 * n + m + (m - b); 
        else if(a == 4)b = n + b; 
        v.push_back({a, b});    
    } 
    Point _a = v[v.size() - 1];   
    for(int i = 0; i < v.size() - 1; i++){ 
        path = abs(_a.dist - v[i].dist); 
        ret += min(2 * n + 2 * m - path, path); 
    }
    cout << ret << "\n";
    return 0;
}
