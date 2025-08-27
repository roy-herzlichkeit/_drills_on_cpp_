#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

static inline void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static inline unsigned long long splitmix64(unsigned long long x)
{
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

static mt19937_64 rng((unsigned)splitmix64(chrono::high_resolution_clock::now().time_since_epoch().count()));

struct chash
{
    size_t operator()(unsigned long long x) const
    {
        static const unsigned long long FIXED_RANDOM = splitmix64(chrono::high_resolution_clock::now().time_since_epoch().count());
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};

#ifndef ONLINE_JUDGE
#define dbg(...)                                               \
    do                                                         \
    {                                                          \
        fprintf(stderr, "DBG (%s:%d) = ", __FILE__, __LINE__); \
        fprintf(stderr, __VA_ARGS__);                          \
        fprintf(stderr, "\n");                                 \
    } while (0)
#define debug_var(x) cerr << #x << " = " << (x) << "\n";
#else
#define dbg(...) (void)0
#define debug_var(x) (void)0
#endif

template <class T>
inline T aabs(T x) { return x < 0 ? -x : x; }
template <class T>
inline T ceil_div(T a, T b) { return (a + b - 1) / b; }
template <class T>
inline void chmin(T &a, T b)
{
    if (b < a)
        a = b;
}
template <class T>
inline void chmax(T &a, T b)
{
    if (b > a)
        a = b;
}

inline static void solver()
{
    int n;
    if (!(cin >> n))
        return;
    vector<ll> a(n + 1);
    ll total = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        total += a[i];
    }
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    vector<ll> P(n + 1, 0);
    vector<ll> prefMax(n + 1, LLONG_MIN);
    prefMax[0] = 0;
    ll kept = 0;

    int i = 1;
    if (n >= 2)
    {
        ll x = min(a[1], a[2]);
        ll y = a[2];
        kept += x + y;
        P[1] = -x;
        P[2] = -x + y;
        prefMax[1] = max(prefMax[0], P[1]);
        prefMax[2] = max(prefMax[1], P[2]);
        i = 3;
    }

    for (; i + 1 <= n; i += 2)
    {
        ll S = P[i - 1];
        ll M = prefMax[i - 2];
        ll xCap = S - M;
        if (xCap < 0)
            xCap = 0;
        ll x = min({a[i], a[i + 1], xCap});
        ll y = a[i + 1];
        kept += x + y;
        P[i] = S - x;
        P[i + 1] = P[i] + y;
        prefMax[i] = max(prefMax[i - 1], P[i]);
        prefMax[i + 1] = max(prefMax[i], P[i + 1]);
    }

    if (i == n && (n & 1))
    {
        ll S = P[n - 1];
        ll M = prefMax[n - 2];
        ll xCap = S - M;
        if (xCap < 0)
            xCap = 0;
        ll x = min(a[n], xCap);
        kept += x;
    }

    ll res = total - kept;
    cout << res << '\n';
}

int main()
{
    fast_io();
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    int T = 1;
    if (!(cin >> T))
        return 0;
    while (T--)
        solver();

    return 0;
}