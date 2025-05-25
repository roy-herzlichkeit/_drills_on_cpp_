#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

inline static void solver(void);

int main(void) {
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
    int n; 
    string s; 
    cin >> n >> s;
    vector<int> cnt(26, 0), p(26, 0);
    for(auto x: s) 
    cnt[x - 'a']++;
    int ans = 0;
    for(auto x: s) {
        --cnt[x - 'a'];
        ++p[x - 'a'];
        int cur = 0;
        for(int i = 0; i < 26; ++i) {
            cur += min(1, cnt[i]) + min(1, p[i]);
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}