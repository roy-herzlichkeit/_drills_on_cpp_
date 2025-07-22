#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

typedef long long ll;

const int INF = 1e9 + 7;

ll good(ll);
inline static void solver(void);

vector<int> primes = {2, 3, 5, 7};

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
    ll l, r;
    cin >> l >> r;
    ll res = good(r) - good(l - 1);
    cout << res << endl;
}

ll good(ll n)
{
    if (n == 0)
        return 0;
    ll bad = 0;
    for (int mask = 1; mask < 16; mask++)
    {
        ll prod = 1;
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            if (mask & (1 << i))
            {
                cnt++;
                prod *= primes[i];
            }
        }
        if (prod > n)
        {
            continue;
        }
        ll terms = n / prod;
        if (cnt % 2 == 1)
        {
            bad += terms;
        }
        else
        {
            bad -= terms;
        }
    }
    return n - bad;
}