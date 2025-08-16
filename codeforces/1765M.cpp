#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef unsigned long long ll;
 
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
    cin >> n;
    if (n % 2 == 0) {
        n = n >> 1;
        cout << n << " " << n << endl;
        return;
    }
    int a = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i) {
            continue;
        } else {
            a = n / i;
            break;
        }
    }
    cout << a << " " << n - a << endl;
    return;
}