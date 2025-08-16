#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

inline static void solver(void);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solver();
    exit(EXIT_SUCCESS);
}

inline static void solver(void) {
    int n, count_1 = 0, count_0 = 0;
    cin >> n;
    vector<int> arr(n);
    for (auto& it : arr) {
        cin >> it;
        if (it == 0)
            count_0++;
        if (it == 1)
            count_1++;
    }
    ll res = 0;
    if (count_0 == 0)
        res = 1LL * count_1;
    else 
        res = 1LL * count_1 * (1LL << count_0);
    cout << res << endl;
}