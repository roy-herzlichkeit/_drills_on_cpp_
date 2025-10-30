#include <bits/stdc++.h>
#define MOD 1e9+7
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vll = vector<ll>;

static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static inline unsigned long long splitmix64(unsigned long long x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

static mt19937_64 rng((unsigned)splitmix64(chrono::high_resolution_clock::now().time_since_epoch().count()));

struct chash {
    size_t operator()(unsigned long long x) const {
        static const unsigned long long FIXED_RANDOM = splitmix64(chrono::high_resolution_clock::now().time_since_epoch().count());
        return (size_t)splitmix64(x + FIXED_RANDOM);
    }
};

#ifndef ONLINE_JUDGE
  #define dbg(...) do{ fprintf(stderr, "DBG (%s:%d) = ", __FILE__, __LINE__); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); } while(0)
  #define debug_var(x) cerr << #x << " = " << (x) << "\n";
#else
  #define dbg(...) (void)0
  #define debug_var(x) (void)0
#endif

template<class T> inline T aabs(T x){ return x < 0 ? -x : x; }
template<class T> inline T ceil_div(T a, T b){ return (a + b - 1) / b; }
template<class T> inline void chmin(T &a, T b){ if(b < a) a = b; }
template<class T> inline void chmax(T &a, T b){ if(b > a) a = b; }

void solver() {
    ll R0, D; 
    int X, n;
    cin >> R0 >> X >> D >> n;
    string s; 
    cin >> s;
    int N = n;
    vector<vector<pair<ll, ll>>> curr(N + 1), nxt(N + 1);
    curr[0].push_back({R0, R0});

    auto add_interval = [&] (vector<pair<ll, ll>> &vec, ll L, ll R) -> void {
        if (L > R) 
            return;
        if (R < 0) 
            return;
        if (L < 0) 
            L = 0;
        vec.emplace_back(L, R);
    };

    auto normalize = [&] (vector<pair<ll, ll>> &v) -> void {
        if (v.empty()) 
            return;
        sort(v.begin(), v.end());
        vector<pair<ll, ll>> res;
        res.reserve(v.size());
        ll L = v[0].first, R = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first <= R + 1) {
                R = max(R, v[i].second);
            } else {
                res.emplace_back(L, R);
                L = v[i].first; R = v[i].second;
            }
        }
        res.emplace_back(L, R);
        v.swap(res);
    };

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        for (int c = 0; c <= N; c++) 
            nxt[c].clear();

        for (int c = 0; c <= N; c++) {
            for (auto seg : curr[c]) {
                ll L = seg.first, R = seg.second;
                if (L > R) 
                    continue;
                if (ch == '1') {
                    if (c + 1 <= N) 
                        add_interval(nxt[c + 1], max(0LL, L - D), R + D);
                } else {
                    ll L1 = L, R1 = min<ll>(R, (ll)X - 1);
                    if (L1 <= R1) 
                        if (c + 1 <= N) 
                            add_interval(nxt[c + 1], max(0LL, L1 - D), R1 + D);
                    ll L2 = max<ll>(L, X), R2 = R;
                    if (L2 <= R2) 
                        add_interval(nxt[c], L2, R2);
                }
            }
        }

        for (int c = 0; c <= N; c++) 
            normalize(nxt[c]);
        curr.swap(nxt);
    }

    int res = 0;
    for (int c = N; c >= 0; c--) {
        if (!curr[c].empty()) { 
            res = c; 
            break; 
        }
    }
    cout << res << '\n';
}

int main() {
    fast_io();
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif

    int T = 1;
    if(!(cin >> T)) return 0;
    while(T--) solver();

    return 0;
}