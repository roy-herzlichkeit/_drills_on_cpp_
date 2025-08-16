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
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    ll minX = *min_element(all(x)), maxX = *max_element(all(x)), minY = *min_element(all(y)), maxY = *max_element(all(y));
    vector<ll> preMinX(n), preMaxX(n), preMinY(n), preMaxY(n), sufMinX(n), sufMaxX(n), sufMinY(n), sufMaxY(n);
    preMinX[0] = preMaxX[0] = x[0];
    preMinY[0] = preMaxY[0] = y[0];
    sufMinX[n - 1] = sufMaxX[n - 1] = x[n - 1];
    sufMinY[n - 1] = sufMaxY[n - 1] = y[n - 1];
    for(int i = 1; i < n; ++i) {
        preMinX[i] = min(preMinX[i - 1], x[i]);
        preMaxX[i] = max(preMaxX[i - 1], x[i]);
        preMinY[i] = min(preMinY[i - 1], y[i]);
        preMaxY[i] = max(preMaxY[i - 1], y[i]);
    }
    for(int i = n - 2; i >= 0; --i) {
        sufMinX[i] = min(sufMinX[i + 1], x[i]);
        sufMaxX[i] = max(sufMaxX[i + 1], x[i]);
        sufMinY[i] = min(sufMinY[i + 1], y[i]);
        sufMaxY[i] = max(sufMaxY[i + 1], y[i]);
    }
    ll total = (maxX - minX + 1) * (maxY - minY + 1), minCost = (total > n ? total : LLONG_MAX);
    for(int i = 0; i < n; ++i) {
        ll curMinX = (i == 0 ? sufMinX[i + 1] : (i == n - 1 ? preMinX[i - 1] : min(preMinX[i - 1], sufMinX[i + 1])));
        ll curMaxX = (i == 0 ? sufMaxX[i + 1] : (i == n - 1 ? preMaxX[i - 1] : max(preMaxX[i - 1], sufMaxX[i + 1])));
        ll curMinY = (i == 0 ? sufMinY[i + 1] : (i == n - 1 ? preMinY[i - 1] : min(preMinY[i - 1], sufMinY[i + 1])));
        ll curMaxY = (i == 0 ? sufMaxY[i + 1] : (i == n - 1 ? preMaxY[i - 1] : max(preMaxY[i - 1], sufMaxY[i + 1])));
        ll width = (curMaxX - curMinX + 1), height = (curMaxY - curMinY + 1), area = width * height;
        if (area > (n - 1)) {
            minCost = min(minCost, area);
        } else {
            ll costExpandX = (width + 1) * height, costExpandY = width * (height + 1);
            minCost = min({minCost, costExpandX, costExpandY});
        }
    }
    cout << minCost << "\n";
}