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

vi primes;

void generate_prime() {
    vector<bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) 
        if (is_prime[i]) 
            for (int j = i * i; j <= 1000000; j += i) 
                is_prime[j] = false;
    for (int i = 2; i <= 1000000; i++) 
        if (is_prime[i]) 
            primes.push_back(i);
}

void solver() {
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        for (const int& prime : primes) {
            if (prime * prime > tmp)
                break;
            while (tmp % prime == 0) {
                map[prime]++;
                tmp /= prime;
            }
        }
        if (tmp > 1) {
            map[tmp]++;
        }
    }
    for  (const auto& [prime, count] : map) {
        if (count % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    fast_io();
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif
    generate_prime();
    int T = 1;
    if(!(cin >> T)) return 0;
    while(T--) solver();

    return 0;
}