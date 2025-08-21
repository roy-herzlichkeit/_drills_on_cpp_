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
    int a, b, min_op = INT_MAX, op1 = 0, op2 = 0;
    cin >> a >> b;
    if (b == 1) {
        b++;
        op2++;
    }
    for (int extra = 0; extra <= 40; ++extra) {
        int curr = b + extra;
        op1 = 0;
        int temp = a;
        while (temp > 0) {
            temp /= curr;
            ++op1;
        }
        min_op = min(min_op, op1 + op2 + extra);
        if (op2 + extra >= min_op) break;
    }
    cout << min_op << endl;
}