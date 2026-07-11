#include <bits/stdc++.h>
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

int main() {
    fast_io();
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif

    int N, K;
    cin >> N >> K;

    vector<ll> A(N), B(N);
    ll base = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        base += A[i];
    }

    const ll NEG = -(1LL << 60);
    vector<ll> dp0(K + 1, NEG), dp1(K + 1, NEG);
    dp0[0] = 0;

    for (int i = 0; i < N; ++i) {
        ll d = B[i] - A[i];
        vector<ll> ndp0(K + 1, NEG), ndp1(K + 1, NEG);
        for (int j = 0; j <= K; ++j) {
            ndp0[j] = max(ndp0[j], dp0[j]);
            ndp0[j] = max(ndp0[j], dp1[j]);
        }
        for (int j = 1; j <= K; ++j) {
            if (dp1[j] != NEG) 
                ndp1[j] = max(ndp1[j], dp1[j] + d);
            if (dp0[j - 1] != NEG) 
                ndp1[j] = max(ndp1[j], dp0[j - 1] + d);
        }

        dp0.swap(ndp0);
        dp1.swap(ndp1);
    }

    ll best = 0;
    for (int j = 0; j <= K; ++j) {
        best = max(best, dp0[j]);
        best = max(best, dp1[j]);
    }

    cout << base + best << '\n';

    return 0;
}