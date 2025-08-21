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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int res = 0;
    for (int len = 1; len <= min(n, m); len++) 
        for (int i = 0; i + len <= n; i++) 
            for (int j = 0; j + len <= m; j++) 
                if (a.substr(i, len) == b.substr(j, len)) 
                    res = max(res, len);
    cout << a.size() + b.size() - 2 * res << "\n";
}