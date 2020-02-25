#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;   
vector<pair<int, int>> adj[100004]; 
int n, s, e, x, y, cost, visited[100004], dp[100004], _max[100004];
void go(int here, int dist, int m){
    dp[here] = dist; 
    _max[here] = m; 
    visited[here] = 1; 
    for(auto there : adj[here]){ 
        if(visited[there.first]) continue;
        go(there.first, dist + there.second, max(m, there.second));  
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n >> s >> e; 
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y >> cost; 
        adj[x].push_back({y, cost});
        adj[y].push_back({x, cost}); 
    }
    go(s, 0, 0);
    cout << dp[e] - _max[e] << "\n";
    return 0;
}


