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
    solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            cout << "YES\n" << (i + 1) << " " << (i + 2) << endl;
            return;
        }
    }
    cout << "NO\n";
}