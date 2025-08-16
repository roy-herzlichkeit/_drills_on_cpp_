#include <bits/stdc++.h>
using namespace std;

void solver(void);

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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> hash(n);
    for (int i = 0, val; i < n; i++) {
        cin >> val;
        val = val % k;
        hash[i].first = val ? val : k;
        hash[i].second = i + 1;
    }
    sort(hash.begin(), hash.end(), [] (const auto& a, const auto& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });
    for (int i = 0; i < n; i++)
        cout << hash[i].second << " ";
    cout << "\n";
}