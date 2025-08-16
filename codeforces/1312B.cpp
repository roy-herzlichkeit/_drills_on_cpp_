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
    vector<int> arr(n);
    for (int& it : arr)
        cin >> it;
    sort(arr.begin(), arr.end(), [] (const auto& a, const auto& b) {
        return a > b;
    });
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}