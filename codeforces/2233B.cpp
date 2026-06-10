#include <bits/stdc++.h>
#define MOD 1000000007
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
    int n;
    cin >> n;

    vi arr(4 * n, 0);
    vi cnt(n + 1, 0);
    vector<vi> pos(n + 1);

    auto valid = [&](int idx, int x) -> bool {
        auto& p = pos[x];
        int g1, g2, g3;
        switch (p.size()) {
            case 0:
                return true;
            case 1:
                return idx - p[0] > 0;
            case 2:
                g1 = p[1] - p[0];
                g2 = idx - p[1];
                return g1 != g2;
            case 3: 
                g1 = p[1] - p[0];
                g2 = p[2] - p[1];
                g3 = idx - p[2];
                return g1 != g2 && g2 != g3 && g1 != g3;
            default:
                return false;
        }
    };

    function<bool(int)> solve = [&](int idx) -> bool {
        if (idx == 4 * n) 
            return true;
        for (int x = 1; x <= n; x++) {
            if (cnt[x] < 4 && valid(idx, x)) {
                arr[idx] = x;
                cnt[x]++;
                pos[x].push_back(idx);
                if (solve(idx + 1)) 
                    return true;
                arr[idx] = 0;
                cnt[x]--;
                pos[x].pop_back();
            }
        }
        return false;
    };

    solve(0);

    for (int i = 0; i < 4 * n; i++) 
        cout << arr[i] << " ";
    cout << endl;
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