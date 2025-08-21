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
    int n, r, b;
    cin >> n >> r >> b;
    int groups = b + 1;
    int base = r / groups;
    int excess = r % groups;
    string res;
    for (int i = 0; i < groups; ++i) {
        int addR = base + (excess > 0 ? 1 : 0);
        if (excess > 0) 
            --excess;
        res.append(addR, 'R');
        if (i < b) 
            res.push_back('B');
    }
    cout << res << '\n';
}