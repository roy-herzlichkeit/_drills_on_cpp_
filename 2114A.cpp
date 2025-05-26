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
    string s;
    cin >> s;
    int n = stoi(s);
    int root = int(floor(sqrt(n) + 0.5));
    if (root * root == n) {
        cout << 0 << ' ' << root << '\n';
    } else {
        cout << -1 << '\n';
    }
}