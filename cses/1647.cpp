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
	int n, q;
	cin >> n >> q;
	vll arr(n);
	for (ll& it : arr)
		cin >> it;
	vll tree = arr;
	const auto lsb_id = [] (ll k) -> ll {
		return k & (-k);
	};
	const auto query = [&] (ll k) -> ll {
		ll sum = 0ll;
		while (k > 0ll) {
			sum += tree[k - 1];
			k -= lsb_id(k);
		}
		return sum;
	};
	for (ll i = 1ll; i <= n; i++) {
		ll j = i + lsb_id(i);
		if (j <= n)
			tree[j - 1] += tree[i - 1];
	}
	while (q--) {
		ll a, b;
		cin >> a >> b;
		cout << (query(b) - query(a - 1)) << "\n";
	}
}

int main() {
    fast_io();
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif

    int T = 1;
    // if(!(cin >> T)) return 0;
    while(T--) solver();

    return 0;
}
