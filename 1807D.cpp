#include <bits/stdc++.h>
using namespace std;

void solver() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1), prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    while (q--) {
        int l, r;
        long long k;
        cin >> l >> r >> k;
        long long subarraySum = prefix[r] - prefix[l - 1];
        long long newSum = prefix[n] - subarraySum + (long long)(r - l + 1) * k;
        cout << (newSum % 2 == 1 ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
        solver();
    return 0;
}