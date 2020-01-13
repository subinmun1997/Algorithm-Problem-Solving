#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;


long long eightToTwo(string e){
  long long c = 1LL;
  int p = e.length();
  p -= 1;
  long long target = 0LL;
  while(p >= 0){
   long long tmp = stoll(e.substr(p, 1));
    target += (tmp * c);
    c *= 8;
    p -= 1;
  }
  return target;
}

string tenToTwo(long long e){
  string ans = "";
  while(e != 0){
    if(e % 2 == 1){
      ans = "1" + ans;
    }else{
      ans = "0" + ans;
    }
    e /= 2;
  }
  return ans;
}

int main(){
  string e;
  cin >> e;
  cout << tenToTwo(eightToTwo(e)) << endl;



  return 0;
}

