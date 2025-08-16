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
    solver();
    return 0;
}

inline static void solver(void) {
    int N, D;
    cin >> N >> D; 
    priority_queue<int> pq;
    for (int i = 0, p; i < N; i++) { 
        cin >> p;
        pq.push(p);
    }   
    int K = N, c = 0;
    while (K > 0 && !pq.empty()) {
        int t = pq.top();
        int q = int(D / t) + 1;
        K -= q;
        if (K >= 0)
            c++;
        pq.pop();
    }
    cout << c << endl;
}