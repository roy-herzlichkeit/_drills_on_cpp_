#include <bits/stdc++.h>
#define ll unsigned long long
#define INF INT_MAX
using namespace std;

void solver(void);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

void solver(void) {
    int n;
    cin >> n;
    int minn = INF;
    vector<int> min2;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> v(m);
        for (auto &el : v) 
            cin >> el;
        int minel = *min_element(v.begin(), v.end());
        minn = min(minn, minel);
        v.erase(find(v.begin(), v.end(), minel));
        min2.push_back(*min_element(v.begin(), v.end()));
    }
    ll ans = accumulate(min2.begin(), min2.end(), 0ULL);
    ans = minn + ans - *min_element(min2.begin(), min2.end());
    cout << ans << "\n";
}