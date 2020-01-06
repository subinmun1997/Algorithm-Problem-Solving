#include <stdio.h>
bool CHECK[1000000];
int MAP[5][5];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
bool isOut(int i, int j){
  return i < 0 || j < 0 || i >= 5 || j >= 5;
}

int go(int i, int j, int level, int val){
  if(level == 5){
    if(CHECK[val])return 0;
    CHECK[val] = true;
    return 1;
  }
  int total = 0;
  for(int k = 0; k < 4; k++){
   int ni = i + di[k];
   int nj = j + dj[k];
   if(isOut(ni, nj))continue;
   total += go(ni, nj, level + 1, val * 10 + MAP[ni][nj]); 
  }
  return total;
}


int main(){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      scanf("%d", &MAP[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      ans += go(i, j, 0, MAP[i][j]);
    }
  }
  printf("%d\n", ans);

  return 0;
}
