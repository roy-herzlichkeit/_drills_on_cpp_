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
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    bool flag = false;
    int l1 = n / 2;
    if (k < n / 2) {
        flag = true;
        l1 = k;
    }
    ll res = 0ll;
    int i;
    for (i = 0; i < l1; i++) {
        res ^= (x * (!(i & 1)));
        x = (x * a + b) % c;
    }
    if (!flag && n % 2) {
        res ^= (x * (k % 2));
        x = (x * a + b) % c;
        i++;
    } 
    if (flag) {
        for (; i < n - l1 + 1; i++) {
            if (k % 2)
                res ^= x;
            x = (x * a + b) % c;    
        }
    }
    for (; i < n; i++) {
        res ^= (x * (i & 1));
        x = (x * a + b) % c;
    }
    cout << res << endl;
}

int main() {
    fast_io();
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif

    solver();

    return 0;
}

/*
Basically if the half point of array is smaller than k we will choose it or else k
if it is k:
    we will iterate from index 0 to k 
    xorring items which occur at odd positions 
    since xor of numbers with even occurences is 0
    then the remaining middle elements would be xorred if our k is odd, else would just be calc'd for future x
    after that we will iterate from n - k + 1 to n - 1 
    we will xor 'em only if they occur in even positions
    (k - 1 items)(rest)(k - 1 items)
    1 0 1 0 0 1 0 1 id % 2
    3 0 1 8 2 4 7 6 arr
    1 0 1 0 1 0 1 0 1 id % 2
    3 0 1 8 8 2 4 7 6 arr
if it ain't k, i.e., it's n / 2:
    iterate from 0 to n / 2:
    xorr them as we were doing for first half
    if there's an extra number betwn the two sections 
    we will see if our k is odd then only we will xor it
    then we will do the rest of things as k
*/
/*
Symbolic formulation (à la Rosen):
mid = ⌊n / 2⌋
len = k          if k ≤ mid
len = mid        if k > mid
take(i) := position i contributes to the xor

(len = k) ⇒ [
    ( ∀i (0 ≤ i < k ∧ i ≡ 1 (mod 2) ⇒ take(i) ) ) ∧
    ( k ≡ 1 (mod 2) ⇒ take(mid_index) ) ∧
    ( ∀j (n − k + 1 ≤ j < n ∧ j ≡ 0 (mod 2) ⇒ take(j) ) )
]
∧
(len = mid) ⇒ [
    ( ∀i (0 ≤ i < mid ∧ i ≡ 1 (mod 2) ⇒ take(i) ) ) ∧
    ( (n ≡ 1 (mod 2) ∧ k ≡ 1 (mod 2)) ⇒ take(mid_index) ) ∧
    ( ∀j (n − mid ≤ j < n ∧ j ≡ 0 (mod 2) ⇒ take(j) ) )
]

res = ⊕ { value(p) | take(p) }
*/