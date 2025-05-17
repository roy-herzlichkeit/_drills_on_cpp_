#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        int bits = 32 - __builtin_clz(x);
        int full = (1 << bits) - 1;
        if((x & (x - 1)) == 0 || x == full){
            cout << -1 << "\n";
            continue;
        }
        if((x & 1) == 0){
            cout << x - 1 << "\n";
            continue;
        }
        int k = 1;
        while(x & (1 << k)) k++;
        cout << x - (1 << k) << "\n";
    }
    return 0;
}
