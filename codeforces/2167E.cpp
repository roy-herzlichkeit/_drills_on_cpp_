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

inline static void solver() {
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (auto &val : a) cin >> val;
    sort(a.begin(), a.end());

    auto build_allowed = [&](ll D) {
        vector<pair<ll,ll>> forbidden;
        if (D > 0) {
            forbidden.reserve(n);
            ll radius = D - 1;
            for (ll pos : a) {
                ll L = max(0LL, pos - radius);
                ll R = min(x, pos + radius);
                if (L <= R) forbidden.emplace_back(L, R);
            }
        }
        sort(forbidden.begin(), forbidden.end());
        vector<pair<ll,ll>> merged;
        for (const auto &seg : forbidden) {
            ll L = seg.first;
            ll R = seg.second;
            if (merged.empty() || merged.back().second + 1 < L) {
                merged.emplace_back(L, R);
            } else {
                merged.back().second = max(merged.back().second, R);
            }
        }
        vector<pair<ll,ll>> allowed;
        ll cur = 0;
        for (const auto &seg : merged) {
            ll L = seg.first;
            ll R = seg.second;
            if (cur < L) allowed.emplace_back(cur, L - 1);
            cur = max(cur, R + 1);
        }
        if (cur <= x) allowed.emplace_back(cur, x);
        return allowed;
    };

    auto can = [&](ll D) {
        auto allowed = build_allowed(D);
        long long cnt = 0;
        for (const auto &seg : allowed) {
            ll L = seg.first;
            ll R = seg.second;
            cnt += (R - L + 1);
            if (cnt >= k) return true;
        }
        return false;
    };

    ll lo = 0, hi = x, best = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (can(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    auto allowed = build_allowed(best);
    vector<ll> teleports;
    teleports.reserve(k);
    for (const auto &seg : allowed) {
        ll L = seg.first;
        ll R = seg.second;
        for (ll pos = L; pos <= R && (int)teleports.size() < k; ++pos) {
            teleports.push_back(pos);
        }
        if ((int)teleports.size() == k) break;
    }

    for (int i = 0; i < k; ++i) {
        cout << teleports[i] << (i + 1 == k ? '\n' : ' ');
    }
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