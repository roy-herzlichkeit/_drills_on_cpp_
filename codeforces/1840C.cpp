#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

inline static void solver(void);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<bool> a(n);
    auto helper = [] (int x, int k) {
        return ((1LL * (x - k + 1)) * (1LL * (x - k + 2)) / 2LL);
    };
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        a[i] = (temp > q) ? false : true;
    }
    n++;
    a.push_back(false);
    ll res = 0LL;
    for (int j = 0, c = 0; j <= n; j++) {
        if (a[j] == false) {
            if (c >= k)
                res += 1LL * helper(c, k);
            c = 0;
        } else {
            c++;
        }
    }
    cout << res << endl;
}