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

struct node {
    int val;
    unordered_map<int, node*> children;
    node(int x) : val(x) {}; 
};

class Trie {
private:
    node *root;
public:
    Trie();
    void add_permutation(vi& p);
    int traverse(const vi& p);
    ~Trie();
};

Trie::Trie() {
    root = new node(0);
}

void Trie::add_permutation(vi& p) {
    node *curr = root;
    for (const int& it : p) {
        if (curr->children.find(it) == curr->children.end()) {
            curr->children[it] = new node(it);
        }
        curr = curr->children[it];
    }
}

int Trie::traverse(const vi& p) {
    node *curr = root;
    int depth = 0;
    for (const int& it : p) {
        if (curr->children.find(it) != curr->children.end()) {
            depth++;
            curr = curr->children[it];
        } else {
            break;
        }
    }
    return depth;
}

Trie::~Trie() {
    function<void(node*)> deleteTrie = [&](node* curr) {
        if (!curr) return;
        for(auto& [key, child] : curr->children) {
            deleteTrie(child);
        }
        delete curr;
    };
    deleteTrie(root);
}

void get_inverse(const vi& p, vi& p_1) {
    for (int i = 0, n = p.size(); i < n; i++) 
        p_1[p[i] - 1] = (i + 1);
}

void solver() {
    Trie root = Trie();
    int n, m;
    cin >> n >> m;
    vector<vi> permutations(n, vi(m));
    for (vi& permutation : permutations) 
        for (int& term : permutation) 
            cin >> term;
    vi inverse_permutation(m);
    for (const vi& permutation : permutations) {
        get_inverse(permutation, inverse_permutation);
        root.add_permutation(inverse_permutation);
    }
    vi res;
    for (const vi& permutation : permutations) 
        res.push_back(root.traverse(permutation));
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