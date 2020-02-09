#include <bits/stdc++.h> 
using namespace std; 
int n, visited[24][24], a[24][24], ret; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1};
struct Shark{
    int y, x, size, eat;
    Shark(){
        y = -1; 
        x = -1; 
        size = 0; 
        eat = 0; 
    }
    Shark(int y, int x, int size, int eat) : y(y), x(x), size(size), eat(eat){}
    bool operator < (const Shark & a)const{
        if(size == a.size){
            if(y == a.y){
                return x < a.x; 
            }
            return y < a.y; 
        }
        return size < a.size; 
    } 
};  
Shark shark; 
vector<Shark> v; 
int bfs(int y, int x){ 
    fill(&visited[0][0], &visited[0][0] + 24 * 24, 0);   
    visited[shark.y][shark.x] = 1;  
    queue<int> q; 
    q.push(1000 * shark.y + shark.x);
    while(q.size()){
        int _y = q.front() / 1000; 
        int _x = q.front() % 1000;  
        if(_y == y && _x == x){
            return visited[_y][_x] - 1; 
        }
        q.pop(); 
        for(int i = 0; i < 4; i++){
            int ny = _y + dy[i]; 
            int nx = _x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue; 
            if(a[ny][nx] > shark.size) continue; 
            visited[ny][nx] = visited[_y][_x] + 1; 
            q.push(1000 * ny + nx); 
        }
    } 
 
 
    return 0; 
}
void solve(){
    v.clear();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            if(a[i][j] < shark.size && a[i][j] != 0){  
                int _dist = bfs(i, j);  
                if(_dist){ 
                    v.push_back({i, j, _dist, 0}); 
                } 
            } 
        }
    } 
    if(v.size()){ 
        sort(v.begin(), v.end()); 
        int rety = v[0].y; 
        int retx = v[0].x; 
        ret += v[0].size; 
        // 상어가 먹어버린거여. 
        a[rety][retx] = 0; 
        int _size = shark.size; 
        int eat = shark.eat; 
        if(eat + 1 == _size){
            _size++; 
            eat = 0; 
        }else eat++; 
        shark = {rety, retx, _size, eat}; 

        solve();
    } 
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j]; 
            if(a[i][j] == 9){
                shark = {i, j, 2, 0}; 
                a[i][j] = 0;
            }
        }
    }
    solve(); 
	cout << ret << "\n";
    return 0;
}

