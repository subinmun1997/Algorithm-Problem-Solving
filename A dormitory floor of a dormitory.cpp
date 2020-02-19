#include <bits/stdc++.h>
using namespace std;
int l, w, a, b;
bool f(int _a, int _b){
    if((_a + 2) * (_b + 2) - _a * _b != l) return false;
    else return true;
}
int main(){
    cin >> l >> w;
    for(int i = 1; i <= w; i++){
        if(w % i == 0){
            if(f(i, w/i)){
                a = i; b = w / i;
                if(a < b) swap(a, b);
                cout << a + 2<< " " << b + 2 << "\n";
                break;
            }
        }
    }
    return 0;
}


