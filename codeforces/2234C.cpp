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

void compute(const vector<ll>& h, vector<ll>& A) {
    int n = h.size();
    vector<ll> d(2 * n);
    for(int i = 0; i < 2 * n; i++) 
        d[i] = h[i % n];
    
    vector<int> PGE(2 * n, -1), NGE(2 * n, 2 * n);

    stack<int> st;
    for(int r = 0; r < 2 * n; r++){
        while(!st.empty() && d[st.top()] <= d[r]){
            NGE[st.top()] = r;
            st.pop();
        }
        PGE[r] = st.empty() ? -1 : st.top();
        st.push(r);
    }
    
    vector<ll> cdiff(n + 2, 0), ldiff(n + 2, 0);
    
    for(int r = 0; r <  2 * n; r++){
        int span = NGE[r] - r;
        int L1 = max({PGE[r] + 1, r - n + 2, 0});
        int L2 = min(r, n - 1);
        if(L1 > L2) 
            continue;
        
        int T = NGE[r] - n + 1;

        int a = max(L1, T), b = L2;
        if(a <= b){
            ll C = d[r] * (ll)span;
            cdiff[a] += C; 
            cdiff[b + 1] -= C;
        }

        a = L1, b = min(L2, T-1);
        if(a <= b){
            ll slope = d[r], intercept = d[r] * (ll)(n - 1 - r);
            ldiff[a] += slope; 
            ldiff[b + 1] -= slope;
            cdiff[a] += intercept; 
            cdiff[b + 1] -= intercept;
        }
    }
    
    A.resize(n);
    ll rc = 0, rl = 0;
    for(int l = 0; l < n; l++){
        rc += cdiff[l]; rl += ldiff[l];
        A[l] = rc + rl * ll(l);
    }
}

void solver() {
    int n; 
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) 
        cin >> h[i];
    ll maxDeH = *max_element(h.begin(), h.end());
    
    vector<ll> A, arev;
    compute(h, A);
    
    vector<ll> hrev(n);
    for(int i = 0; i < n; i++) 
        hrev[i] = h[n - 1 - i];
    compute(hrev, arev);
    
    for(int l = 0; l < n; l++){
        ll B = arev[(n - l) % n];
        cout << A[l] + B - (ll)(n - 1) * maxDeH << " ";
    }
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
// I am so depressed man, the city I am in rn is so larp