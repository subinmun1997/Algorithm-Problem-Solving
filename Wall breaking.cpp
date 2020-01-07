#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, k, visited[1001][1001][10], a[1001][1001], ret = INF; 
struct b{
	int y, x, wall;
};
queue<b> q; 
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1}; 
void fastIO(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return;
}
int main() { 
	scanf("%d %d %d", &n, &m, &k); 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]); 
		}
	}
	visited[0][0][0] = 1; 
	q.push({0, 0, 0}); 
	while(q.size()){ 
		int y = q.front().y; 
		int x = q.front().x; 
		int wall = q.front().wall;  
		q.pop();  
		if(y == n - 1 && x == m - 1){
			ret = min(ret, visited[y][x][wall]);  
		}
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i]; 
			int nx = x + dx[i]; 
			int next_wall = a[ny][nx] == 1 ? wall + 1 : wall;
			if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;   
			if(visited[ny][nx][next_wall] && visited[ny][nx][next_wall] <= visited[y][x][wall] + 1) continue;  
			if(a[ny][nx] == 1){ 
				if(next_wall > k) continue; 
				if(visited[y][x][wall] % 2 == 1){
					visited[ny][nx][next_wall] = visited[y][x][wall] + 1;
				}else{
					visited[ny][nx][next_wall] = visited[y][x][wall] + 2; 
				}
			}else{
				visited[ny][nx][next_wall] = visited[y][x][wall] + 1;
			} 
			q.push({ny, nx, next_wall});
		}
	}   
	printf("%d\n", ret == INF ? -1 : ret);   
  	return 0;
} 

