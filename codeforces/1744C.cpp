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
    return 0;
}

inline static void solver(void) {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    if (c == 'g') {
        cout << 0 << endl;
        return;
    }
    int res = INT_MIN;
    bool flag = false;
    int j = n - 1, clast = -1;
    for (; j >= 0; j--) {
        if (s[j] == 'g')
            break;
    }
    for (int k = j + 1; k < n; k++) {
        if (s[k] == c) {
            clast = k;
            break;
        }
    }
    if (j < clast)
        flag = true;
    for (int i = j; i >= 0; i--) {
        if (s[i] == 'g') {
            j = i;
        } else if (s[i] == c) {
            res = max(res, j - i);
        }
    }
    if (flag) {
        res = max(res, (j + n - clast));
    }
    cout << res << endl;
}