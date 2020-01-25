#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ret;
pair<int, int> a[500001];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first; a[i].second = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(a[i].second - i >= 0)ret = max(ret, abs(i - a[i].second));
    }
    cout << ret + 1<< "\n";
    return 0;
}


