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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n), parent(n);
    function<void(int, int)> dfs = [&](int curr, int prev) {
        parent[curr] = prev;
        for (int& children : adj[curr]) {
            if (children != prev) {
                dist[children] = dist[curr] + 1;
                dfs(children, curr);
            }
        }   
    };
    dist[0] = 0;
    dfs(0, -1);
    int root = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[root] = 0;
    dfs(root, -1);
    root = max_element(dist.begin(), dist.end()) - dist.begin();
    if (dist[root] == n - 1) {
        cout << -1 << endl;
    } else {
        vector<bool> diameter(n, false);
        int curr = root;
        while (curr != -1) {
            diameter[curr] = true;
            curr = parent[curr];
        }
        int a, b, c;
        a = b = c = -1;
        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                if (diameter[u] && !diameter[v]) {
                    a = parent[u], b = u, c = v;
                    break;
                }
            }
            if (a != -1) {
                break;
            }
        }
        cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
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