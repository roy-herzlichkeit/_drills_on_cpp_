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
    uint64_t n, k;
    cin >> n;
    k = n;
    while (k > 0)
    {
        int a = k % 10;
        k = k / 10;
        if (a > 0 && n % a != 0)
        {
            n++;
            k = n;
        }
    }
    cout << n << endl;
}