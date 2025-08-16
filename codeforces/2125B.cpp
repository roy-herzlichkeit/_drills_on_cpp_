#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

typedef long long ll;

const int INF = 1e9 + 7;

inline static void solver(void);

signed main(void)
{
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

inline static void solver(void)
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (a <= k && b <= k)
    {
        cout << 1 << "\n";
        return;
    }
    ll g = __gcd<ll>(a, b);
    ll dx = a / g, dy = b / g;
    if (dx <= k && dy <= k)
    {
        cout << 1 << "\n";
        return;
    }
    cout << 2 << "\n";
}