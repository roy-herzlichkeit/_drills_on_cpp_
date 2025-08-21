#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
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
    int n;
    cin >> n;
    vector<int> shoes(n);
    unordered_map<int, vector<int>> groups;
    for (int i = 0; i < n; ++i) {
        cin >> shoes[i];
        groups[shoes[i]].push_back(i + 1); 
    }
    for (auto &p : groups) {
        if (p.second.size() == 1) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> res(n);
    for (auto &p : groups) {
        auto &v = p.second;
        int k = (int)v.size();
        for (int j = 0; j < k; ++j) {
            int from_idx = v[j] - 1;  
            int to_pos   = v[(j + 1) % k];  
            res[from_idx] = to_pos;
        }
    }
    for (int x : res) 
        cout << x << " ";
    cout << '\n';
}