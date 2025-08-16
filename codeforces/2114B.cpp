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
    ll k;
    string s;
    cin >> n >> k;
    cin >> s;
    int z = 0;
    for (char c: s) 
        if (c == '0') 
            z++;
    int t = n - z;
    int D = z - (n / 2);
    if (k < abs(D) || k > (n / 2) || ((k - D) % 2 != 0)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}