// MEMOIZATION -> O(n * target) -> max of O(1e8)
// #include <bits/stdc++.h>
// using namespace std;
 
// #define all(v) v.begin(), v.end()
 
// typedef long long ll;
 
// const int INF = 1e9 + 7;
// int res, n, target;
// vector<int> dp;

// void backtrack(int i, int sum, vector<int>& coins);
// inline static void solver(void);

// signed main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     #ifdef LOCAL
//         freopen("a.in", "r", stdin);
//     #endif
//     solver();
//     exit(EXIT_SUCCESS);
// }

// inline static void solver(void) {
//     cin >> n >> target;
//     vector<int> coins(n);
//     for (int& coin : coins)
//         cin >> coin;
//     res = INT_MAX;
//     dp.assign(target + 1, INT_MAX);
//     backtrack(0, 0, coins);
//     if (res == INT_MAX)
//         cout << "-1\n";
//     else    
//         cout << res << endl;
// }

// void backtrack(int i, int sum, vector<int>& coins) {
//     if (sum == target) {
//         res = min(res, i);
//         return;
//     } else if (sum > target) {
//         return;
//     }
//     if (dp[sum] <= i) 
//         return;
//     dp[sum] = i;
//     for (int j = 0; j < n; j++) 
//         backtrack(i + 1, sum + coins[j], coins);
// }
#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
ll dp[1000001];
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
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) 
        cin >> coins[i]; 
	for (int i = 0; i <= x; i++) 
        dp[i] = INT_MAX; 
	dp[0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int weight = coins[i - 1]; weight <= x; weight++) 
			dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
	cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}