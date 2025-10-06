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
    int n;
    cin >> n;
    vector<pair<ll, int>> arr(n);
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        arr[i] = {tmp, i};
    }
    sort(arr.begin(), arr.end());
    
    vector<ull> prefix(n);
    prefix[0] = arr[0].first;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i].first;
    }

    vector<int> reach(n);
    reach[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (prefix[i] >= arr[i + 1].first) {
            reach[i] = reach[i + 1];
        } else {
            reach[i] = i;
        }
    }
    
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int id = arr[i].second;
        res[id] = reach[i];
    }
    
    for (const int& it : res)
        cout << it << " ";
    cout << "\n";
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