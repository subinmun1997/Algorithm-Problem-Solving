#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;   
int n, a[104][104], ret = INF, comp[104][104], compSize[5];  
int solve(int y, int x, int d1, int d2){ 
    memset(comp, 0, sizeof(comp)); 
    vector<int> _ret; 
    int startX = x; 
    int cnt = 1;
    int f1 = y + min(d1, d2); 
    int f2 = y + max(d1, d2); 
    int f3 = y + d2 + d1; 
    for(int i = y; i <= f1; i++){ 
        for(int j = startX; j < startX + cnt; j++){
            comp[i][j] = 5; 
        }
        if(i != f1){
            startX--;  
            cnt += 2; 
        } 
    }
    for(int i = f1 + 1; i <= f2; i++){ 
        if(d1 >= d2){
            startX--; 
            for(int j = startX; j < startX + cnt; j++){
                comp[i][j] = 5; 
            } 
        }else{
            startX++; 
            for(int j = startX; j < startX + cnt; j++){
                comp[i][j] = 5; 
            } 
        }
    } 
    for(int i = f2 + 1; i <= f3; i++){ 
        cnt -= 2; 
        startX++; 
        for(int j = startX; j < startX + cnt; j++){
            comp[i][j] = 5; 
        } 
    } 
    fill(compSize, compSize + 5, 0); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < y + d1 && j <= x) comp[i][j] = (comp[i][j] == 0 ? 1 : comp[i][j]); 
            if(i <= y + d2 && j > x) comp[i][j] = (comp[i][j] == 0 ? 2 : comp[i][j]);
            if(i >= y + d1 && j < x + (d2 - d1)) comp[i][j] = (comp[i][j] == 0 ? 3 : comp[i][j]); 
            if(i > y + d2 && j >= x + (d2 - d1)) comp[i][j] = (comp[i][j] == 0 ? 4 : comp[i][j]); 
            //cout << comp[i][j] << " ";
            compSize[comp[i][j] - 1] += a[i][j]; 
        } 
        //cout << "\n";
    }  
    const auto [min, max] = minmax_element(compSize, compSize + 5);  
    return *max - *min; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int d1 = 1; d1 < n; d1++){
                for(int d2 = 1; d2 < n; d2++){
                    if(i + d1 + d2 >= n || j - d1 < 0 || j + d2 >= n) continue;  
                    //cout << "___________START __________\n";
                    ret = min(ret, solve(i, j, d1, d2)); 
                }
            }
        }
    }
    cout << ret << "\n"; 
    return 0; 
}

