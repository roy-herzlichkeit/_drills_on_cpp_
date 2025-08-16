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
    solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;
    unordered_map<int, int> dp;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= 6; j++) 
            dp[i] = (dp[i] + dp[i - j]) % MOD;
    cout << (dp[n] % MOD) << endl;
}