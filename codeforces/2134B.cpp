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

inline static void solver() {
    int n; ll k; 
    cin >> n >> k;
    vll a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    if(n == 1){
        if(a[0] == 1) a[0] += k; // one operation suffices
        cout << a[0] << '\n';
        return;
    }

    // Pick smallest prime p (<=47) not dividing k; one always exists since 47# > 1e9.
    static const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int p = 2; // default
    for(int pr: primes){ if(k % pr != 0){ p = pr; break; } }
    // Ensure p-1 <= k (since p <= k+1 automatically). If p-1 > k (can only happen if k < p-1 but then p > k+1) so safe.

    // Modular inverse of k mod p (since p does not divide k).
    ll kmod = k % p;
    auto mod_pow = [&](ll b, ll e)->ll{
        ll r=1%p; b%=p; while(e){ if(e&1) r = (r*b)%p; b = (b*b)%p; e >>=1; } return r; };
    ll invk = mod_pow(kmod, p-2); // Fermat's little theorem

    // Build final array: choose m_i so that a_i + k*m_i ≡ 0 (mod p); m_i in [0, p-1] and p-1 <= k
    for(int i=0;i<n;++i){
        ll need = (p - (a[i] % p)) % p; // need ≡ k*m_i (mod p)
        ll m = (need * invk) % p;       // minimal m satisfying congruence
        // m <= p-1 <= k
    unsigned long long val = (unsigned long long)k * (unsigned long long)m + (unsigned long long)a[i];
    // k,m <= 1e9 so product <= 1e18 fits in 64-bit
    cout << val << (i+1==n?'\n':' ');
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