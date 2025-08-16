#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
 
typedef long long ll;
 
const int INF = 1e9 + 7;

inline static void solver(void);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int maxV = 2 * n;
    vector<int> runsA(maxV+1), runsB(maxV+1);
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) cnt++;
        else {
            runsA[a[i-1]] = max(runsA[a[i-1]], cnt);
            cnt = 1;
        }
    }
    runsA[a[n-1]] = max(runsA[a[n-1]], cnt);
    cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (b[i] == b[i-1]) cnt++;
        else {
            runsB[b[i-1]] = max(runsB[b[i-1]], cnt);
            cnt = 1;
        }
    }
    runsB[b[n-1]] = max(runsB[b[n-1]], cnt);
    int res = 0;
    for (int v = 1; v <= maxV; ++v)
        res = max(res, runsA[v] + runsB[v]);
    cout << res << endl;
}