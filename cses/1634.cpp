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
    int n, target;
    cin >> n >> target;
    unordered_map<int, int> dp;
    vector<int> coins(n);
    for (int& coin : coins) {
        cin >> coin;
        if (coin == target) {
            cout << "1\n";
            return;
        }
        dp[coin] = 1;
    }
    for (int i = 1; i <= target; i++) {
        if (dp[i])
            continue;
        dp[i] = INT_MAX;
        for (const int& coin : coins) {
            if (coin > i || dp[i - coin] == INT_MAX)
                continue;
            dp[i] = min(dp[i], dp[coin] + dp[i - coin]);
        }
    }
    dp[target] = dp[target] == INT_MAX ? -1 : dp[target];
    cout << dp[target] << endl;
}