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

int binSearch(long long val, int ind, int x) {
	int low = 1, high = 1e9 + 5;
	int ans = 0; 
	while (low <= high) {
		int mid = (low + high) / 2; 
		if (val + (1LL * (ind + 1) * (mid - 1)) <= x) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	} 
	return ans;
} 

void solver() {int n, x;
	cin >> n >> x;
	vector<int> cost(n);
	for (int i = 0; i < n; i++) 
		cin >> cost[i];
	sort(cost.begin(), cost.end());
	vector<long long> presum(n);
	presum[0] = cost[0];
	for (int i = 1; i < n; i++)
		presum[i] = presum[i - 1] + cost[i];
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += binSearch(presum[i], i, x); 
	cout << ans << "\n";
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