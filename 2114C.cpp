#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

inline static void solver(void);

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    ll fin = a[0];
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] >= fin + 2) {
            res++;
            fin = a[i];
        }
    }
    cout << res << "\n";
}