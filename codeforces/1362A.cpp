#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
const int INF = 1e9 + 7;

inline static void solver(void);

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("a.in", "r", stdin);
    #endif
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    uint64_t a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    auto trimmer = [] (string s) -> string {
        auto first = s.find_first_not_of('0');
        if (first == string::npos) 
            return "0";
        auto last = s.find_last_not_of('0');
        return s.substr(first, last - first + 1);
    };
    string b1 = trimmer(bitset<64>(a).to_string()), b2 = trimmer(bitset<64>(b).to_string());
    int res = -1;
    if (b1 == b2) {
        uint64_t t = b / a;
        uint64_t d = log2l(t);
        res = d / 3;
        d = d % 3;
        res += d / 2;
        d = d % 2;
        res += d;
    }
    cout << res << endl;
}