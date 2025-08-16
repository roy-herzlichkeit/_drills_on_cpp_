#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
const int INF = 1e9 + 7;

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    ll base = b * k;
    ll rem = s - base;
    if (rem < 0 || rem > (k - 1) * n) {
        cout << -1 << "\n";
        return;
    }
    vector<ll> a(n, 0);
    a[0] = base + min(rem, k - 1);
    rem -= min(rem, k - 1);
    for (int i = 1; i < n && rem > 0; ++i) {
        a[i] = min(rem, k - 1);
        rem -= a[i];
    }
    for (ll x : a)
        cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}