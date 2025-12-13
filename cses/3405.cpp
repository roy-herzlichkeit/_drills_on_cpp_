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

template<typename t>
class Queue {
private:
    stack<pair<t, t>> s1, s2;
public:
    void insert(t x) {
        t curr_or;
        if (s1.empty())
            curr_or = x;
        else
            curr_or = x | s1.top().second;
        s1.emplace(x, curr_or);
    }

    t remove() {
        if (s2.empty()) {
            while (!s1.empty()) {
                t curr_or = s2.empty() ? s1.top().first : (s1.top().first | s2.top().second);
                s2.emplace(s1.top().first, curr_or);
                s1.pop();
            }
        }
        t k = s1.empty() ? s2.top().second : (s2.top().second | s1.top().second);
        s2.pop();
        return k;
    }
};

void solver() {
    ll n, k, x, a, b, c, res = 0ll;
    cin >> n >> k >> x >> a >> b >> c;
    Queue<ll> q;
    int i;
    for (i = 0; i < k; i++) {
        q.insert(x);
        x = (x * a + b) % c;
    }
    for (; i <= n; i++) {
        res ^= q.remove();
        q.insert(x);
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