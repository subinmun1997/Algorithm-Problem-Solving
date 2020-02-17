#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int visited[51][51], _max, ret, n, m;
string s;
char a[54][54];
queue<pair<int, int>> q;
void bfs(int y, int x){
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    visited[y][x] = 1;
    q.push({y, x});
    _max = 0;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 'W' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            if(_max <= visited[ny][nx]){
                _max = visited[ny][nx];
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L'){
                bfs(i, j);
                ret = max(ret, _max);
            }
        }
    }
    cout << ret - 1 << "\n";
    return 0;
}

