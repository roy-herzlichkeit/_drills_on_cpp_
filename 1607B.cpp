#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solver() {
    ll x, n;
    cin >> x >> n;
    ll r = n & 3LL;
    if (r == 0)
        n = 0;
    else if (r == 1)
        n = -n;
    else if (r == 2)
        n = 1;
    else if (r == 3)
        n = n + 1;
    if (x & 1LL)
        cout << x - n << "\n";
    else
        cout << x + n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solver();
    }
    return 0;
}